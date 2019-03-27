#include "LastSampleDialog.h"

LastSampleDialog::LastSampleDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	list_btnBlock.append(ui.btn_sample0);		//��Ӱ�ťָ�뵽�б���������ͼ��
	list_btnBlock.append(ui.btn_sample1);		//
	list_btnBlock.append(ui.btn_sample2);		//
	list_btnBlock.append(ui.btn_sample3);		//
	list_btnBlock.append(ui.btn_sample4);		//
	list_btnBlock.append(ui.btn_sample5);		//
	list_btnBlock.append(ui.btn_sample6);		//
	list_btnBlock.append(ui.btn_sample7);		//
	list_btnBlock.append(ui.btn_sample8);		//

	curFace = "f";								//Ĭ�ϴ�ʱ��ʾF��Ĳ�����ť
	ui.radioBtn_f->setChecked(true);			//
	setIconBySample();							//


	connect(ui.btn_sample0, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//�󶨲���ͼ��ť�ۺ���
	connect(ui.btn_sample1, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//
	connect(ui.btn_sample2, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//
	connect(ui.btn_sample3, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//
	connect(ui.btn_sample4, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//
	connect(ui.btn_sample5, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//
	connect(ui.btn_sample6, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//
	connect(ui.btn_sample7, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//
	connect(ui.btn_sample8, SIGNAL(clicked()), this, SLOT(on_btnSampleBlockClicked()));		//

	connect(ui.radioBtn_f, SIGNAL(toggled(bool)), this, SLOT(on_radioFaceToggled(bool)));	//����ѡ��ť�ۺ���
	connect(ui.radioBtn_r, SIGNAL(toggled(bool)), this, SLOT(on_radioFaceToggled(bool)));	//
	connect(ui.radioBtn_u, SIGNAL(toggled(bool)), this, SLOT(on_radioFaceToggled(bool)));	//
	connect(ui.radioBtn_b, SIGNAL(toggled(bool)), this, SLOT(on_radioFaceToggled(bool)));	//
	connect(ui.radioBtn_l, SIGNAL(toggled(bool)), this, SLOT(on_radioFaceToggled(bool)));	//
	connect(ui.radioBtn_d, SIGNAL(toggled(bool)), this, SLOT(on_radioFaceToggled(bool)));	//
}

LastSampleDialog::~LastSampleDialog()
{
}

void LastSampleDialog::setIconBySample()
{
	QMap<QString, vector<cv::Mat>>& map_face_id_lastRecogMat = getLastRecogMatMap();

	vector<cv::Mat>& vec_id_lastRecogMat = map_face_id_lastRecogMat[curFace];
	cv::Mat mat_t;
	for (int i = 0; i < vec_id_lastRecogMat.size(); i++) {
		cv::cvtColor(vec_id_lastRecogMat[i], mat_t, cv::COLOR_BGR2RGB);
		QImage img(mat_t.data, mat_t.cols, mat_t.rows, mat_t.step, QImage::Format_RGB888);

		QSize iconSize;
		if (img.width() > img.height()) iconSize = QSize(100, float(img.height()) / img.width() * 100);
		else if (img.height() > img.width()) iconSize = QSize(float(img.width()) / img.height() * 100, 100);
		list_btnBlock[i]->setIconSize(iconSize);

		list_btnBlock[i]->setIcon(QIcon(QPixmap::fromImage(img)));
	}
}

void LastSampleDialog::on_btnSampleBlockClicked() {
	int index = QString(*(sender()->objectName().end() - 1)).toInt();						//�õ������������¼��İ�ť���

	QMap<QString, vector<cv::Mat>>& map_face_id_lastRecogMat = getLastRecogMatMap();
	HSVDataDialog hsvDialog(map_face_id_lastRecogMat[curFace][index],this);					//��ʾ������HSV���ӻ�ͳ������
	hsvDialog.setWindowTitle("HSV-" + curFace.toUpper() + QString::number(index + 1));
	hsvDialog.show();
	hsvDialog.exec();
}

void LastSampleDialog::on_radioFaceToggled(bool checked) {
	if (checked) {
		curFace = *(sender()->objectName().end() - 1);	//���õ�ǰ��
		setIconBySample();								//���ݵ�ǰ�����ð�ťͼ��
	}
}
