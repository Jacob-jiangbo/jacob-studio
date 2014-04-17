#ifndef FINDDIALOG_H	//避免头文件被多次包含
#define FINDDIALOG_H
#include <QDialog>
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
// 类从QDialog 继承，QDialog 从QWidget 继承
class FindDialog : public QDialog
{
	// Q_OBJECT 是一个宏定义，如果类里面用到了signal 或者slots，就要声明这个宏
	Q_OBJECT
public:
	// 父参数为NULL，说明没有父控件
	FindDialog(QWidget *parent = 0);
signals:
	// Qt::CaseSensitivity 是一个枚举类型，
	// 有Qt::CaseSensitive和Qt::CaseInsensitive 两个值
	void findNext(const QString &str, Qt::CaseSensitivity cs);
	void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:
	void findClicked();
	void enableFindButton(const QString &text);
private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findButton;
	QPushButton *closeButton;
};
#endif
