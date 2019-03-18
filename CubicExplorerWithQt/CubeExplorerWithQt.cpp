#include "CubeExplorerWithQt.h"

extern QList<QString> list_picID;

CubeExplorerWithQt::CubeExplorerWithQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	curPath = QDir::currentPath();		//获取当前工作路径

	//界面按钮信号槽绑定
	connect(ui.btn_tightOrLoose, SIGNAL(clicked()), this, SLOT(on_btnTightOrLooseClicked()));
	connect(ui.btn_restore, SIGNAL(clicked()), this, SLOT(on_btnRestoreClicked()));
	connect(ui.btn_reset, SIGNAL(clicked()), this, SLOT(on_btnResetClicked()));
	connect(ui.btn_debug, SIGNAL(clicked()), this, SLOT(on_btnDebugClicked()));
	connect(ui.btn_camSwitch, SIGNAL(clicked()), this, SLOT(on_btnCameraClicked()));
	connect(ui.btn_showSamRecs, SIGNAL(clicked()), this, SLOT(on_btnShowSamRecsClicked()));
	connect(ui.btn_setHSV, SIGNAL(clicked()), this, SLOT(on_btnSetHSVClicked()));
	
	connect(ui.btn_portOpen_close, SIGNAL(clicked()), this, SLOT(on_btnPortOpenClicked()));
	connect(ui.btn_portRefresh, SIGNAL(clicked()), this, SLOT(on_btnPortRefreshClicked()));
	connect(ui.btn_portSend, SIGNAL(clicked()), this, SLOT(on_btnPortSendClicked()));
	connect(ui.comboBox_coms, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_portInfoChanged(QString)));
		
	//初始化摄像头
	iniCamera();

	//构造CubicExplorer对象
	cubeExplorer = CubeExplorer();

	//初始化串口类对象
	serialPort = new QSerialPort();

	serialPort->setBaudRate(QSerialPort::Baud9600);
	serialPort->setDataBits(QSerialPort::Data8);
	serialPort->setParity(QSerialPort::NoParity);
	serialPort->setStopBits(QSerialPort::OneStop);
	serialPort->setFlowControl(QSerialPort::NoFlowControl);

	ui.comboBox_coms->clear();
	foreach(QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
		ui.comboBox_coms->addItem(info.portName());
	}
}

CubeExplorerWithQt::~CubeExplorerWithQt() {
	if (serialPort->isOpen()){
		serialPort->close();
		delete serialPort;
	}
}

