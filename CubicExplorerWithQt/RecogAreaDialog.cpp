#include "RecogAreaDialog.h"

RecogAreaDialog::RecogAreaDialog(QString caller,QRect rect,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	m_rec = rect;
	m_strCaller = caller;
	ui.groupBtnBox_1->setTitle(QString(caller[0]));
	ui.groupBtnBox_2->setTitle(QString(caller[1]));

	//设置总体布局为GridLayout
	gridLayout = new QGridLayout;
	this->setLayout(gridLayout);

	//根据不同的拍摄面进行不同的布局	
	if (caller[1] == 'D') {
		gridLayout->addWidget(ui.groupBtnBox_1, 0, 0);
		gridLayout->addWidget(ui.groupBtnBox_2, 1, 0);
		resize(200, 400);
	}
	else {
		gridLayout->addWidget(ui.groupBtnBox_1, 0, 0);
		gridLayout->addWidget(ui.groupBtnBox_2, 0, 1);
		resize(400, 200);
	}

	//按钮槽绑定
	connect(ui.btn_block1_1, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_2, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_3, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_4, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_5, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_6, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_7, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_8, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block1_9, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_1, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_2, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_3, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_4, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_5, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_6, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_7, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_8, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));
	connect(ui.btn_block2_9, SIGNAL(clicked()), this, SLOT(on_btnsClicked()));

	//设置取色区域信号绑定
	connect(this, SIGNAL(signal_setRecArea(QString, QRect, int, int)), parent, SLOT(slot_setRecArea(QString, QRect, int, int)));
}

RecogAreaDialog::~RecogAreaDialog()
{
	delete gridLayout;
}

void RecogAreaDialog::on_btnsClicked() {
	//弹出对话框询问是否确认当前选择
	QMessageBox::StandardButton btnReply;
	btnReply = QMessageBox::question(this, QStringLiteral("取色块确认"), QStringLiteral("确定将当前框选区域作为指定色块的取色区域吗？"), QMessageBox::Yes | QMessageBox::Cancel);
	//只在选择确定时进行设置操作
	if (btnReply == QMessageBox::Yes) {
		int iBlockID, iFaceID;
		//获取发送信号的按钮信息
		QPushButton* btn = qobject_cast<QPushButton*>(sender());	//sender()获取
		QString btnName = btn->objectName();
		char cBlockID = btnName[btnName.length() - 1].unicode();
		char cFaceID = btnName[btnName.length() - 3].unicode();

		//根据按钮ObjectName后三位确定选定的魔方面号和块号
		iFaceID = cFaceID - '0';
		iBlockID = cBlockID - '0';
		
		emit signal_setRecArea(m_strCaller,m_rec, iFaceID, iBlockID);
		this->reject();
	}
}
