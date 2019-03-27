#include "CubeRecognizer.h"

////B D F L R U
//SamRec P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18;			//ÿ��ͼƬ����Ӧ18��������λ��
//
//static vector<SamRec> sampleRec_FR, sampleRec_UB, sampleRec_LD;	//�洢������Ƭ�Ĳ�����
//static string Bcolor[10];				//ʶ����
//static string Dcolor[10];				//
//static string Fcolor[10];				//
//static string Lcolor[10];				//
//static string Rcolor[10];				//
//static string Ucolor[10];				//
//static HSV BWhiteHSV, UWhiteHSV, RWhiteHSV, FWhiteHSV, LWhiteHSV, DWhiteHSV;
//static HSV BRedHSV_L, URedHSV_L, RRedHSV_L, FRedHSV_L, LRedHSV_L, DRedHSV_L;
//static HSV BRedHSV_H, URedHSV_H, RRedHSV_H, FRedHSV_H, LRedHSV_H, DRedHSV_H;
//static HSV BYellowHSV, UYellowHSV, RYellowHSV, FYellowHSV, LYellowHSV, DYellowHSV;
//static HSV BBlueHSV, UBlueHSV, RBlueHSV, FBlueHSV, LBlueHSV, DBlueHSV;
//static HSV BGreenHSV, UGreenHSV, RGreenHSV, FGreenHSV, LGreenHSV, DGreenHSV;
//static HSV BOrangeHSV, UOrangeHSV, ROrangeHSV, FOrangeHSV, LOrangeHSV, DOrangeHSV;

////////////////////////////////////////////////////////////////new things////////////////////////////////////////////////////////////////
//

static QMap<QString, QMap<QString, HSV>> map_face_color_hsv;		//���hsv��ֵ���ݵ�Ƕ�� map,���ʷ�ʽΪ map[faceName][colorName]
static QList<QString> list_faceID, list_colorID;					//�����±�list������ͨ������ index ȡ�ö�Ӧ���ַ�����Ϊ map ��keyֵ������ map_face_color_hsv;

static QMap<QString, vector<SamRec>> map_pic_id_samRec;				//��Ų��������ݵ� map ,����ÿ��Ԫ��Ϊ�洢 samRec ���͵�vector����Ӧһ��ͼƬ��18������λ��
QList<QString> list_picID;											//���ڲ�����map���±�list��ͨ������ index ȡ�ö�Ӧ����Ƭ����Ϊ map ��keyֵ������ map_pic_id_samRec

static QMap<QString, vector<QString>> map_face_id_recogRes;			//���ʶ���������ʷ�ʽΪ map[face][blockID]
static QMap<QString, cv::Scalar> map_color_scalar;					//���Ԥ����ɫֵ�����ڻ���ʶ����ͼ
//static vector<cv::Rect> vec_rect_drawResult;						//��ž������ݣ����ڻ���ʶ����ͼ�ĸ���ɫ��

//HSVģ��
void iniHSVMap()
{
	//��ʼ�������洢hsv���ݵ�map��������������Ӧ�Ĵμ���map�����У�������Ϊkey��������
	QMap<QString, HSV> map_color_hsv_f, map_color_hsv_r, map_color_hsv_u, map_color_hsv_b, map_color_hsv_l, map_color_hsv_d;
	map_face_color_hsv.insert("f", map_color_hsv_f);
	map_face_color_hsv.insert("r", map_color_hsv_r);
	map_face_color_hsv.insert("u", map_color_hsv_u);
	map_face_color_hsv.insert("b", map_color_hsv_b);
	map_face_color_hsv.insert("l", map_color_hsv_l);
	map_face_color_hsv.insert("d", map_color_hsv_d);

	list_colorID.append("red_h");	list_faceID.append("u"); 		//��ʼ�������±�list
	list_colorID.append("red_l");	list_faceID.append("r"); 		//
	list_colorID.append("orange");	list_faceID.append("f"); 		//
	list_colorID.append("blue");	list_faceID.append("d"); 		//
	list_colorID.append("green");	list_faceID.append("l"); 		//
	list_colorID.append("yellow");	list_faceID.append("b"); 		//
	list_colorID.append("white");

	//�ӱ����ļ���ȡ�洢��HSV����
	QFile file_hsv(QDir::currentPath() + "/data/hsv_threshold.txt");//��ȡ��ֵ�����ļ��� str_hsvData �Խ��зָ����
	file_hsv.open(QIODevice::ReadWrite);							//
	QTextStream ts(&file_hsv);										//
	QString str_hsvData = ts.readAll();								//


	QList<QString> list_face = str_hsvData.split('~');				//���ȸ��� '~' �ָ�õ���������Ϊ��λ��HSV����
	QList<QString> list_color;
	QList<QString> list_hsv;

	for (int i = 0; i < list_face.length(); i++) {
		list_color = list_face[i].split('-');						//Ȼ����� '-' �ָ�õ���ǰ��(iΪ�±����)������ɫΪ��λ��HSV����
		map_face_color_hsv[list_faceID[i]].clear();
		for (int j = 0; j < list_color.length(); j++) {
			list_hsv = list_color[j].split('_');					//������ '_' �ָ�õ���Ӧ��(iΪ�±�)�ж�Ӧ��ɫ(jΪ�±�)�ĸ���HSV��ֵ

			map_face_color_hsv[list_faceID[i]].insert(				//�� map_face_color_hsv �е�ָ����(list_faceID[i]���key)���һ��HSV����(key��list_colorID[j]��ȡ)
				list_colorID[j], 
				HSV{list_hsv[0].toInt(),list_hsv[1].toInt(),		//iLowH,iHighH
					list_hsv[2].toInt(),list_hsv[3].toInt(),		//iLowS,iHighS
					list_hsv[4].toInt(),list_hsv[5].toInt() });		//iLowV,iHighV
		}
	}

	file_hsv.close();
}

