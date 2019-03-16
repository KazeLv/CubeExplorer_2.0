#include "CubeExplorerWithQt.h"

CubeExplorerWithQt::CubeExplorerWithQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	curPath = QDir::currentPath();		//��ȡ��ǰ����·��

	//���水ť�źŲ۰�
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
		
	//��ʼ������ͷ
	iniCamera();

	//����CubicExplorer����
	cubeExplorer = CubeExplorer();

	//��ʼ�����������
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
	//����ͷ��ʾ�������Ӧ�۰�
	connect(ui.graView_cameraFR, SIGNAL(mouseReleased(QRect)), this, SLOT(slot_mouseReleasedInCameraViews(QRect)));
	connect(ui.graView_cameraUB, SIGNAL(mouseReleased(QRect)), this, SLOT(slot_mouseReleasedInCameraViews(QRect)));
	connect(ui.graView_cameraLD, SIGNAL(mouseReleased(QRect)), this, SLOT(slot_mouseReleasedInCameraViews(QRect)));

	//�˵�action��
	connect(ui.actSetBlock, SIGNAL(triggered()), this, SLOT(slot_menuSetRecTriggered()));
	connect(ui.actShowHSV, SIGNAL(triggered()), this, SLOT(slot_menuShowHSVTriggered()));

	//��ȡ��������ͷ��Ϣ
	list_cameraInfo.clear();
	foreach(QCameraInfo info, QCameraInfo::availableCameras()) {
		list_cameraInfo.append(info);
	}

	camera_FR = new QCamera(list_cameraInfo.at(0));
	capture_FR = new QCameraImageCapture(camera_FR);

	//Capture��Ӧ�۰�
	connect(capture_FR, SIGNAL(imageSaved(int, QString)), this, SLOT(slot_imageSaved(int, QString)));

	//��ʼ������ͷ��ʾ���
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

	scene_FR->addItem(videoItem_FR);
	scene_UB->addItem(videoItem_UB);
	scene_LD->addItem(videoItem_LD);

	camera_FR->setViewfinder(videoItem_FR);
}

