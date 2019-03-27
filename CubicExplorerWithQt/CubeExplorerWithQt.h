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

	CubeExplorer cubeExplorer;							//魔方解算

	QSerialPort *serialPort;							//串口控制
	QSerialPortInfo currentPortInfo;
	QMap<QString,QSerialPortInfo> list_portInfo;

	//摄像头处理
	QGraphicsScene *scene_FR;							//摄像头显示场景
	QGraphicsScene *scene_UB;							//
	QGraphicsScene *scene_LD;							//
	QGraphicsVideoItem *videoItem_FR;					//摄像头显示载体
	QGraphicsVideoItem *videoItem_UB;					//
	QGraphicsVideoItem *videoItem_LD;					//
	QRect rec_tSelect;									//选取框位置临时记录
	QString curPath;									//当前工作目录
	QList<QCameraInfo> list_cameraInfo;					//摄像头信息
	QList<QCamera*> list_pCamera;						//摄像头列表和摄像头捕获对象列表，两者下标对应
	QList<QCameraImageCapture*> list_pCapture;			//
	QMap<QString, int> map_pic_cameraIndex;				//图片名到摄像头对象指针的映射
	QMap<QString, QGraphicsVideoItem*> map_pic_pItem;	//图片名到videoItem指针的映射
	QMap<QString, QGraphicsScene*> map_pic_pScene;		//图片名到scene指针的映射
	int nImgSaved;

	QList<QGraphicsRectItem*> list_samRecItems;			//存储显示在窗口上的采样框指针

signals:
	void signal_captureFinished();

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
	//摄像头分配槽函数
	void slot_cameraInfoChanged(const QString &text);

	void slot_continueRestore();
};
