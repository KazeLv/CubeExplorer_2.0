#include "DebugWidget.h"

DebugWidget::DebugWidget(QSerialPort* serialPort, QWidget *parent)
	: serialPortDebug(serialPort), QDialog(parent), ui(Ui::DebugWidget())
{
	ui.setupUi(this);

	connect(ui.btn_showLastSample, SIGNAL(clicked()), this, SLOT(on_btnShowLastSampleClicked()));

	connect(ui.btn_left_close, SIGNAL(clicked()), this, SLOT(ClickBtnLeftClose()));
	connect(ui.btn_left_close_small, SIGNAL(clicked()), this, SLOT(ClickBtnLeftCloseSmall()));
	connect(ui.btn_left_close_half, SIGNAL(clicked()), this, SLOT(ClickBtnLeftHalfClose()));
	connect(ui.btn_left_open, SIGNAL(clicked()), this, SLOT(ClickBtnLeftOpen()));
	connect(ui.btn_left_open_small, SIGNAL(clicked()), this, SLOT(ClickBtnLeftOpenSmall()));
	connect(ui.btn_left_open_all, SIGNAL(clicked()), this, SLOT(ClickBtnLeftOpenAll()));
	connect(ui.btn_left_to90, SIGNAL(clicked()), this, SLOT(ClickBtnLeftTo90()));
	connect(ui.btn_left_to180, SIGNAL(clicked()), this, SLOT(ClickBtnLeftTo180()));
	connect(ui.btn_left_clockwise, SIGNAL(clicked()), this, SLOT(ClickBtnLeftClock()));
	connect(ui.btn_left_anticlockwise, SIGNAL(clicked()), this, SLOT(ClickBtnLeftAnticlock()));
	connect(ui.btn_left_clockwise_small, SIGNAL(clicked()), this, SLOT(ClickBtnLeftClockSmall()));
	connect(ui.btn_left_anticlockwise_small, SIGNAL(clicked()), this, SLOT(ClickBtnLeftAnticlockSmall()));
	connect(ui.btn_left_180, SIGNAL(clicked()), this, SLOT(ClickBtnLeft180()));
	connect(ui.btn_left_5circle, SIGNAL(clicked()), this, SLOT(ClickBtnLeft5Circle()));
	connect(ui.btn_right_close, SIGNAL(clicked()), this, SLOT(ClickBtnRightClose()));
	connect(ui.btn_right_close_small, SIGNAL(clicked()), this, SLOT(ClickBtnRightCloseSmall()));
	connect(ui.btn_right_close_half, SIGNAL(clicked()), this, SLOT(ClickBtnRightHalfClose()));
	connect(ui.btn_right_open, SIGNAL(clicked()), this, SLOT(ClickBtnRightOpen()));
	connect(ui.btn_right_open_small, SIGNAL(clicked()), this, SLOT(ClickBtnRightOpenSmall()));
	connect(ui.btn_right_open_all, SIGNAL(clicked()), this, SLOT(ClickBtnRightOpenAll()));
	connect(ui.btn_right_to90, SIGNAL(clicked()), this, SLOT(ClickBtnRightTo90()));
	connect(ui.btn_right_to180, SIGNAL(clicked()), this, SLOT(ClickBtnRightTo180()));
	connect(ui.btn_right_clockwise, SIGNAL(clicked()), this, SLOT(ClickBtnRightClock()));
	connect(ui.btn_right_anticlockwise, SIGNAL(clicked()), this, SLOT(ClickBtnRightAnticlock()));
	connect(ui.btn_right_clockwise_small, SIGNAL(clicked()), this, SLOT(ClickBtnRightClockSmall()));
	connect(ui.btn_right_anticlockwise_small, SIGNAL(clicked()), this, SLOT(ClickBtnRightAnticlockSmall()));
	connect(ui.btn_right_180, SIGNAL(clicked()), this, SLOT(ClickBtnRight180()));
	connect(ui.btn_right_5circle, SIGNAL(clicked()), this, SLOT(ClickBtnRight5Circle()));


	QGraphicsScene* scene_case1_FR = new QGraphicsScene;
	QGraphicsScene* scene_case1_UB = new QGraphicsScene;
	QGraphicsScene* scene_case1_LD = new QGraphicsScene;
	QGraphicsScene* scene_case2_FR = new QGraphicsScene;
	QGraphicsScene* scene_case2_UB = new QGraphicsScene;
	QGraphicsScene* scene_case2_LD = new QGraphicsScene;
	QImage* image = new QImage();
	QImage imageTmp;

	image->load(QString("./pic_cam/cam_case1_FR.jpg"));
	imageTmp = image->scaled(ui.graphicsView_case1_FR->width() - 10, ui.graphicsView_case1_FR->height() - 10);
	scene_case1_FR->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_case1_FR->setScene(scene_case1_FR);
	ui.graphicsView_case1_FR->show();

	image->load(QString("./pic_cam/cam_case1_UB.jpg"));
	imageTmp = image->scaled(ui.graphicsView_case1_UB->width() - 10, ui.graphicsView_case1_UB->height() - 10);
	scene_case1_UB->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_case1_UB->setScene(scene_case1_UB);
	ui.graphicsView_case1_UB->show();

	image->load(QString("./pic_cam/cam_case1_LD.jpg"));
	imageTmp = image->scaled(ui.graphicsView_case1_LD->width() - 10, ui.graphicsView_case1_LD->height() - 10);
	scene_case1_LD->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_case1_LD->setScene(scene_case1_LD);
	ui.graphicsView_case1_LD->show();

	image->load(QString("./pic_cam/cam_case2_FR.jpg"));
	imageTmp = image->scaled(ui.graphicsView_case2_FR->width() - 10, ui.graphicsView_case2_FR->height() - 10);
	scene_case2_FR->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_case2_FR->setScene(scene_case2_FR);
	ui.graphicsView_case2_FR->show();

	image->load(QString("./pic_cam/cam_case2_UB.jpg"));
	imageTmp = image->scaled(ui.graphicsView_case2_UB->width() - 10, ui.graphicsView_case2_UB->height() - 10);
	scene_case2_UB->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_case2_UB->setScene(scene_case2_UB);
	ui.graphicsView_case2_UB->show();

	image->load(QString("./pic_cam/cam_case2_LD.jpg"));
	imageTmp = image->scaled(ui.graphicsView_case2_LD->width() - 10, ui.graphicsView_case2_LD->height() - 10);
	scene_case2_LD->addPixmap(QPixmap::fromImage(imageTmp));
	ui.graphicsView_case2_LD->setScene(scene_case2_LD);
	ui.graphicsView_case2_LD->show();
}