QMap<QString, QMap<QString, HSV>>& getHSVMap() {
	return map_face_color_hsv;
}

void saveHSVData() {
	//����ǰ�� map_face_color_hsv �б��������ת��Ϊ�ַ������浽 "./data/hsv_threshold.txt" �ļ�
	QString data2write;

	QMap<QString, HSV> map_face;
	HSV hsv;

	for (int i = 0; i < map_face_color_hsv.size(); i++) {
		map_face.clear();
		map_face = map_face_color_hsv[list_faceID[i]];						//��ȡ�������hsv����map
		for (int j = 0; j < map_face.size(); j++) {
			hsv = map_face[list_colorID[j]];
			data2write.append(
				QString::number(hsv.iLowH) + "_" + QString::number(hsv.iHighH) + "_" +		//��"iLowH_iHighH_iLowS_iHighS_iLowV_iHighV"�ĸ�ʽ�洢����HSV�ṹ
				QString::number(hsv.iLowS) + "_" + QString::number(hsv.iHighS) + "_" +		//
				QString::number(hsv.iLowV) + "_" + QString::number(hsv.iHighV));			//

			if (j != map_face.size() - 1) data2write.append('-');			//�������һ����ɫ֮�⣬����������һ�� '-' ��Ϊ��ɫ�ķָ�
		}
		if (i != map_face_color_hsv.size() - 1) data2write.append('~');		//�������һ����֮�⣬����������һ�� '~' ��Ϊ��ķָ�
	}

	QFile::remove(QDir::currentPath() + "/data/hsv_threshold.txt");			//ֱ��ɾ��ԭ���������ļ�

	QFile file_hsv(QDir::currentPath() + "/data/hsv_threshold.txt");		//�����������ļ���������
	file_hsv.open(QIODevice::WriteOnly);									//
	QTextStream ts(&file_hsv);												//
	ts << data2write;														//

	file_hsv.close();
}

//������ģ��
void iniRecMap() {
	vector<SamRec> sampleRec_FR, sampleRec_UB, sampleRec_LD;		//�洢������Ƭ�Ĳ�����
	map_pic_id_samRec.insert("FR", sampleRec_FR);
	map_pic_id_samRec.insert("UB", sampleRec_UB);
	map_pic_id_samRec.insert("LD", sampleRec_LD);

	list_picID.append("FR");										//��ʼ��ͼƬ key �±�list��0��Ӧ "FR"
	list_picID.append("UB");										//1��Ӧ "UB"
	list_picID.append("LD");										//2��Ӧ "LD"

	//�ӱ����ļ���ȡ�洢�Ĳ���������
	QFile file_rec(QDir::currentPath() + "/data/sample_rec.txt");	//��ȡ�����������ļ��� str_samRecData �Խ��зָ����
	file_rec.open(QIODevice::ReadWrite);							//
	QTextStream ts(&file_rec);										//
	QString str_samRecData = ts.readAll();							//

	QList<QString> list_pic = str_samRecData.split('~');			//���ȸ��� '~' �ָ�õ�������ͼƬΪ��λ�Ĳ���������
	QList<QString> list_id;
	QList<QString> list_rec;

	for (int i = 0; i < list_pic.length(); i++) {
		list_id = list_pic[i].split('-');							//Ȼ����� '-' �ָ�õ���ǰ��Ƭ��(iΪ�±����)������ƬΪ��λ�Ĳ���������
		map_pic_id_samRec[list_picID[i]].clear();
		for (int j = 0; j < list_id.length(); j++) {
			list_rec = list_id[j].split('_');						//������ '_' �ָ�õ���Ӧ��(jΪ�±�)�еĸ�������������

			map_pic_id_samRec[list_picID[i]].push_back(				//�� map_pic_id_samRec �е�ָ����(list_picID[i]���key)���һ�����������(��˳������)
				SamRec{ list_rec[0].toInt(),						//x1
						list_rec[1].toInt(),						//x2
						list_rec[2].toInt(),						//y1
						list_rec[3].toInt() });						//y2
		}
	}
}

QMap<QString, vector<SamRec>>& getSamRecMap() {
	return map_pic_id_samRec;
}

