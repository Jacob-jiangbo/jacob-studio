#include <QtGui>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
	: QDialog(parent)
{
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);	// 快捷键触发时lineEdit获得焦点
	caseCheckBox = new QCheckBox(tr("Match &case"));
	backwardCheckBox = new QCheckBox(tr("Search &backward"));
	findButton = new QPushButton(tr("&Find"));
	findButton->setEnabled(false);
	closeButton = new QPushButton(tr("Close"));

	//改变lineEdit 中的文本，enableFindButton()slot 函数就会调用。
	//如果输入了文本，那么让findButton 有效，否则就无效。
	connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));
	connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);
	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);
	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();
	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Find"));
}

void FindDialog::findClicked()
{
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs =
		caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
	if (backwardCheckBox->isChecked()) {
		emit findPrevious(text, cs);
	} else {
		emit findNext(text, cs);
	}
}

void FindDialog::enableFindButton(const QString &text)
{
	findButton->setEnabled(!text.isEmpty());
}