void CubeExplorerWithQt::iniCamera()
{
	//摄像头显示区鼠标响应槽绑定
	connect(ui.graView_cameraFR, SIGNAL(mouseReleased(QRect)), this, SLOT(slot_mouseReleasedInCameraViews(QRect)));
	connect(ui.graView_cameraUB, SIGNAL(mouseReleased(QRect)), this, SLOT(slot_mouseReleasedInCameraViews(QRect)));
	connect(ui.graView_cameraLD, SIGNAL(mouseReleased(QRect)), this, SLOT(slot_mouseReleasedInCameraViews(QRect)));

	//菜单action绑定
	connect(ui.actSetBlock, SIGNAL(triggered()), this, SLOT(slot_menuSetRecTriggered()));
	connect(ui.actShowHSV, SIGNAL(triggered()), this, SLOT(slot_menuShowHSVTriggered()));

	//获取可用摄像头信息
	list_cameraInfo.clear();
	foreach(QCameraInfo info, QCameraInfo::availableCameras()) {
		list_cameraInfo.append(info);
	}

	camera_FR = new QCamera(list_cameraInfo.at(0));
	capture_FR = new QCameraImageCapture(camera_FR);

	//Capture响应槽绑定
	connect(capture_FR, SIGNAL(imageSaved(int, QString)), this, SLOT(slot_imageSaved(int, QString)));

	//初始化摄像头显示组件
	videoItem_FR = new QGraphicsVideoItem;
	videoItem_FR->setSize(QSize(320, 240));
	videoItem_FR->setPos(-160, -120);

	videoItem_UB = new QGraphicsVideoItem;
	videoItem_UB->setSize(QSize(320, 240));
	videoItem_UB->setPos(-160, -120);

	videoItem_LD = new QGraphicsVideoItem;
	videoItem_LD->setSize(QSize(320, 240));
	videoItem_LD->setPos(-160, -120);

	scene_FR = new QGraphicsScene(-160, -120, 320, 240);
	scene_UB = new QGraphicsScene(-160, -120, 320, 240);
	scene_LD = new QGraphicsScene(-160, -120, 320, 240);

	ui.graView_cameraFR->setScene(scene_FR);
	ui.graView_cameraFR->setCursor(Qt::CrossCursor);
	ui.graView_cameraFR->setDragMode(QGraphicsView::RubberBandDrag);

	ui.graView_cameraUB->setScene(scene_UB);
	ui.graView_cameraUB->setCursor(Qt::CrossCursor);
	ui.graView_cameraUB->setDragMode(QGraphicsView::RubberBandDrag);

	ui.graView_cameraLD->setScene(scene_LD);
	ui.graView_cameraLD->setCursor(Qt::CrossCursor);
	ui.graView_cameraLD->setDragMode(QGraphicsView::RubberBandDrag);

	scene_FR->addItem(videoItem_FR);				//在三个scene中分别添加视频显示组件
	scene_UB->addItem(videoItem_UB);				//
	scene_LD->addItem(videoItem_LD);				//

	camera_FR->setViewfinder(videoItem_FR);			//设置摄像头显示对象

	map_pic_pScene.insert("FR", scene_FR);			//在map中添加三个scene指针
	map_pic_pScene.insert("UB", scene_UB);			//
	map_pic_pScene.insert("LD", scene_LD);			//
}

void CubeExplorerWithQt::Capture(std::string Case) {
	if (Case == "Case1") {
		capture_FR->capture(curPath + "/pic_cam/cam_case1_FR");
		capture_UB->capture(curPath + "/pic_cam/cam_case1_UB");
		capture_LD->capture(curPath + "/pic_cam/cam_case1_LD");
	}
	else if (Case == "Case2") {
		capture_FR->capture(curPath + "/pic_cam/cam_case2_FR");
		capture_UB->capture(curPath + "/pic_cam/cam_case2_UB");
		capture_LD->capture(curPath + "/pic_cam/cam_case2_LD");
	}
}

void CubeExplorerWithQt::Sleep(int sec) {
	QDateTime last = QDateTime::currentDateTime();
	QDateTime now;
	while (1) {
		now = QDateTime::currentDateTime();
		if (last.msecsTo(now) >= sec) {
			break;
		}
	}
}

void CubeExplorerWithQt::SendOperationSerial() {
	for (auto iter = cubeExplorer.GetVecStrSerial().cbegin(); iter != cubeExplorer.GetVecStrSerial().cend(); iter++) {
		serialPort->write(QString(iter->c_str()).toLatin1());
	}
	serialPort->write(QString("#2P2T200\r\n").toLatin1());
	serialPort->write(QString("#4P2T200\r\n").toLatin1());
}

//右边栏操作按钮响应槽函数
void CubeExplorerWithQt::on_btnTightOrLooseClicked() {
	//操作两只机械手进行微松开和夹紧，用以装配和取下魔方
	if (cubeExplorer.handState.left.isTight) {
		serialPort->write(QString("#2P2T200\r\n").toLatin1());
		serialPort->write(QString("#4P2T200\r\n").toLatin1());
		cubeExplorer.handState = HandState(true, false, true, false);
	}
	else {
		serialPort->write(QString("#2P1T200\r\n").toLatin1());
		serialPort->write(QString("#4P1T200\r\n").toLatin1());
		cubeExplorer.handState = HandState(true, true, true, true);
	}
}