void setSampleRec(QString strFaceGroup, SamRec rect2set, int nFaceID, int nBlockID) {
	//��ѡ���Ĳ���������Ϊ��Ӧ�桢��ŵĲ�����
	int index = (nFaceID-1) * 9 + nBlockID - 1;					//��ȡ��������ţ�0~17
	map_pic_id_samRec[strFaceGroup][index] = rect2set;

	//���µĲ��������ݱ��浽�ļ� "./data/sample_rec.txt" �ļ�
	QString data2write;
	vector<SamRec> vec_pic;
	SamRec rec;

	for (int i = 0; i < map_pic_id_samRec.size(); i++) {
		vec_pic = map_pic_id_samRec[list_picID[i]];
		for (int j = 0; j < vec_pic.size(); j++) {
			rec = vec_pic[j];
			data2write.append(
				QString::number(rec.x1) + "_" +
				QString::number(rec.x2) + "_" +
				QString::number(rec.y1) + "_" +
				QString::number(rec.y2));

			if (j != vec_pic.size() - 1) data2write.append('-');
		}
		if (i != map_pic_id_samRec.size() - 1) data2write.append('~');
	}

	QFile::remove(QDir::currentPath() + "/data/sample_rec.txt");			//ֱ��ɾ��ԭ���������ļ�

	QFile file_rec(QDir::currentPath() + "/data/sample_rec.txt");		//�����������ļ���������
	file_rec.open(QIODevice::WriteOnly);									//
	QTextStream ts(&file_rec);												//
	ts << data2write;														//

	file_rec.close();
}

//ʶ��ģ��
void iniRecogVars() {
	//��ʼ��ʶ���� map Ϊ 6*9 ��С
	vector<QString> vec_fill;
	vec_fill.resize(9);
	map_face_id_recogRes.insert("f", vec_fill);
	map_face_id_recogRes.insert("r", vec_fill);
	map_face_id_recogRes.insert("u", vec_fill);
	map_face_id_recogRes.insert("b", vec_fill);
	map_face_id_recogRes.insert("l", vec_fill);
	map_face_id_recogRes.insert("d", vec_fill);

	//��ʼ������ʶ����ͼ���õ�Ԥ����ɫ map
	map_color_scalar.insert("red", cv::Scalar(0, 0, 255));
	map_color_scalar.insert("orange", cv::Scalar(0, 165, 255));
	map_color_scalar.insert("blue", cv::Scalar(255, 0, 0));
	map_color_scalar.insert("green", cv::Scalar(0, 255, 0));
	map_color_scalar.insert("yellow", cv::Scalar(0, 255, 255));
	map_color_scalar.insert("white", cv::Scalar(255, 255, 255));
}

int isColor(cv::Mat imgHSV, QString color, QString face)
{
	HSV hsv;
	if (color == "red") hsv = map_face_color_hsv[face]["red_l"];
	else hsv = map_face_color_hsv[face][color];

	cv::Mat imgThresholded;

	cv::inRange(imgHSV, cv::Scalar(hsv.iLowH, hsv.iLowS, hsv.iLowV), cv::Scalar(hsv.iHighH, hsv.iHighS, hsv.iHighV), imgThresholded); //��ֵ������ͼƬ��������ֵ�����ص���ͨ����Ϊȫ255

	int count = 0;
	int totalPixNum = imgThresholded.cols*imgThresholded.rows;

	for (int i = 0; i < imgThresholded.rows; i++) {				//������ֵ��������ͼƬ
		cv::Vec3b *p = imgThresholded.ptr<cv::Vec3b>(i);
		for (int j = 0; j < imgThresholded.cols; j++) {
			if (p[j] == cv::Vec3b{ 255,255,255 })				//�����ǰ����Ϊ(255,255,255)�����������һ
				count++;										//
		}
	}

	if (color == "red") {						//��ɫHSV��ֵ���������䣬��Ҫ�ֱ���м����ۼ�
		hsv = map_face_color_hsv[face]["red_h"];
		cv::inRange(imgHSV, cv::Scalar(hsv.iLowH, hsv.iLowS, hsv.iLowV), cv::Scalar(hsv.iHighH, hsv.iHighS, hsv.iHighV), imgThresholded);
		int count1 = 0;
		for (int i = 0; i < imgThresholded.rows; i++) {				//������ֵ��������ͼƬ
			cv::Vec3b *p = imgThresholded.ptr<cv::Vec3b>(i);
			for (int j = 0; j < imgThresholded.cols; j++) {
				if (p[j] == cv::Vec3b{ 255,255,255 })				//�����ǰ����Ϊ(255,255,255)�����������һ
					count1++;										//
			}
		}
		count += count1;
	}

	if (count > totalPixNum*RECOG_SIMILARITY_COE) return 1;		//������ֵ�����ص���ռ��������Ԥ��ϵ�����ж�ȡɫ��Ϊ��ǰ��ɫ
	return 0;													//�����ж�ȡɫ�鲻�ǵ�ǰ��ɫ
}

