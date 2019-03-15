#pragma once
	
#include <vector>
#include <QDialog>
#include <qlabel.h>
#include <qpixmap.h>
#include <qgroupbox.h>
#include <qradiobutton.h>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <qsurface.h>
#include "CubeRecognizer.h"
#include "ui_HSVDataDialog.h"

using namespace QtDataVisualization;

#define SAMPLED_PIC_SHOW_WIDTH 150			//����ͼƬ��ʾ�ڴ����ϵĿ�ȣ��߶ȵȱ����仯��

class HSVDataDialog : public QDialog
{
	Q_OBJECT

public:
	HSVDataDialog(cv::Mat imageBGR,QWidget *parent = Q_NULLPTR);
	~HSVDataDialog();

	void calculation(string target);		//����m_matHSV�õ�HSV���ݲ����㼫�󡢼�С����ֵ
	void iniGraph();						//��ʼ��ͼ��UI
	void iniStatistic();					//��ʼ����������ͳ��UI
	
private:
	cv::Mat m_matHSV;
	cv::Mat m_matRGB;

	//���ݿ��ӻ�
	Q3DSurface *surface_graph;
	QWidget *containner;
	QSurfaceDataProxy *proxy; 
	QSurface3DSeries *series;
	QSurfaceDataArray *dataArray_H;
	QSurfaceDataArray *dataArray_S;
	QSurfaceDataArray *dataArray_V;

	//��������չʾ������ѡ��
	QVBoxLayout *vLay_imgAndChannel;

	QGroupBox *groupBox_sample;				//����������ʾ
	QVBoxLayout *vLay_samData;				//
	QLabel *label_showSamPic;				//
	QImage *m_imgRGB;						//
	QLabel *label_max;						//
	QLabel *label_min;						//
	QLabel *label_mean;						//
	int nMax_H;								//���󡢼�С����ֵ
	int nMin_H;								//
	int nMean_H;							//
	int nMax_S;								//
	int nMin_S;								//
	int nMean_S;							//
	int nMax_V;								//
	int nMin_V;								//
	int nMean_V;							//

	QGroupBox *groupBox_sourceSelect;		//����ѡ��
	QVBoxLayout *vLay_radioBtn;				//
	QRadioButton *radioBtn_H;				//
	QRadioButton *radioBtn_S;				//
	QRadioButton *radioBtn_V;				//

	Ui::HSVDataDialog ui;

public slots:
	void on_radioBtnHToggled(bool checked);
	void on_radioBtnSToggled(bool checked);
	void on_radioBtnVToggled(bool checked);
};
