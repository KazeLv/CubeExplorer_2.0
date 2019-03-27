#pragma once

#include "CubeRecognizer.h"
#include "HSVDataDialog.h"
#include <QDialog>
#include <qpixmap.h>
#include "ui_LastSampleDialog.h"

class LastSampleDialog : public QDialog
{
	Q_OBJECT

public:
	LastSampleDialog(QWidget *parent = Q_NULLPTR);
	~LastSampleDialog();

	void setIconBySample();					//���ò�����ťͼ��Ϊ��ǰ��ĸ�������ͼ

private:
	Ui::LastSampleDialog ui;

	QString curFace;
	QList<QPushButton*> list_btnBlock;		//������ŵõ���Ӧ�Ÿ�����ͼ�İ�ť

public slots:
	void on_btnSampleBlockClicked();
	void on_radioFaceToggled(bool checked);
};
