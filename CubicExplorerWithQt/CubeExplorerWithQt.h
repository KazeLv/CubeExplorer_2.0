#pragma once

#include <QtWidgets/QMainWindow>
#include <iostream>
#include "CubeRecognizer.h"	
#include "CubeExplorer.h"
#include <qapplication.h>
#include <qdatetime.h>
#include <qserialport.h>
#include <qserialportinfo.h>
#include <QStringListModel>
#include <qfiledialog.h>
#include <qcamera.h>
#include <qcamerainfo.h>
#include <qcameraimagecapture.h>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <qgraphicsvideoitem.h>
#include <QMyGraphicsView.h>
#include "ui_CubicExplorerWithQt.h"
#include "DebugWidget.h"
#include "RecogAreaDialog.h"
#include "HSVDataDialog.h"
#include "HSVThresholdDialog.h"

extern "C" {
#include "solve.h"
}

#define SCENE_VIEW_WIDTH 320
#define SCENE_VIEW_HEIGHT 240

class CubeExplorerWithQt : public QMainWindow
{
	Q_OBJECT

public:
	CubeExplorerWithQt(QWidget *parent = Q_NULLPTR);
	virtual ~CubeExplorerWithQt();
	//void openCamera();
	void iniCamera();
	void capture(std::string);
	void SendOperationSerial();
	void Sleep(int);

private:
	Ui::CubicExplorerWithQt ui;

	CubeExplorer cubeExplorer;							//ħ������

	QSerialPort *serialPort;							//���ڿ���
	QSerialPortInfo currentPortInfo;
	QMap<QString,QSerialPortInfo> list_portInfo;

	//����ͷ����
	QGraphicsScene *scene_FR;							//����ͷ��ʾ����
	QGraphicsScene *scene_UB;							//
	QGraphicsScene *scene_LD;							//
	QGraphicsVideoItem *videoItem_FR;					//����ͷ��ʾ����
	QGraphicsVideoItem *videoItem_UB;					//
	QGraphicsVideoItem *videoItem_LD;					//
	QRect rec_tSelect;									//ѡȡ��λ����ʱ��¼
	QString curPath;									//��ǰ����Ŀ¼
	QList<QCameraInfo> list_cameraInfo;					//����ͷ��Ϣ
	QList<QCamera*> list_pCamera;						//����ͷ�б������ͷ��������б������±��Ӧ
	QList<QCameraImageCapture*> list_pCapture;			//
	QMap<QString, int> map_pic_cameraIndex;				//ͼƬ��������ͷ����ָ���ӳ��
	QMap<QString, QGraphicsVideoItem*> map_pic_pItem;	//ͼƬ����videoItemָ���ӳ��
	QMap<QString, QGraphicsScene*> map_pic_pScene;		//ͼƬ����sceneָ���ӳ��
	int nImgSaved;

	QList<QGraphicsRectItem*> list_samRecItems;			//�洢��ʾ�ڴ����ϵĲ�����ָ��

signals:
	void signal_captureFinished();

public slots:
	//���水ť�ۺ���
	void on_btnTightOrLooseClicked();
	void on_btnRestoreClicked();
	void on_btnResetClicked();
	void on_btnDebugClicked();
	void on_btnCameraClicked();
	void on_btnShowSamRecsClicked();
	void on_btnSetHSVClicked();
	//����ͷView�����Ӧ�ۺ���
	void slot_mouseReleasedInCameraViews(QRect rec_select);
	void slot_menuSetRecTriggered();
	void slot_menuShowHSVTriggered();
	//ȡɫ��������Ӧ�ۺ���
	void slot_setRecArea(QString groupName,QRect rect,int faceID,int blockID);
	//Capture��Ӧ�ۺ���
	void slot_imageSaved(int id, QString fileName);
	//����ģ����Ӧ�ۺ���
	void on_btnPortRefreshClicked();
	void on_btnPortOpenClicked();
	void on_btnPortSendClicked();
	void slot_portInfoChanged(const QString &text);
	//����ͷ����ۺ���
	void slot_cameraInfoChanged(const QString &text);

	void slot_continueRestore();
};