void judgeColor(cv::Mat image, QString picName, int caseID) {
	vector<SamRec> vec_samRec1, vec_samRec2;				//�ֱ���picNameָ��ͼƬ��������������Ĳ��������ݣ���С����������kociemba�㷨���Ҫ��
	vector<vector<SamRec>> vec_samRec;						//�ֱ���picNameָ��ͼƬ��������������Ĳ��������ݣ���С����������kociemba�㷨���Ҫ��
	vector<int> vec_specialBlockID;							//�������飨��case1�лᱻ�ڵ��Ŀ죩�����(0~17)
	//���ȸ���kociemba�㷨��ħ���������Ҫ�󣬽���Ӧ��Ĳ���������ŷŵ�vec_samRec��ʱ������
	if (picName == "FR") {
		//F��Ĳ���������
		vec_samRec1.push_back(map_pic_id_samRec["FR"][17]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][16]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][15]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][14]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][13]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][12]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][11]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][10]);
		vec_samRec1.push_back(map_pic_id_samRec["FR"][9]);
		vec_samRec.push_back(vec_samRec1);
		//R��Ĳ���������
		vec_samRec2.push_back(map_pic_id_samRec["FR"][8]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][7]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][6]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][5]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][4]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][3]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][2]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][1]);
		vec_samRec2.push_back(map_pic_id_samRec["FR"][0]);
		vec_samRec.push_back(vec_samRec2);
		
		//F���1�ź�7�ſ����case1�б��ڵ�
		vec_specialBlockID.push_back(1);
		vec_specialBlockID.push_back(7);
	}
	else if (picName == "UB") {
		//U�����������
		vec_samRec1.push_back(map_pic_id_samRec["UB"][2]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][5]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][8]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][1]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][4]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][7]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][0]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][3]);
		vec_samRec1.push_back(map_pic_id_samRec["UB"][6]);
		vec_samRec.push_back(vec_samRec1);
		//B�����������
		vec_samRec2.push_back(map_pic_id_samRec["UB"][15]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][12]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][9]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][16]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][13]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][10]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][17]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][14]);
		vec_samRec2.push_back(map_pic_id_samRec["UB"][11]);
		vec_samRec.push_back(vec_samRec2);

		//U���7�ſ����case1�б��ڵ�
		vec_specialBlockID.push_back(7);
	}
	else if (picName == "LD") {
		//L�����������
		vec_samRec1.push_back(map_pic_id_samRec["LD"][0]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][1]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][2]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][3]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][4]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][5]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][6]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][7]);
		vec_samRec1.push_back(map_pic_id_samRec["LD"][8]);
		vec_samRec.push_back(vec_samRec1);
		//D�����������
		vec_samRec2.push_back(map_pic_id_samRec["LD"][11]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][14]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][17]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][10]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][13]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][16]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][9]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][12]);
		vec_samRec2.push_back(map_pic_id_samRec["LD"][15]);
		vec_samRec.push_back(vec_samRec2);

		//D���1�ſ飨��ͼ��Ϊ10�ſ飩����case1�б��ڵ�
		vec_specialBlockID.push_back(10);
	}

	//Ȼ����ݲ�ͬ��case���в�ͬ��ʶ�𷽰�
	//case1ʱ������special�飬��ʶ��δ���ڵ��Ŀ�
	//case2ʱ������case1�ܹ������ɫ�飬��ʶ��special��
	cv::Mat mat_t, mat_hsv;
	QString faceName;
	vector<SamRec> vec_samRec_t;
	for (int faceID = 0; faceID < 2; faceID++) {
		faceName = picName[faceID].toLower();
		vec_samRec_t = vec_samRec[faceID];
		for (int i = 0; i < vec_samRec_t.size(); i++) {
			//�ж��Ƿ���Ե�ǰɫ�飬�ؼ����������ֻ�����ʹ������case�õ���ͬ�Ľ����
			//case1����ǰ�����������specialBlockID�����У��жϽ��Ϊ 1^0=1��continue���к��ԣ������жϽ��Ϊ 0^0=0
			//case2����ǰ�������������specialBlockID�����У��жϽ��Ϊ 0^1=1��continue���к��ԣ������жϽ��Ϊ 1^1=0
			if (std::find(vec_specialBlockID.cbegin(), vec_specialBlockID.cend(), (faceID * 9 + i)) != vec_specialBlockID.cend() ^ (caseID == 2)) continue;

			//��ȡ�õ��������ڵ�ͼƬ������ת����ʶ��
			mat_t = image(cv::Range(vec_samRec_t[i].y1, vec_samRec_t[i].y2), cv::Range(vec_samRec_t[i].x1, vec_samRec_t[i].x2));			
			cv::cvtColor(mat_t, mat_hsv, cv::COLOR_BGR2HSV);													//ת��ΪHSVͼƬ
			if (isColor(mat_hsv, "red", faceName)) map_face_id_recogRes[faceName][i] = "red";					//��ٷ��жϵ�ǰ��������һ����ɫ
			else if (isColor(mat_hsv, "orange", faceName)) map_face_id_recogRes[faceName][i] = "orange";		//
			else if (isColor(mat_hsv, "blue", faceName)) map_face_id_recogRes[faceName][i] = "blue";			//
			else if (isColor(mat_hsv, "green", faceName)) map_face_id_recogRes[faceName][i] = "green";			//
			else if (isColor(mat_hsv, "yellow", faceName)) map_face_id_recogRes[faceName][i] = "yellow";		//
			else if (isColor(mat_hsv, "white", faceName)) map_face_id_recogRes[faceName][i] = "white";			//
			else map_face_id_recogRes[faceName][i] = "unkown";													//������ٷ�Χ��û���ҵ��������洢Ϊ"unkown"
		}
	}
}