void CubeExplorerWithQt::on_btnResetClicked() {
	//操作两只手臂恢复到初始角度，以备下一次复原的进行
	if (!cubeExplorer.handState.left.isReady) {
		serialPort->write(QString("#1P6T200\r\n").toLatin1());
		cubeExplorer.handState.left.isReady = true;
	}
	if (!cubeExplorer.handState.right.isReady) {
		serialPort->write(QString("#3P6T200\r\n").toLatin1());
		cubeExplorer.handState.right.isReady = true;
	}
}

void CubeExplorerWithQt::on_btnRestoreClicked() {
	nImgSaved = 0;						//重置拍照计数
	cubeExplorer.Reset();
	serialPort->write(QString("#2P1T200\r\n").toLatin1());
	serialPort->write(QString("#4P1T200\r\n").toLatin1());
	//1.拍照case1，得到strCase1；拍照case2，得到strCase2
	//a.左手夹紧，右手松开
	serialPort->write(QString("#4P5T200\r\n").toLatin1());
	serialPort->flush();
	cubeExplorer.handState.right.isTight = false;

	//b.拍照case1
	Sleep(500);
	Capture("Case1");

	//c.右手夹紧，左手松开
	serialPort->clear();
	serialPort->write(QString("#4P1T200\r\n").toLatin1());
	serialPort->write(QString("#2P5T200\r\n").toLatin1());
	cubeExplorer.handState.left.isTight = false;
	cubeExplorer.handState.right.isTight = true;

	//d.拍照case2
	Sleep(500);
	Capture("Case2");

	while (nImgSaved < 2);				//等待三张图片保存完毕		

	//2.进行识别得到识别字符串
	std::string strRec/* = recognize()*/;

	//把识别结果显示在界面上
	QGraphicsScene* scene_rec_F = new QGraphicsScene;
	QGraphicsScene* scene_rec_R = new QGraphicsScene;
	QGraphicsScene* scene_rec_U = new QGraphicsScene;
	QGraphicsScene* scene_rec_B = new QGraphicsScene;
	QGraphicsScene* scene_rec_L = new QGraphicsScene;
	QGraphicsScene* scene_rec_D = new QGraphicsScene;
	QImage* image = new QImage();
	QImage imageTmp;

	image->load(QString("./pic_res/res_r.png"));
	imageTmp = image->scaled(ui.graphicsView_R->width() - 10, ui.graphicsView_R->height() - 10);
	scene_rec_R->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_R->setScene(scene_rec_R);
	ui.graphicsView_R->show();

	image->load(QString("./pic_res/res_f.png"));
	imageTmp = image->scaled(ui.graphicsView_F->width() - 10, ui.graphicsView_F->height() - 10);
	scene_rec_F->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_F->setScene(scene_rec_F);
	ui.graphicsView_F->show();

	image->load(QString("./pic_res/res_u.png"));
	imageTmp = image->scaled(ui.graphicsView_U->width() - 10, ui.graphicsView_U->height() - 10);
	scene_rec_U->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_U->setScene(scene_rec_U);
	ui.graphicsView_U->show();

	image->load(QString("./pic_res/res_b.png"));
	imageTmp = image->scaled(ui.graphicsView_B->width() - 10, ui.graphicsView_B->height() - 10);
	scene_rec_B->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_B->setScene(scene_rec_B);
	ui.graphicsView_B->show();

	image->load(QString("./pic_res/res_l.png"));
	imageTmp = image->scaled(ui.graphicsView_L->width() - 10, ui.graphicsView_L->height() - 10);
	scene_rec_L->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_L->setScene(scene_rec_L);
	ui.graphicsView_L->show();

	image->load(QString("./pic_res/res_d.png"));
	imageTmp = image->scaled(ui.graphicsView_D->width() - 10, ui.graphicsView_D->height() - 10);
	scene_rec_D->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_D->setScene(scene_rec_D);
	ui.graphicsView_D->show();

	//3.利用两个字符串得到最终识别序列并初始化CubicExplorer对象
	char* cp = new char[strRec.length() + 1];
	strcpy(cp, strRec.c_str());
	char* res = cube_solve(cp, NULL);
	if (!res) {
		//ui.label_UI_tip->setText(QStringLiteral("错误：错误的识别序列！！"));
		return;
	}
	cubeExplorer.SetTarget(res);

	//4.CubicExplorer对象调用解算方法，得到串口操作序列字符串
	cubeExplorer.GetShortestWay();

	//5.通过串口通信把串口序列传递给控制机，并使用listView控件实时显示操作序列传输情况
	SendOperationSerial();
}

