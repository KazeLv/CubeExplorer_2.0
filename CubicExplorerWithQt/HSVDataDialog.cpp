#include "HSVDataDialog.h"

HSVDataDialog::HSVDataDialog(cv::Mat imageBGR,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//�������ݴ洢
	cv::cvtColor(imageBGR, m_matRGB, cv::COLOR_BGR2RGB);	//ת��ΪRGBͼƬ
	cv::cvtColor(imageBGR, m_matHSV, cv::COLOR_BGR2HSV);	//ת��ΪHSVͼƬ

	//��ʼ��������ݿ��ӻ�ͼ��
	iniGraph();

	//��ʼ���Ҳ�����������������Դѡ��
	iniStatistic();

	//������ģ����ӵ�����ˮƽ����
	ui.horizontalLayout->addWidget(containner,1);
	ui.horizontalLayout->addLayout(vLay_imgAndChannel);
}

HSVDataDialog::~HSVDataDialog()
{
	delete surface_graph;
}

void HSVDataDialog::calculation(string target)
{
	if(target == "H")dataArray_H = new QSurfaceDataArray();
	if (target == "S")dataArray_S = new QSurfaceDataArray();
	if (target == "V")dataArray_V = new QSurfaceDataArray();

	if (target == "H") nMin_H = nMax_H = m_matHSV.at<cv::Vec3b>(cv::Point(0, 0))[0];	//���/Сֵ����ֵΪ��һ����
	if (target == "V") nMin_S = nMax_S = m_matHSV.at<cv::Vec3b>(cv::Point(0, 0))[1];	//
	if (target == "S") nMin_V = nMax_V = m_matHSV.at<cv::Vec3b>(cv::Point(0, 0))[2];	//

	int sum = 0;				//HSV�����غ͸���ֵΪ0

	for (int i = 0; i < m_matHSV.rows; i++) {
		QSurfaceDataRow *newRow = new QSurfaceDataRow(m_matHSV.cols);
		/*QSurfaceDataRow *newRow_S = new QSurfaceDataRow(m_matHSV.cols);
		QSurfaceDataRow *newRow_V = new QSurfaceDataRow(m_matHSV.cols);*/
		for (int j = 0; j < m_matHSV.cols; j++) {
			cv::Point p(j, i);
			if (target == "H")(*newRow)[j].setPosition(QVector3D(j, m_matHSV.at<cv::Vec3b>(p)[0], m_matHSV.rows - i - 1));
			if (target == "S")(*newRow)[j].setPosition(QVector3D(j, m_matHSV.at<cv::Vec3b>(p)[1], m_matHSV.rows - i - 1));
			if (target == "V")(*newRow)[j].setPosition(QVector3D(j, m_matHSV.at<cv::Vec3b>(p)[2], m_matHSV.rows - i - 1));

			if (target == "H") {
				if (m_matHSV.at<cv::Vec3b>(p)[0] > nMax_H) nMax_H = m_matHSV.at<cv::Vec3b>(p)[0];
				else if (m_matHSV.at<cv::Vec3b>(p)[0] < nMin_H)nMin_H = m_matHSV.at<cv::Vec3b>(p)[0];
			}

			if (target == "S") {
				if (m_matHSV.at<cv::Vec3b>(p)[1] > nMax_S) nMax_S = m_matHSV.at<cv::Vec3b>(p)[1];
				else if (m_matHSV.at<cv::Vec3b>(p)[1] < nMin_S)nMin_S = m_matHSV.at<cv::Vec3b>(p)[1];
			}

			if (target == "V") {
				if (m_matHSV.at<cv::Vec3b>(p)[2] > nMax_V) nMax_V = m_matHSV.at<cv::Vec3b>(p)[2];
				else if (m_matHSV.at<cv::Vec3b>(p)[2] < nMin_V)nMin_V = m_matHSV.at<cv::Vec3b>(p)[2];
			}

			if (target == "H")sum += m_matHSV.at<cv::Vec3b>(p)[0];
			if (target == "S")sum += m_matHSV.at<cv::Vec3b>(p)[1];
			if (target == "V")sum += m_matHSV.at<cv::Vec3b>(p)[2];
		}
		if (target == "H")*dataArray_H << newRow;
		if (target == "S")*dataArray_S << newRow;
		if (target == "V")*dataArray_V << newRow;
	}

	int n = m_matHSV.cols*m_matHSV.rows;
	if (target == "H")nMean_H = sum / n;
	if (target == "S")nMean_S = sum / n;
	if (target == "V")nMean_V = sum / n;
}

void HSVDataDialog::iniGraph()
{
	surface_graph = new Q3DSurface();
	containner = QWidget::createWindowContainer(surface_graph);
	surface_graph->setAxisX(new QValue3DAxis);
	surface_graph->setAxisY(new QValue3DAxis);
	surface_graph->setAxisZ(new QValue3DAxis);

	proxy = new QSurfaceDataProxy();
	series = new QSurface3DSeries(proxy);

	//����������
	surface_graph->axisX()->setRange(0, m_matHSV.cols);
	surface_graph->axisX()->setLabelFormat("%d x");
	surface_graph->axisZ()->setRange(0, m_matHSV.rows);
	surface_graph->axisZ()->setLabelFormat("%d y");
	surface_graph->axisZ()->setReversed(true);
	surface_graph->addSeries(series);
}