string recognize() {
	//����������ͼƬ���ζ�ȡ������ʶ��ʶ������ŵ� map_face_id_recogRes ��
	cv::Mat image;
	
	image = cv::imread("pic_cam/cam_case1_FR.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	judgeColor(image, "FR", 1);

	image = cv::imread("pic_cam/cam_case1_UB.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	judgeColor(image, "UB", 1);

	image = cv::imread("pic_cam/cam_case1_LD.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	judgeColor(image, "LD", 1);

	image = cv::imread("pic_cam/cam_case2_FR.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	judgeColor(image, "FR", 2);

	image = cv::imread("pic_cam/cam_case2_UB.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	judgeColor(image, "UB", 2);

	image = cv::imread("pic_cam/cam_case2_LD.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	judgeColor(image, "LD", 2);

	//����ʶ��������ʶ����ʾ��ͼ����ŵ������ļ���"./pic_res"
	//����ʶ�����������еõ� kociemba �㷨����Ҫ���ַ������У�U-R-F-D-L-B��
	QString str_res;
	QMap<QString, QString> map_color_face;
	for (int i = 0; i < 6; i++) map_color_face.insert(map_face_id_recogRes[list_faceID[i]][4], list_faceID[i]);		//�洢�������Ŀ���ɫ�����Եõ�ɫ����ţ�U-R-F-D-L-B��

	for (int i = 0; i < map_face_id_recogRes.size(); i++) {
		vector<QString>& vec_res = map_face_id_recogRes[list_faceID[i]]; 
		cv::Mat mat_res(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));
		for (int j = 0; j < vec_res.size(); j++) {
			switch (j) {
			case(0): rectangle(mat_res, cv::Rect(0, 0, 120, 120), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(1): rectangle(mat_res, cv::Rect(120, 0, 240, 120), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(2): rectangle(mat_res, cv::Rect(240, 0, 360, 120), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(3): rectangle(mat_res, cv::Rect(0, 120, 120, 240), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(4): rectangle(mat_res, cv::Rect(120, 120, 240, 240), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(5): rectangle(mat_res, cv::Rect(240, 120, 360, 240), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(6): rectangle(mat_res, cv::Rect(0, 240, 120, 360), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(7): rectangle(mat_res, cv::Rect(120, 240, 240, 360), map_color_scalar[vec_res[j]], -1, 1, 0);
			case(8): rectangle(mat_res, cv::Rect(240, 240, 360, 360), map_color_scalar[vec_res[j]], -1, 1, 0);
			}
			str_res.append(map_color_face[vec_res[j]]);		//�������ڴ�0-8�������м���
		}
		line(mat_res, cv::Point(0, 120), cv::Point(360, 120), cv::Scalar(0, 0, 0), 1, 8, 0);						//���Ʒָ�ɫ��ĺ���
		line(mat_res, cv::Point(0, 240), cv::Point(360, 240), cv::Scalar(0, 0, 0), 1, 8, 0);
		line(mat_res, cv::Point(120, 0), cv::Point(120, 360), cv::Scalar(0, 0, 0), 1, 8, 0);
		line(mat_res, cv::Point(240, 0), cv::Point(240, 360), cv::Scalar(0, 0, 0), 1, 8, 0);

		imwrite("pic_res/res_" + list_faceID[i].toStdString() + ".png", mat_res);
	}

	return str_res.toStdString();
}

//
////////////////////////////////////////////////////////////////new things////////////////////////////////////////////////////////////////

//
//void getHSV(cv::Mat hsv, int x, int y) {
//	cv::Point p(x, y);
//	printf("H=%d\t", hsv.at<cv::Vec3b>(p)[0]);
//	printf("S=%d\t", hsv.at<cv::Vec3b>(p)[1]);
//	printf("V=%d\n", hsv.at<cv::Vec3b>(p)[2]);
//	return;
//}
//
//void PrintHSV(cv::Mat img, string hsv_name) {
//	int i, j;
//	fstream fout;
//	fout.open("pic_hsv\\" + hsv_name + ".txt", ios::out);
//	for (i = 0; i < img.rows; i++) {			//print HSV
//		for (j = 0; j < img.cols; j++) {
//			cv::Point p(i, j);
//			fout << "H=" << int(img.at<cv::Vec3b>(p)[0]) << "\t" << "S=" << int(img.at<cv::Vec3b>(p)[1]) << "\t" << "V=" << int(img.at<cv::Vec3b>(p)[2]) << endl;
//		}
//	}
//	fout.close();
//}
//
//void JudgeColor(cv::Mat &image, cv::Mat& Blank, string ColorName, string CaseName, string color[], vector<SamRec> &Ps) {
//	//resize(image, image, cv::Size(700, 500), 0, 0, 3);			//����ͼƬ��С
//	int i, j;
//
//	//��ɫ��,�����ֲ�������
//	cv::Mat P1, P2, P3, P4, P5, P6, P7, P8, P9;
//	if (ColorName == "U" || ColorName == "D" || ColorName == "F") {
//		P1 = image(cv::Range(Ps[9].y1, Ps[9].y2), cv::Range(Ps[9].x1, Ps[9].x2));
//		P2 = image(cv::Range(Ps[10].y1, Ps[10].y2), cv::Range(Ps[10].x1, Ps[10].x2));
//		P3 = image(cv::Range(Ps[11].y1, Ps[11].y2), cv::Range(Ps[11].x1, Ps[11].x2));
//		P4 = image(cv::Range(Ps[12].y1, Ps[12].y2), cv::Range(Ps[12].x1, Ps[12].x2));
//		P5 = image(cv::Range(Ps[13].y1, Ps[13].y2), cv::Range(Ps[13].x1, Ps[13].x2));
//		P6 = image(cv::Range(Ps[14].y1, Ps[14].y2), cv::Range(Ps[14].x1, Ps[14].x2));
//		P7 = image(cv::Range(Ps[15].y1, Ps[15].y2), cv::Range(Ps[15].x1, Ps[15].x2));
//		P8 = image(cv::Range(Ps[16].y1, Ps[16].y2), cv::Range(Ps[16].x1, Ps[16].x2));
//		P9 = image(cv::Range(Ps[17].y1, Ps[17].y2), cv::Range(Ps[17].x1, Ps[17].x2));
//	}
//	else if (ColorName == "B" || ColorName == "L" || ColorName == "R") {
//		P1 = image(cv::Range(Ps[0].y1, Ps[0].y2), cv::Range(Ps[0].x1, Ps[0].x2));
//		P2 = image(cv::Range(Ps[1].y1, Ps[1].y2), cv::Range(Ps[1].x1, Ps[1].x2));
//		P3 = image(cv::Range(Ps[2].y1, Ps[2].y2), cv::Range(Ps[2].x1, Ps[2].x2));
//		P4 = image(cv::Range(Ps[3].y1, Ps[3].y2), cv::Range(Ps[3].x1, Ps[3].x2));
//		P5 = image(cv::Range(Ps[4].y1, Ps[4].y2), cv::Range(Ps[4].x1, Ps[4].x2));
//		P6 = image(cv::Range(Ps[5].y1, Ps[5].y2), cv::Range(Ps[5].x1, Ps[5].x2));
//		P7 = image(cv::Range(Ps[6].y1, Ps[6].y2), cv::Range(Ps[6].x1, Ps[6].x2));
//		P8 = image(cv::Range(Ps[7].y1, Ps[7].y2), cv::Range(Ps[7].x1, Ps[7].x2));
//		P9 = image(cv::Range(Ps[8].y1, Ps[8].y2), cv::Range(Ps[8].x1, Ps[8].x2));
//	}
//
//	cv::Mat imgHSV[10];
//	//Mat imgThresholded(200, 200, CV_8UC3);
//
//	cvtColor(P1, imgHSV[1], cv::COLOR_BGR2HSV);
//	cvtColor(P2, imgHSV[2], cv::COLOR_BGR2HSV);
//	cvtColor(P3, imgHSV[3], cv::COLOR_BGR2HSV);
//	cvtColor(P4, imgHSV[4], cv::COLOR_BGR2HSV);
//	cvtColor(P5, imgHSV[5], cv::COLOR_BGR2HSV);
//	cvtColor(P6, imgHSV[6], cv::COLOR_BGR2HSV);
//	cvtColor(P7, imgHSV[7], cv::COLOR_BGR2HSV);
//	cvtColor(P8, imgHSV[8], cv::COLOR_BGR2HSV);
//	cvtColor(P9, imgHSV[9], cv::COLOR_BGR2HSV);
//
//	if (CaseName == "case1") {
//		if (ColorName == "B") {
//			for (i = 1; i <= 9; i++) {				//������ɫ��threshold
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "red", "b") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "B") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "B") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "B") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "B") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "B") == 1)
//					color[i] = "White";
//			}
//		}
//		else if (ColorName == "R") {
//			for (i = 1; i <= 9; i++) {				//������ɫ��threshold
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "Red", "R") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "R") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "R") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "R") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "R") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "R") == 1)
//					color[i] = "White";
//			}
//		}
//		else if (ColorName == "D") {
//			for (i = 1; i <= 9; i++) {				//��7��ɫ��threshold
//				if (i == 2 || i == 3)
//					continue;
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "Red", "D") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "D") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "D") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "D") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "D") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "D") == 1)
//					color[i] = "White";
//			}
//		}
//		else if (ColorName == "L") {
//			for (i = 1; i <= 9; i++) {				//������ɫ��threshold
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "Red", "L") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "L") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "L") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "L") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "L") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "L") == 1)
//					color[i] = "White";
//			}
//		}
//		else if (ColorName == "U") {
//			for (i = 1; i <= 9; i++) {				//��8��ɫ����threshold
//				if (i == 8)
//					continue;
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "Red", "U") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "U") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "U") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "U") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "U") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "U") == 1)
//					color[i] = "White";
//			}
//		}
//	}
//	else if (CaseName == "case2") {
//		if (ColorName == "D") {
//			for (i = 1; i <= 9; i++) {				//��2��ɫ��threshold
//				if (i != 2 && i != 3)
//					continue;
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "Red", "D") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "D") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "D") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "D") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "D") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "D") == 1)
//					color[i] = "White";
//			}
//		}
//		else if (ColorName == "F") {
//			for (i = 1; i <= 9; i++) {				//������ɫ��threshold
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "Red", "F") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "F") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "F") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "F") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "F") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "F") == 1)
//					color[i] = "White";
//			}
//		}
//		else if (ColorName == "U") {
//			for (i = 1; i <= 9; i++) {				//��һ��ɫ��threshold
//				if (i != 8)
//					continue;
//				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
//				if (Color(imgHSV[i], "Red", "U") == 1)
//					color[i] = "Red";
//				else if (Color(imgHSV[i], "Orange", "U") == 1)
//					color[i] = "Orange";
//				else if (Color(imgHSV[i], "Yellow", "U") == 1)
//					color[i] = "Yellow";
//				else if (Color(imgHSV[i], "Blue", "U") == 1)
//					color[i] = "Blue";
//				else if (Color(imgHSV[i], "Green", "U") == 1)
//					color[i] = "Green";
//				else if (Color(imgHSV[i], "White", "U") == 1)
//					color[i] = "White";
//			}
//		}
//	}
//
//	for (i = 1; i <= 9; i++)				//ɫ�����
//		FillBlocks(Blank, color[i], i);
//	line(Blank, cv::Point(0, 120), cv::Point(360, 120), cv::Scalar(0, 0, 0), 1, 8, 0);		//���Ʒָ�ɫ��ĺ���
//	line(Blank, cv::Point(0, 240), cv::Point(360, 240), cv::Scalar(0, 0, 0), 1, 8, 0);
//	line(Blank, cv::Point(120, 0), cv::Point(120, 360), cv::Scalar(0, 0, 0), 1, 8, 0);
//	line(Blank, cv::Point(240, 0), cv::Point(240, 360), cv::Scalar(0, 0, 0), 1, 8, 0);
//	for (i = 1; i <= 9; i++)
//		if (color[i] == "")
//			break;				//����δʶ�������ɫ��ʱ������ѭ��
//	if (i > 9)							//ֻ����ȫ��ɫ��ʶ������ű���ʶ����ͼƬ
//		imwrite("pic_res\\res_" + ColorName + ".png", Blank);
//	else
//		cout << "Failed to recognize" + ColorName + "the first time" << endl;	//��ʾһ�£�˵����һ��û��ʶ��ɹ�������ڵ��Ե�ʱ���õõ�
//}
//
//string Print_str(string color[10], vector<string> standardcolor)		//order URFDLB
//{
//	int i;
//	string str;
//	for (i = 1; i <= 9; i++) {
//		if (color[i] == standardcolor[0])
//			str += "U";
//		else if (color[i] == standardcolor[1])
//			str += "R";
//		else if (color[i] == standardcolor[2])
//			str += "F";
//		else if (color[i] == standardcolor[3])
//			str += "D";
//		else if (color[i] == standardcolor[4])
//			str += "L";
//		else if (color[i] == standardcolor[5])
//			str += "B";
//	}
//	return str;
//}
//
//string Recognition() {			//ʶ��ħ��һ�����ɫ�飬�Ӳ�case������������ݲ�ͬ��������ɫ�����λ��Ps
//
//	//vector<cv::Point> center;								//���9��ɫ�������λ��,x��y��δ��������
//
//	//��ʼ��6������
//	cv::Mat B(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//B��
//	cv::Mat D(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//D��
//	cv::Mat F(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//F��
//	cv::Mat L(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//L��
//	cv::Mat R(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//R��
//	cv::Mat U(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//U��
//	int i;
//	cv::Mat image;
//	vector <string> standardcolor;
//	string tmp[6];				//���ܷ��ص��ַ���
//	string color_def;
//
//	Sample_Reset(sampleRec_FR, sampleRec_UB, sampleRec_LD);		// ��ʼ������
//
//	image = cv::imread("pic_cam//cam_case1_UB.png");			//B�����һ��ʶ��ʶ����ͱ���ͼƬ
//	JudgeColor(image, B, "B", "case1", Bcolor, sampleRec_UB);
//
//	image = cv::imread("pic_cam//cam_case1_LD.png");			//��һ��ʶ��
//	JudgeColor(image, D, "D", "case1", Dcolor, sampleRec_LD);
//	image = cv::imread("pic_cam//cam_case2_LD.png");			//���ڶ���ʶ��
//	JudgeColor(image, D, "D", "case2", Dcolor, sampleRec_LD);
//
//
//	image = cv::imread("pic_cam//cam_case2_FR.png");			//һ��ʶ��
//	JudgeColor(image, F, "F", "case2", Fcolor, sampleRec_FR);
//
//
//	image = cv::imread("pic_cam//cam_case1_LD.png");			//LֻҪʶһ��
//	JudgeColor(image, L, "L", "case1", Lcolor, sampleRec_LD);
//
//	image = cv::imread("pic_cam//cam_case1_FR.png");			//RֻҪʶ��һ��
//	JudgeColor(image, R, "R", "case1", Rcolor, sampleRec_FR);
//
//	image = cv::imread("pic_cam//cam_case1_UB.png");
//	JudgeColor(image, U, "U", "case1", Ucolor, sampleRec_UB);
//	image = cv::imread("pic_cam//cam_case2_UB.png");			//���ڶ���ʶ��
//	JudgeColor(image, U, "U", "case2", Ucolor, sampleRec_UB);
//
//
//	//����Ĳ������������ַ���
//	string Ustandard = Ucolor[5];
//	string Rstandard = Rcolor[5];
//	string Fstandard = Fcolor[5];
//	string Dstandard = Dcolor[5];
//	string Lstandard = Lcolor[5];
//	string Bstandard = Bcolor[5];
//	standardcolor.push_back(Ustandard);
//	standardcolor.push_back(Rstandard);
//	standardcolor.push_back(Fstandard);
//	standardcolor.push_back(Dstandard);
//	standardcolor.push_back(Lstandard);
//	standardcolor.push_back(Bstandard);
//
//	tmp[0] = Print_str(Ucolor, standardcolor);
//	tmp[1] = Print_str(Rcolor, standardcolor);
//	tmp[2] = Print_str(Fcolor, standardcolor);
//	tmp[3] = Print_str(Dcolor, standardcolor);
//	tmp[4] = Print_str(Lcolor, standardcolor);
//	tmp[5] = Print_str(Bcolor, standardcolor);
//
//	for (i = 0; i < 6; i++)
//		color_def += tmp[i];
//
//	return color_def;			//��ɫ�ַ���
//}
//
//void Empty_Color(string Bcolor[], string Dcolor[], string Fcolor[], string Lcolor[], string Rcolor[], string Ucolor[])
//{
//	int i;
//	for (i = 0; i <= 9; i++) {
//		Bcolor[i] = "";
//		Dcolor[i] = "";
//		Fcolor[i] = "";
//		Lcolor[i] = "";
//		Rcolor[i] = "";
//		Ucolor[i] = "";
//	}
//}
//
//void Show()
//{
//	cv::Mat image;
//	Sample_Reset(sampleRec_FR, sampleRec_UB, sampleRec_LD);
//
//	image = cv::imread("pic_cam//cam_case1_RF.png");
//	resize(image, image, cv::Size(700, 500), 0, 0, 3);
//	DrawLine(image, "RF", sampleRec_FR, sampleRec_UB, sampleRec_LD);
//	imshow("My_pic_RF", image);
//
//	image = cv::imread("pic_cam//cam_case1_LD.png");
//	resize(image, image, cv::Size(700, 500), 0, 0, 3);
//	DrawLine(image, "LD", sampleRec_FR, sampleRec_UB, sampleRec_LD);
//	imshow("My_pic_LD", image);
//
//	image = cv::imread("pic_cam//cam_case1_BU.png");
//	resize(image, image, cv::Size(700, 500), 0, 0, 3);
//	DrawLine(image, "BU", sampleRec_FR, sampleRec_UB, sampleRec_LD);
//	imshow("My_pic_BU", image);
//
//	cv::waitKey(0);
//}
//
//void DrawLine(cv::Mat image, string c, vector<SamRec> &Sample_RF, vector<SamRec> &Sample_BU, vector<SamRec> &Sample_LD)
//{
//	int i;
//	cv::Point p1, p2;
//	if (c == "RF") {
//		for (i = 0; i < 18; i++) {
//			p1.x = Sample_RF[i].x1;
//			p1.y = Sample_RF[i].y1;
//			p2.x = Sample_RF[i].x2;
//			p2.y = Sample_RF[i].y2;
//			line(image, p1, p2, cv::Scalar(0, 0, 0), 2);
//		}
//	}
//	else if (c == "LD") {
//		for (i = 0; i < 18; i++) {
//			p1.x = Sample_LD[i].x1;
//			p1.y = Sample_LD[i].y1;
//			p2.x = Sample_LD[i].x2;
//			p2.y = Sample_LD[i].y2;
//			line(image, p1, p2, cv::Scalar(0, 0, 0), 2);
//		}
//	}
//	else if (c == "BU") {
//		for (i = 0; i < 18; i++) {
//			p1.x = Sample_BU[i].x1;
//			p1.y = Sample_BU[i].y1;
//			p2.x = Sample_BU[i].x2;
//			p2.y = Sample_BU[i].y2;
//			line(image, p1, p2, cv::Scalar(0, 0, 0), 2);
//		}
//	}
//}