void CubeExplorerWithQt::on_btnDebugClicked() {
	DebugWidget dw(serialPort, this);
	dw.show();
	dw.exec();
}

void CubeExplorerWithQt::on_btnCameraClicked() {
	if (camera_FR != nullptr) {
		if (camera_FR->status() == QCamera::ActiveStatus) camera_FR->stop();
		else camera_FR->start();
	}
	if (camera_UB != nullptr) {
		if (camera_UB->status() == QCamera::ActiveStatus) camera_UB->stop();
		else camera_UB->start();
	}
	if (camera_LD != nullptr) {
		if (camera_LD->status() == QCamera::ActiveStatus) camera_LD->stop();
		else camera_LD->start();
	}
}

void CubeExplorerWithQt::on_btnShowSamRecsClicked()
{
	QMap<QString, vector<SamRec>> &map_pic_id_samRec = getSamRecMap();	//获取采样框数据map
	vector<SamRec> map_id_samRec;
	QGraphicsScene* scene;
	QRect rect;
	QGraphicsRectItem *item;

	QPen pen;															//自定义画笔进行item的绘画
	pen.setWidth(2);													//
	pen.setColor(Qt::green);											//

	for (int i = 0; i < map_pic_id_samRec.size(); i++) {				//遍历采样框数据map
		map_id_samRec = map_pic_id_samRec[list_picID[i]];				//从list_picID获取字符串作为键值从采样框数据map中获取对应图片的采样框
		scene = map_pic_pScene[list_picID[i]];							//以同样的键值从scene指针map中获取对应图片的scene指针
		for (int j = 0; j < map_id_samRec.size(); j++) {				//遍历单个图片的采样框数据vector,将SamRec结构转换为符合视野比例的QRect并利用scene指针将采样框绘制到界面上
			rect = { map_id_samRec[j].x1 / 2 + 5,						//x = x1 / 2 + 5
					 map_id_samRec[j].y1 / 2 + 5,						//y = y1 / 2 + 5
					(map_id_samRec[j].x2 - map_id_samRec[j].x1) / 2,	//width = (x2 - x1) / 2
					(map_id_samRec[j].y2 - map_id_samRec[j].y1) / 2 };	//height = (y2 - y1) / 2
			
			item = new QGraphicsRectItem(rect);							//构建RectItem并绘制到指定scene
			item->setPen(pen);											//
			scene->addItem(item);										//
		}
	}
}

void CubeExplorerWithQt::on_btnSetHSVClicked()
{
	HSVThresholdDialog td(this);
	td.show();
	td.exec();
}

//右键菜单响应槽函数
void CubeExplorerWithQt::slot_mouseReleasedInCameraViews(QRect rec_select)
{
	rec_tSelect = rec_select;

	QMyGraphicsView *view_sender = qobject_cast<QMyGraphicsView*>(sender());
	QPointF sceneAxis_startPoint = view_sender->mapToScene(rec_select.x(), rec_select.y());	//将View坐标映射到Scene坐标
	QGraphicsRectItem* item = new QGraphicsRectItem(QRect(sceneAxis_startPoint.x(), sceneAxis_startPoint.y(), rec_select.width(), rec_select.height()));
	QPen pen;						//自定义画笔进行item的绘画
	pen.setWidth(2);				//
	pen.setColor(Qt::black);		//
	item->setPen(pen);				//
	view_sender->scene()->addItem(item);	//绘制item到场景内

	//弹出菜单
	ui.actSetBlock->setData(view_sender->objectName());	//配置action数据，告知当前触发菜单的摄像头View
	ui.actShowHSV->setData(view_sender->objectName());	//

	QMenu *popMenu = new QMenu();
	popMenu->addAction(ui.actSetBlock);
	popMenu->addAction(ui.actShowHSV);
	popMenu->addSeparator();
	popMenu->addAction(ui.actCancel);
	popMenu->exec(QCursor::pos());
	view_sender->scene()->removeItem(item);
	delete popMenu;
	popMenu = nullptr;
}

