#include "RecogAreaDialog.h"

RecogAreaDialog::RecogAreaDialog(QString caller,QRect rect,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	m_rec = rect;
	m_strCaller = caller;
	ui.groupBtnBox_1->setTitle(QString(caller[0]));
	ui.groupBtnBox_2->setTitle(QString(caller[1]));

	//�������岼��ΪGridLayout
	gridLayout = new QGridLayout;
	this->setLayout(gridLayout);

	//���ݲ�ͬ����������в�ͬ�Ĳ���	
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

	//��ť�۰�
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

	//����ȡɫ�����źŰ�
	connect(this, SIGNAL(signal_setRecArea(QString, QRect, int, int)), parent, SLOT(slot_setRecArea(QString, QRect, int, int)));
}

RecogAreaDialog::~RecogAreaDialog()
{
	delete gridLayout;
}

void RecogAreaDialog::on_btnsClicked() {
	//�����Ի���ѯ���Ƿ�ȷ�ϵ�ǰѡ��
	QMessageBox::StandardButton btnReply;
	btnReply = QMessageBox::question(this, QStringLiteral("ȡɫ��ȷ��"), QStringLiteral("ȷ������ǰ��ѡ������Ϊָ��ɫ���ȡɫ������"), QMessageBox::Yes | QMessageBox::Cancel);
	//ֻ��ѡ��ȷ��ʱ�������ò���
	if (btnReply == QMessageBox::Yes) {
		int iBlockID, iFaceID;
		//��ȡ�����źŵİ�ť��Ϣ
		QPushButton* btn = qobject_cast<QPushButton*>(sender());	//sender()��ȡ
		QString btnName = btn->objectName();
		char cBlockID = btnName[btnName.length() - 1].unicode();
		char cFaceID = btnName[btnName.length() - 3].unicode();

		//���ݰ�ťObjectName����λȷ��ѡ����ħ����źͿ��
		iFaceID = cFaceID - '0';
		iBlockID = cBlockID - '0';
		
		emit signal_setRecArea(m_strCaller,m_rec, iFaceID, iBlockID);
		this->reject();
	}
}
