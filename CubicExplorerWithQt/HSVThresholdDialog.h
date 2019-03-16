#pragma once

#include <QDialog>
#include <qmap.h>
#include "ui_HSVThresholdDialog.h"
#include "cubeRecognizer.h"

class HSVThresholdDialog : public QDialog
{
	Q_OBJECT

public:
	HSVThresholdDialog(QWidget *parent = Q_NULLPTR);
	~HSVThresholdDialog();

	void showHSVData(QString face);

private:
	Ui::HSVThresholdDialog ui;
	
	QMap<QString, QMap<QString, HSV>> map_hsv_t;	//��ʱhsv����,��ű����ĵ�����δӦ�õ�hsv��ֵ,map.[��].[��ɫ]���з���

	QChar curFace = 'f';							//��ǰ��ʾ��

public slots:
	void on_btnResetClicked();						//�Ի���ť�ۺ���
	void on_btnApplyClicked();						//
	void on_btnCancelClicked();						//

	void on_faceRadioToggled(bool checked);			//ҳ��ѡ��ť�ۺ���
	void slot_spinValueChanged(int value);			//���ݿ�ۺ���
};

