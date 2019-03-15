#pragma once
#include <QtWidgets/QWidget>
#include <iostream>
#include "CubeRecognizer.h"
#include "CubeExplorer.h"
#include <qserialport.h>
#include <QStringListModel>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include <qfiledialog.h>
#include "ui_CubicExplorerWithQt.h"
#include "ui_DebugWidget.h"
#include "CubeExplorerWithQt.h"

class DebugWidget : public QDialog
{
	Q_OBJECT

public:
	DebugWidget(QSerialPort* serialPort, QWidget *parent = Q_NULLPTR);
	~DebugWidget();

public slots:
	//×ó×¦¿ªºÏ
	void ClickBtnLeftClose();
	void ClickBtnLeftCloseSmall();
	void ClickBtnLeftHalfClose();
	void ClickBtnLeftOpen();
	void ClickBtnLeftOpenSmall();
	void ClickBtnLeftOpenAll();

	//×ó×¦Ðý×ª
	void ClickBtnLeftTo90();
	void ClickBtnLeftTo180();
	void ClickBtnLeftClock();
	void ClickBtnLeftAnticlock();
	void ClickBtnLeftClockSmall();
	void ClickBtnLeftAnticlockSmall();
	void ClickBtnLeft180();
	void ClickBtnLeft5Circle();

	//ÓÒ×¦¿ªºÏ
	void ClickBtnRightClose();
	void ClickBtnRightCloseSmall();
	void ClickBtnRightHalfClose();
	void ClickBtnRightOpen();
	void ClickBtnRightOpenSmall();
	void ClickBtnRightOpenAll();

	//ÓÒ×¦Ðý×ª
	void ClickBtnRightTo90();
	void ClickBtnRightTo180();
	void ClickBtnRightClock();
	void ClickBtnRightAnticlock();
	void ClickBtnRightClockSmall();
	void ClickBtnRightAnticlockSmall();
	void ClickBtnRight180();
	void ClickBtnRight5Circle();

private:
	Ui::DebugWidget ui;
	QSerialPort* serialPortDebug;
};
