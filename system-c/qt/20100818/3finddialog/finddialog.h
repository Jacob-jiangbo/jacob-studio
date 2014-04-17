#ifndef FINDDIALOG_H	//����ͷ�ļ�����ΰ���
#define FINDDIALOG_H
#include <QDialog>
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
// ���QDialog �̳У�QDialog ��QWidget �̳�
class FindDialog : public QDialog
{
	// Q_OBJECT ��һ���궨�壬����������õ���signal ����slots����Ҫ���������
	Q_OBJECT
public:
	// ������ΪNULL��˵��û�и��ؼ�
	FindDialog(QWidget *parent = 0);
signals:
	// Qt::CaseSensitivity ��һ��ö�����ͣ�
	// ��Qt::CaseSensitive��Qt::CaseInsensitive ����ֵ
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