void HSVDataDialog::iniStatistic()
{
	vLay_imgAndChannel = new QVBoxLayout;					//�������vertical����
	vLay_imgAndChannel->setAlignment(Qt::AlignTop);

	//����ͼƬ��ʾ������ͳ��
	groupBox_sample = new QGroupBox(QStringLiteral("��������"));
	label_showSamPic = new QLabel;
	label_max = new QLabel(QStringLiteral("Max: "));
	label_mean = new QLabel(QStringLiteral("Mean: "));
	label_min = new QLabel(QStringLiteral("Min: "));

	m_imgRGB = new QImage(m_matRGB.data, m_matRGB.cols, m_matRGB.rows, m_matRGB.step, QImage::Format_RGB888);
	label_showSamPic->setPixmap(QPixmap::fromImage(m_imgRGB->scaledToWidth(SAMPLED_PIC_SHOW_WIDTH)));
	label_showSamPic->setMinimumWidth(SAMPLED_PIC_SHOW_WIDTH);
	label_showSamPic->setMaximumWidth(SAMPLED_PIC_SHOW_WIDTH);

	vLay_samData = new QVBoxLayout;							//���ò���
	vLay_samData->addWidget(label_showSamPic);				//
	vLay_samData->addWidget(label_max);						//
	vLay_samData->addWidget(label_mean);					//
	vLay_samData->addWidget(label_min);						//
	groupBox_sample->setLayout(vLay_samData);				//

	vLay_imgAndChannel->addWidget(groupBox_sample);			//��ģ����ӵ��ұ�������

	//����Դѡ��
	groupBox_sourceSelect = new QGroupBox(QStringLiteral("����Դѡ��"));		//����Դѡ��ģ��
	radioBtn_H = new QRadioButton(QStringLiteral("H"), this);				//
	radioBtn_H->setChecked(false);											//
	radioBtn_S = new QRadioButton(QStringLiteral("S"), this);				//
	radioBtn_S->setChecked(false);											//
	radioBtn_V = new QRadioButton(QStringLiteral("V"), this);				//
	radioBtn_V->setChecked(false);											//

	vLay_radioBtn = new QVBoxLayout;						//����radioButton�Ĳ���
	vLay_radioBtn->addWidget(radioBtn_H);					//
	vLay_radioBtn->addWidget(radioBtn_S);					//
	vLay_radioBtn->addWidget(radioBtn_V);					//
	groupBox_sourceSelect->setLayout(vLay_radioBtn);		//

	vLay_imgAndChannel->addWidget(groupBox_sourceSelect);	//��ģ����ӵ��ұ�������

	connect(radioBtn_H, SIGNAL(toggled(bool)), this, SLOT(on_radioBtnHToggled(bool)));	//radioButton�����۰�
	connect(radioBtn_S, SIGNAL(toggled(bool)), this, SLOT(on_radioBtnSToggled(bool)));	//
	connect(radioBtn_V, SIGNAL(toggled(bool)), this, SLOT(on_radioBtnVToggled(bool)));	//
}

void HSVDataDialog::on_radioBtnHToggled(bool checked)
{
	if (checked) {
		//ͳ������
		calculation("H");

		//��ʾS��������
		proxy->resetArray(dataArray_H);
		surface_graph->axisY()->setRange(0, 180);
		surface_graph->axisY()->setLabelFormat("%d H");

		//��ʾͳ�ƽ��(���/��С/��ֵ)
		label_max->setText(QString::asprintf("Max: %d", nMax_H));
		label_mean->setText(QString::asprintf("Mean: %d", nMean_H));
		label_min->setText(QString::asprintf("Min: %d", nMin_H));
	}
}

void HSVDataDialog::on_radioBtnSToggled(bool checked)
{
	if (checked) {
		//ͳ������
		calculation("S");

		//��ʾS��������
		proxy->resetArray(dataArray_S);
		surface_graph->axisY()->setRange(0, 255);
		surface_graph->axisY()->setLabelFormat("%d S");

		//��ʾͳ�ƽ��(���/��С/��ֵ)
		label_max->setText(QString::asprintf("Max: %d", nMax_S));
		label_mean->setText(QString::asprintf("Mean: %d", nMean_S));
		label_min->setText(QString::asprintf("Min: %d", nMin_S));
	}
}

void HSVDataDialog::on_radioBtnVToggled(bool checked)
{
	if (checked) {
		//ͳ������
		calculation("V");

		//��ʾS��������
		proxy->resetArray(dataArray_V);
		surface_graph->axisY()->setRange(0, 255);
		surface_graph->axisY()->setLabelFormat("%d V");

		//��ʾͳ�ƽ��(���/��С/��ֵ)
		label_max->setText(QString::asprintf("Max: %d",nMax_V));
		label_mean->setText(QString::asprintf("Mean: %d", nMean_V));
		label_min->setText(QString::asprintf("Min: %d", nMin_V));
	}
}