void CubeExplorerWithQt::slot_menuSetRecTriggered()
{
	QString t = ui.actSetBlock->data().toString();
	QString caller;
	caller.append(t[t.length() - 2]);
	caller.append(t[t.length() - 1]);

	RecogAreaDialog rad(caller,rec_tSelect, this);
	rad.setWindowTitle(caller);
	rad.show();
	rad.exec();
}

void CubeExplorerWithQt::slot_menuShowHSVTriggered()
{
	QString t = ui.actShowHSV->data().toString();
	QString caller;
	caller.append(t[t.length() - 2]);
	caller.append(t[t.length() - 1]);

	capture_FR->capture(curPath+"/pic_cam/"+caller+"_temp_for_showHSV");
}


void CubeExplorerWithQt::slot_setRecArea(QString groupName,QRect rect,int faceID, int blockID)
{
	ui.label_UI_message->setText(QStringLiteral("set Rect for")+groupName+faceID+blockID);
	SamRec rec2set = { (rect.x() - 5) * 2,(rect.x() + rect.width() - 5) * 2,(rect.y() - 5) * 2,(rect.y() + rect.height() - 5) * 2 };
	setSampleRec(groupName, rec2set, faceID, blockID);		//设置采样矩阵

}

void CubeExplorerWithQt::slot_imageSaved(int id, QString fileName)
{
	if (fileName.indexOf("HSV")!=-1) {		//确认当前操作是统计HSV数值
		cv::Mat mat_t = cv::imread(fileName.toStdString());
		int x = (rec_tSelect.x() - 5) * 2;
		int y = (rec_tSelect.y() - 5) * 2;
		cv::Mat imgBGR = mat_t(cv::Range(y, y + rec_tSelect.height() * 2), cv::Range(x, x + rec_tSelect.width() * 2));

		HSVDataDialog HSVDialog(imgBGR, this);
		HSVDialog.setWindowTitle(QStringLiteral("HSV数据统计"));
		HSVDialog.show();
		HSVDialog.exec();
	}
	else nImgSaved++;				//拍照计数器递增，用于在复原前判断截图保存是否完成
}

//串口模块响应槽函数
void CubeExplorerWithQt::on_btnPortRefreshClicked()
{
	ui.comboBox_coms->clear();
	foreach(QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
		ui.comboBox_coms->addItem(info.portName());
	}
}

void CubeExplorerWithQt::on_btnPortOpenClicked()
{
	if (serialPort->isOpen()) {
		if (serialPort->open(QIODevice::ReadWrite)) ui.label_portMessage->setText (QStringLiteral("打开串口成功..."));
		else ui.label_portMessage->setText(QStringLiteral("打开串口失败..."));
	}
	else {
		serialPort->close();
		ui.label_portMessage->setText(QStringLiteral("已关闭串口..."));
	}
}

void CubeExplorerWithQt::on_btnPortSendClicked()
{
	if (serialPort->isOpen()) {
		serialPort->write(ui.plainTextEdit_portWrite->toPlainText().toLatin1());
		serialPort->flush();
	}
	else ui.label_portMessage->setText(QStringLiteral("串口未打开！！！"));
}

void CubeExplorerWithQt::slot_portInfoChanged(const QString & text)
{
	serialPort->setPortName(text);
}