DebugWidget::~DebugWidget()
{
}

void DebugWidget::on_btnShowLastSampleClicked() {
	LastSampleDialog lsd(this);
	lsd.setWindowTitle(QStringLiteral("识别采样"));
	lsd.show();
	lsd.exec();
}

void DebugWidget::ClickBtnLeftClose() {
	serialPortDebug->write(QString("#2P1T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftCloseSmall() {
	serialPortDebug->write(QString("#2P4T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftHalfClose() {
	serialPortDebug->write(QString("#2P2T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftOpen() {
	serialPortDebug->write(QString("#2P0T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftOpenSmall() {
	serialPortDebug->write(QString("#2P3T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftOpenAll() {
	serialPortDebug->write(QString("#2P5T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftTo90() {
	serialPortDebug->write(QString("#1P90T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftTo180() {
	serialPortDebug->write(QString("#1P180T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftClock() {
	serialPortDebug->write(QString("#1P6T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftAnticlock() {
	serialPortDebug->write(QString("#1P7T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftClockSmall() {
	serialPortDebug->write(QString("#1P3T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeftAnticlockSmall() {
	serialPortDebug->write(QString("#1P4T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeft180() {
	serialPortDebug->write(QString("#1P8T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnLeft5Circle() {
	serialPortDebug->write(QString("#1P5T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightClose() {
	serialPortDebug->write(QString("#4P1T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightCloseSmall() {
	serialPortDebug->write(QString("#4P4T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightHalfClose() {
	serialPortDebug->write(QString("#4P2T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightOpen() {
	serialPortDebug->write(QString("#4P0T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightOpenSmall() {
	serialPortDebug->write(QString("#4P3T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightOpenAll() {
	serialPortDebug->write(QString("#4P5T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightTo90() {
	serialPortDebug->write(QString("#3P90T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightTo180() {
	serialPortDebug->write(QString("#3P180T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightClock() {
	serialPortDebug->write(QString("#3P6T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightAnticlock() {
	serialPortDebug->write(QString("#3P7T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightClockSmall() {
	serialPortDebug->write(QString("#3P3T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRightAnticlockSmall() {
	serialPortDebug->write(QString("#3P4T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRight180() {
	serialPortDebug->write(QString("#3P8T200\r\n").toLatin1());
}

void DebugWidget::ClickBtnRight5Circle() {
	serialPortDebug->write(QString("#3P5T200\r\n").toLatin1());
}