void CubeExplorerWithQt::Capture(std::string Case) {
	//char filename[200];
	//Mat frameFR, frameUB, frameLD;		//order: BDFLRU
	//Mat frameFR_p, frameUB_p, frameLD_p;
	//captureFR >> frameFR;
	//captureUB >> frameUB;
	//captureLD >> frameLD;
	//captureFR >> frameFR;
	//captureUB >> frameUB;
	//captureLD >> frameLD;
	//captureFR >> frameFR;
	//captureUB >> frameUB;
	//captureLD >> frameLD;

	//if (Case == "Case1") {
	//	captureFR >> frameFR;
	//	captureUB >> frameUB;
	//	captureLD >> frameLD;
	//	sprintf(filename, "./pic_cam/cam_case1_RF.png");
	//	imwrite(filename, frameFR);//ͼƬ���浽������Ŀ¼��  
	//	sprintf(filename, "./pic_cam/cam_case1_BU.png");
	//	imwrite(filename, frameUB);//ͼƬ���浽������Ŀ¼��
	//	sprintf(filename, "./pic_cam/cam_case1_LD.png");
	//	imwrite(filename, frameLD);//ͼƬ���浽������Ŀ¼��

	//}
	//else if (Case == "Case2") {
	//	captureFR >> frameFR;
	//	captureUB >> frameUB;
	//	captureLD >> frameLD;
	//	sprintf(filename, "./pic_cam/cam_case2_RF.png");
	//	imwrite(filename, frameFR);
	//	sprintf(filename, "./pic_cam/cam_case2_BU.png");
	//	imwrite(filename, frameUB);
	//	sprintf(filename, "./pic_cam/cam_case2_LD.png");
	//	imwrite(filename, frameLD);
	//}
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

void CubeExplorerWithQt::on_btnTightOrLooseClicked() {
	//������ֻ��е�ֽ���΢�ɿ��ͼн�������װ���ȡ��ħ��
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
	//������ֻ�ֱۻָ�����ʼ�Ƕȣ��Ա���һ�θ�ԭ�Ľ���
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
	cubeExplorer.Reset();
	serialPort->write(QString("#2P1T200\r\n").toLatin1());
	serialPort->write(QString("#4P1T200\r\n").toLatin1());
	//1.����case1���õ�strCase1������case2���õ�strCase2
		//a.���ּн��������ɿ�
	serialPort->write(QString("#4P5T200\r\n").toLatin1());
	serialPort->flush();
	cubeExplorer.handState.right.isTight = false;

		//b.����case1
	Sleep(500);
	Capture("Case1");

		//c.���ּн��������ɿ�
	serialPort->clear();
	serialPort->write(QString("#4P1T200\r\n").toLatin1());
	serialPort->write(QString("#2P5T200\r\n").toLatin1());
	//serialPort->waitForBytesWritten();
	cubeExplorer.handState.left.isTight = false;
	cubeExplorer.handState.right.isTight = true;

		//d.����case2
	Sleep(500);
	Capture("Case2");

	//2.����ʶ��õ�ʶ���ַ���
	//��Ϊ����ͷ��δ��ȫ��������ʹ����ǰ���µ�case��Ƭ���в���
	std::string strRec = Recognition();
	//std::string strRec = "BBLFUBDLLURBDRDBRDLUFRFBRLUBFRBDFURRUUFDLUFUDDLLFBLFDR";


	//��ʶ������ʾ�ڽ�����
	//ui.text_cubicState->setText(QString(strRec.c_str()));
	QGraphicsScene* scene_rec_F = new QGraphicsScene;
	QGraphicsScene* scene_rec_R = new QGraphicsScene;
	QGraphicsScene* scene_rec_U = new QGraphicsScene;
	QGraphicsScene* scene_rec_B = new QGraphicsScene;
	QGraphicsScene* scene_rec_L = new QGraphicsScene;
	QGraphicsScene* scene_rec_D = new QGraphicsScene;
	QImage* image = new QImage();
	QImage imageTmp;

	image->load(QString("./pic_rec/rec_R.png"));
	imageTmp = image->scaled(ui.graphicsView_R->width() - 10, ui.graphicsView_R->height() - 10);
	scene_rec_R->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_R->setScene(scene_rec_R);
	ui.graphicsView_R->show();

	image->load(QString("./pic_rec/rec_F.png"));
	imageTmp = image->scaled(ui.graphicsView_F->width() - 10, ui.graphicsView_F->height() - 10);
	scene_rec_F->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_F->setScene(scene_rec_F);
	ui.graphicsView_F->show();

	image->load(QString("./pic_rec/rec_U.png"));
	imageTmp = image->scaled(ui.graphicsView_U->width() - 10, ui.graphicsView_U->height() - 10);
	scene_rec_U->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_U->setScene(scene_rec_U);
	ui.graphicsView_U->show();

	image->load(QString("./pic_rec/rec_B.png"));
	imageTmp = image->scaled(ui.graphicsView_B->width() - 10, ui.graphicsView_B->height() - 10);
	scene_rec_B->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_B->setScene(scene_rec_B);
	ui.graphicsView_B->show();

	image->load(QString("./pic_rec/rec_L.png"));
	imageTmp = image->scaled(ui.graphicsView_L->width() - 10, ui.graphicsView_L->height() - 10);
	scene_rec_L->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_L->setScene(scene_rec_L);
	ui.graphicsView_L->show();

	image->load(QString("./pic_rec/rec_D.png"));
	imageTmp = image->scaled(ui.graphicsView_D->width() - 10, ui.graphicsView_D->height() - 10);
	scene_rec_D->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_D->setScene(scene_rec_D);
	ui.graphicsView_D->show();

	//3.���������ַ����õ�����ʶ�����в���ʼ��CubicExplorer����
	char* cp = new char[strRec.length() + 1];
	strcpy(cp, strRec.c_str());
	char* res = cube_solve(cp, NULL);
	if (!res) {
		//ui.label_UI_tip->setText(QStringLiteral("���󣺴����ʶ�����У���"));
		return;
	}
	cubeExplorer.SetTarget(res);

	//4.CubicExplorer������ý��㷽�����õ����ڲ��������ַ���
	cubeExplorer.GetShortestWay();
	////������������ʾ��GUI��listView��
	//QStringList qslOperation;
	//vector<string> vsOperation = cubicExplorer.GetVecStrSerial();
	//for (auto iter = vsOperation.cbegin(); iter != vsOperation.cend(); iter++) {
	//	qslOperation << QString(iter->c_str());
	//}
	//QStringListModel* model = new QStringListModel(qslOperation);
	//ui.listView_operation->setModel(model);
	//int cnt = cubicExplorer.GetVecStrSerial().size();
	//ui.label_UI_operationCount->setText(QString::number(cnt));

	//5.ͨ������ͨ�ŰѴ������д��ݸ����ƻ�����ʹ��listView�ؼ�ʵʱ��ʾ�������д������
	SendOperationSerial();

	//6.������ɺ�ʹ��GUI�ײ�label������Ϣ�������Ѿ���ԭ���
	//ui.label_UI_tip->setText(QStringLiteral("�������д������..."));
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

}

void CubeExplorerWithQt::on_btnSetHSVClicked()
{
	HSVThresholdDialog td(this);
	td.show();
	td.exec();
}

void CubeExplorerWithQt::slot_mouseReleasedInCameraViews(QRect rec_select)
{
	rec_tSelect = rec_select;

	QMyGraphicsView *view_sender = qobject_cast<QMyGraphicsView*>(sender());
	QPointF sceneAxis_startPoint = view_sender->mapToScene(rec_select.x(), rec_select.y());	//��View����ӳ�䵽Scene����
	QGraphicsRectItem* item = new QGraphicsRectItem(QRect(sceneAxis_startPoint.x(), sceneAxis_startPoint.y(), rec_select.width(), rec_select.height()));
	QPen pen;						//�Զ��廭�ʽ���item�Ļ滭
	pen.setWidth(2);				//
	pen.setColor(Qt::black);		//
	item->setPen(pen);				//
	view_sender->scene()->addItem(item);	//����item��������

	//�����˵�
	ui.actSetBlock->setData(view_sender->objectName());	//����action���ݣ���֪��ǰ�����˵�������ͷView
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
	string strGroupName = groupName.toStdString();
	setSampleRec(strGroupName, rec2set, faceID, blockID);		//���ò�������

}

void CubeExplorerWithQt::slot_imageSaved(int id, QString fileName)
{
	if (fileName.indexOf("HSV")!=-1) {		//ȷ�ϵ�ǰ������ͳ��HSV��ֵ
		cv::Mat mat_t = cv::imread(fileName.toStdString());
		int x = (rec_tSelect.x() - 5) * 2;
		int y = (rec_tSelect.y() - 5) * 2;
		cv::Mat imgBGR = mat_t(cv::Range(y, y + rec_tSelect.height() * 2), cv::Range(x, x + rec_tSelect.width() * 2));

		HSVDataDialog HSVDialog(imgBGR, this);
		HSVDialog.setWindowTitle(QStringLiteral("HSV����ͳ��"));
		HSVDialog.show();
		HSVDialog.exec();

		//for (int i = 0; i < imgHSV.rows; i++) {
		//	for (int j = 0; j < imgHSV.cols; j++) {
		//		Point p(i, j);
		//		int(imgHSV.at<Vec3b>(p)[0]);//p[0,1,2]�ֱ���H��S��V
		//	}
		//}
	}
}

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
		if (serialPort->open(QIODevice::ReadWrite)) ui.label_portMessage->setText (QStringLiteral("�򿪴��ڳɹ�..."));
		else ui.label_portMessage->setText(QStringLiteral("�򿪴���ʧ��..."));
	}
	else {
		serialPort->close();
		ui.label_portMessage->setText(QStringLiteral("�ѹرմ���..."));
	}
}

void CubeExplorerWithQt::on_btnPortSendClicked()
{
	if (serialPort->isOpen()) {
		serialPort->write(ui.plainTextEdit_portWrite->toPlainText().toLatin1());
		serialPort->flush();
	}
	else ui.label_portMessage->setText(QStringLiteral("����δ�򿪣�����"));
}

void CubeExplorerWithQt::slot_portInfoChanged(const QString & text)
{
	serialPort->setPortName(text);
}

