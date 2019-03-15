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

class CubeExplorerWithQt : public QMainWindow
{
	Q_OBJECT

public:
	CubeExplorerWithQt(QWidget *parent = Q_NULLPTR);
	virtual ~CubeExplorerWithQt();
	//void openCamera();
	void iniCamera();
	void Capture(std::string);
	void SendOperationSerial();
	void Sleep(int);

private:
	Ui::CubicExplorerWithQt ui;

	CubeExplorer cubeExplorer;		//魔方解算

	QSerialPort *serialPort;			//串口控制
	QSerialPortInfo currentPortInfo;
	QMap<QString,QSerialPortInfo> list_portInfo;

	//摄像头处理
	QList<QCameraInfo> list_cameraInfo;	//摄像头信息
	QCamera *camera_FR = nullptr;		//摄像头对象
	QCamera *camera_UB = nullptr;		//
	QCamera *camera_LD = nullptr;		//
	QCameraImageCapture *capture_FR;	//摄像头抓取
	QCameraImageCapture *capture_UB;	//
	QCameraImageCapture *capture_LD;	//
	QGraphicsScene *scene_FR;			//摄像头显示场景
	QGraphicsScene *scene_UB;			//
	QGraphicsScene *scene_LD;			//
	QGraphicsVideoItem *videoItem_FR;	//摄像头显示载体
	QGraphicsVideoItem *videoItem_UB;	//
	QGraphicsVideoItem *videoItem_LD;	//
	QRect rec_tSelect;					//选取框位置临时记录
	QString path_picCaptured;			//保存截取图片的地址

public slots:
	//界面按钮槽函数
	void on_btnTightOrLooseClicked();
	void on_btnRestoreClicked();
	void on_btnResetClicked();
	void on_btnDebugClicked();
	void on_btnCameraClicked();
	void on_btnShowSamRecsClicked();
	void on_btnSetHSVClicked();
	//摄像头View鼠标响应槽函数
	void slot_mouseReleasedInCameraViews(QRect rec_select);
	void slot_menuSetRecTriggered();
	void slot_menuShowHSVTriggered();
	//取色块设置响应槽函数
	void slot_setRecArea(QString groupName,QRect rect,int faceID,int blockID);
	//Capture响应槽函数
	void slot_imageSaved(int id, QString fileName);
	//串口模块响应槽函数
	void on_btnPortRefreshClicked();
	void on_btnPortOpenClicked();
	void on_btnPortSendClicked();
	void slot_portInfoChanged(const QString &text);
};
