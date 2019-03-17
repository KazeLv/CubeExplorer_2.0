#include "CubeRecognizer.h"

static const cv::Scalar Red(0, 0, 255);			//魔方六个颜色定义，用于绘制识别结果
static const cv::Scalar White(255, 255, 255);
static const cv::Scalar Yellow(0, 255, 255);
static const cv::Scalar Blue(255, 0, 0);
static const cv::Scalar Green(0, 255, 0);
static const cv::Scalar Orange(0, 165, 255);

//B D F L R U
SamRec P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18;			//每张图片都对应18个采样的位置

static vector<SamRec> sampleRec_FR, sampleRec_UB, sampleRec_LD;	//存储三张照片的采样框
static string Bcolor[10];				//识别结果
static string Dcolor[10];				//
static string Fcolor[10];				//
static string Lcolor[10];				//
static string Rcolor[10];				//
static string Ucolor[10];				//
static HSV BWhiteHSV, UWhiteHSV, RWhiteHSV, FWhiteHSV, LWhiteHSV, DWhiteHSV;
static HSV BRedHSV_L, URedHSV_L, RRedHSV_L, FRedHSV_L, LRedHSV_L, DRedHSV_L;
static HSV BRedHSV_H, URedHSV_H, RRedHSV_H, FRedHSV_H, LRedHSV_H, DRedHSV_H;
static HSV BYellowHSV, UYellowHSV, RYellowHSV, FYellowHSV, LYellowHSV, DYellowHSV;
static HSV BBlueHSV, UBlueHSV, RBlueHSV, FBlueHSV, LBlueHSV, DBlueHSV;
static HSV BGreenHSV, UGreenHSV, RGreenHSV, FGreenHSV, LGreenHSV, DGreenHSV;
static HSV BOrangeHSV, UOrangeHSV, ROrangeHSV, FOrangeHSV, LOrangeHSV, DOrangeHSV;

////////////////////////////////////////////////////////////////new things////////////////////////////////////////////////////////////////
//

static QMap<QString, QMap<QString, HSV>> map_face_color_hsv;		//存放hsv阈值数据的嵌套 map,访问方式为 map[faceName][colorName]
static QList<QString> list_faceID, list_colorID;					//两个下标list，用于通过整数 index 取得对应的字符串作为 map 的key值来访问 map_face_color_hsv;

static QMap<QString, vector<SamRec>> map_pic_id_samRec;				//存放采样框数据的 map ,其中每个元素为存储 samRec 类型的vector，对应一张图片的18个采样位置
static QList<QString> list_picID;									//用于采样框map的下标list，通过整数 index 取得对应的照片名作为 map 的key值来访问 map_pic_id_samRec

void iniHSVMap()
{
	//初始化整个存储hsv数据的map，先添加六个面对应的次级空map到其中，以面名为key进行索引
	QMap<QString, HSV> map_color_hsv_f, map_color_hsv_r, map_color_hsv_u, map_color_hsv_b, map_color_hsv_l, map_color_hsv_d;
	map_face_color_hsv.insert("f", map_color_hsv_f);
	map_face_color_hsv.insert("r", map_color_hsv_r);
	map_face_color_hsv.insert("u", map_color_hsv_u);
	map_face_color_hsv.insert("b", map_color_hsv_b);
	map_face_color_hsv.insert("l", map_color_hsv_l);
	map_face_color_hsv.insert("d", map_color_hsv_d);

	list_faceID.append("f"); list_colorID.append("red");			//初始化两个下标list
	list_faceID.append("r"); list_colorID.append("orange");			//
	list_faceID.append("u"); list_colorID.append("blue");			//
	list_faceID.append("b"); list_colorID.append("green");			//
	list_faceID.append("l"); list_colorID.append("yellow");			//
	list_faceID.append("d"); list_colorID.append("white");			//

	//从本地文件读取存储的HSV数据
	QFile file_hsv(QDir::currentPath() + "/data/hsv_threshold.txt");//读取阈值数据文件到 str_hsvData 以进行分割、遍历
	file_hsv.open(QIODevice::ReadWrite);							//
	QTextStream ts(&file_hsv);										//
	QString str_hsvData = ts.readAll();								//


	QList<QString> list_face = str_hsvData.split('~');				//首先根据 '~' 分割得到六个以面为单位的HSV数据
	QList<QString> list_color;
	QList<QString> list_hsv;

	for (int i = 0; i < list_face.length(); i++) {
		list_color = list_face[i].split('-');						//然后根据 '-' 分割得到当前面(i为下标遍历)中以颜色为单位的HSV数据
		map_face_color_hsv[list_faceID[i]].clear();
		for (int j = 0; j < list_color.length(); j++) {
			list_hsv = list_color[j].split('_');					//最后根据 '_' 分割得到对应面(i为下标)中对应颜色(j为下标)的各个HSV阈值

			map_face_color_hsv[list_faceID[i]].insert(				//在 map_face_color_hsv 中的指定面(list_faceID[i]获得key)添加一组HSV数据(key由list_colorID[j]获取)
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
	//将当前的 map_face_color_hsv 中保存的数据转换为字符串保存到 "./data/hsv_threshold.txt" 文件
	QString data2write;

	QMap<QString, HSV> map_face;
	HSV hsv;

	for (int i = 0; i < map_face_color_hsv.size(); i++) {
		map_face.clear();
		map_face = map_face_color_hsv[list_faceID[i]];						//获取各个面的hsv数据map
		for (int j = 0; j < map_face.size(); j++) {
			hsv = map_face[list_colorID[j]];
			data2write.append(
				QString(hsv.iLowH) + "_" + QString(hsv.iHighH) + "_" +		//以"iLowH_iHighH_iLowS_iHighS_iLowV_iHighV"的格式存储单个HSV结构
				QString(hsv.iLowS) + "_" + QString(hsv.iHighS) + "_" +		//
				QString(hsv.iLowV) + "_" + QString(hsv.iHighV));			//

			if (j != map_face.size() - 1) data2write.append('-');			//除了最后一个颜色之外，都在其后添加一个 '-' 作为颜色的分割
		}
		if (i != map_face_color_hsv.size() - 1) data2write.append('~');		//除了最后一个面之外，都在其后添加一个 '~' 作为面的分割
	}

	QFile::remove(QDir::currentPath() + "/data/hsv_threshold.txt");			//直接删除原来的数据文件

	QFile file_hsv(QDir::currentPath() + "/data/hsv_threshold.txt");		//创建并打开新文件进行输入
	file_hsv.open(QIODevice::WriteOnly);									//
	QTextStream ts(&file_hsv);												//
	ts << data2write;														//

	file_hsv.close();
}

void iniRecMap() {
	vector<SamRec> sampleRec_FR, sampleRec_UB, sampleRec_LD;		//存储三张照片的采样框
	map_pic_id_samRec.insert("FR", sampleRec_FR);
	map_pic_id_samRec.insert("UB", sampleRec_UB);
	map_pic_id_samRec.insert("LD", sampleRec_LD);

	list_picID.append("FR");										//初始化图片 key 下标list，0对应 "fr"
	list_picID.append("UB");										//1对应 "ub"
	list_picID.append("LD");										//2对应 "ld"

	//从本地文件读取存储的采样框数据
	QFile file_rec(QDir::currentPath() + "/data/sample_rec.txt");	//读取采样框数据文件到 str_samRecData 以进行分割、遍历
	file_rec.open(QIODevice::ReadWrite);							//
	QTextStream ts(&file_rec);										//
	QString str_samRecData = ts.readAll();							//

	QList<QString> list_pic = str_samRecData.split('~');			//首先根据 '~' 分割得到三个以图片为单位的采样框数据
	QList<QString> list_id;
	QList<QString> list_rec;

	for (int i = 0; i < list_pic.length(); i++) {
		list_id = list_pic[i].split('-');							//然后根据 '-' 分割得到当前照片名(i为下标遍历)中以照片为单位的采样框数据
		map_pic_id_samRec[list_picID[i]].clear();
		for (int j = 0; j < list_id.length(); j++) {
			list_rec = list_id[j].split('_');						//最后根据 '_' 分割得到对应面(j为下标)中的各个采样框数据

			map_pic_id_samRec[list_picID[i]].push_back(				//在 map_pic_id_samRec 中的指定面(list_picID[i]获得key)添加一组采样框数据(按顺序排序)
				SamRec{ list_rec[0].toInt(),						//x1
						list_rec[1].toInt(),						//x2
						list_rec[2].toInt(),						//y1
						list_rec[3].toInt() });						//y2
		}
	}
}

void setSampleRec(QString strFaceGroup, SamRec rect2set, int nFaceID, int nBlockID) {
	//将选定的采样框设置为对应面、序号的采样框
	int index = (nFaceID-1) * 9 + nBlockID - 1;					//获取采样框序号，0~17
	map_pic_id_samRec[strFaceGroup][index] = rect2set;

	//将新的采样框数据保存到文件 "./data/sample_rec.txt" 文件
	QString data2write;
	vector<SamRec> vec_pic;
	SamRec rec;

	for (int i = 0; i < map_pic_id_samRec.size(); i++) {
		vec_pic = map_pic_id_samRec[list_picID[i]];
		for (int j = 0; j < vec_pic.size(); j++) {
			rec = vec_pic[j];
			data2write.append(
				QString(rec.x1) + "_" +
				QString(rec.x2) + "_" +
				QString(rec.y1) + "_" +
				QString(rec.y2));

			if (j != vec_pic.size() - 1) data2write.append('-');
		}
		if (i != map_pic_id_samRec.size() - 1) data2write.append('~');
	}

	QFile::remove(QDir::currentPath() + "/data/sample_rec.txt");			//直接删除原来的数据文件

	QFile file_rec(QDir::currentPath() + "/data/sample_rec.txt");		//创建并打开新文件进行输入
	file_rec.open(QIODevice::WriteOnly);									//
	QTextStream ts(&file_rec);												//
	ts << data2write;														//

	file_rec.close();
}

//
////////////////////////////////////////////////////////////////new things////////////////////////////////////////////////////////////////

void ColorTest(cv::Mat imgHSV, string c)
{
	int iLowH, iHighH;
	int iLowS, iHighS;
	int iLowV, iHighV;
	cv::Mat imgThresholded;
	cv::Vec3b pixel;
	pixel[0] = pixel[1] = pixel[2] = 255;

	if (c == "White") {
		iLowH = 10;
		iHighH = 50;

		iLowS = 0;
		iHighS = 20;

		iLowV = 220;
		iHighV = 255;
	}
	else if (c == "Red") {
		iLowH = 156;
		iHighH = 180;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Yellow") {
		iLowH = 26;
		iHighH = 34;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Blue") {
		iLowH = 100;
		iHighH = 115;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Green") {
		iLowH = 50;
		iHighH = 70;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Orange") {
		iLowH = 0;
		iHighH = 10;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}

	cv::inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the imageq
	imwrite("threstest.png", imgThresholded);
	int count = 0;
	int i, j;

	for (i = 0; i < imgThresholded.rows; i++) {
		cv::Vec3b *p = imgThresholded.ptr<cv::Vec3b>(i);
		for (j = 0; j < imgThresholded.cols; j++)
			if (p[j] == pixel)
				count++;
	}

	cout << count << endl;

}

int Color(cv::Mat imgHSV, string c, string Face)
{
	int iLowH, iHighH;
	int iLowS, iHighS;
	int iLowV, iHighV;
	int i, j;
	cv::Mat imgThresholded;
	cv::Vec3b pixel;
	pixel[0] = pixel[1] = pixel[2] = 255;
	iLowH = 0;
	iHighH = 180;

	iLowS = 0;
	iHighS = 30;

	iLowV = 220;
	iHighV = 255;

	if (c == "White") {
		if (Face == "B") {
			iLowH = BWhiteHSV.iLowH;
			iHighH = BWhiteHSV.iHighH;

			iLowS = BWhiteHSV.iLowS;
			iHighS = BWhiteHSV.iHighS;

			iLowV = BWhiteHSV.iLowV;
			iHighV = BWhiteHSV.iHighV;
		}
		else if (Face == "U") {
			iLowH = UWhiteHSV.iLowH;
			iHighH = UWhiteHSV.iHighH;

			iLowS = UWhiteHSV.iLowS;
			iHighS = UWhiteHSV.iHighS;

			iLowV = UWhiteHSV.iLowV;
			iHighV = UWhiteHSV.iHighV;
		}
		else if (Face == "R") {
			iLowH = RWhiteHSV.iLowH;
			iHighH = RWhiteHSV.iHighH;

			iLowS = RWhiteHSV.iLowS;
			iHighS = RWhiteHSV.iHighS;

			iLowV = RWhiteHSV.iLowV;
			iHighV = RWhiteHSV.iHighV;
		}
		else if (Face == "F") {
			iLowH = FWhiteHSV.iLowH;
			iHighH = FWhiteHSV.iHighH;

			iLowS = FWhiteHSV.iLowS;
			iHighS = FWhiteHSV.iHighS;

			iLowV = FWhiteHSV.iLowV;
			iHighV = FWhiteHSV.iHighV;
		}
		else if (Face == "L") {
			iLowH = LWhiteHSV.iLowH;
			iHighH = LWhiteHSV.iHighH;

			iLowS = LWhiteHSV.iLowS;
			iHighS = LWhiteHSV.iHighS;

			iLowV = LWhiteHSV.iLowV;
			iHighV = LWhiteHSV.iHighV;
		}
		else if (Face == "D") {
			iLowH = DWhiteHSV.iLowH;
			iHighH = DWhiteHSV.iHighH;

			iLowS = DWhiteHSV.iLowS;
			iHighS = DWhiteHSV.iHighS;

			iLowV = DWhiteHSV.iLowV;
			iHighV = DWhiteHSV.iHighV;
		}
	}
	else if (c == "Red") {
		if (Face == "B") {
			iLowH = BRedHSV_L.iLowH;
			iHighH = BRedHSV_L.iHighH;

			iLowS = BRedHSV_L.iLowS;
			iHighS = BRedHSV_L.iHighS;

			iLowV = BRedHSV_L.iLowV;
			iHighV = BRedHSV_L.iHighV;
		}
		else if (Face == "U") {
			iLowH = URedHSV_L.iLowH;
			iHighH = URedHSV_L.iHighH;

			iLowS = URedHSV_L.iLowS;
			iHighS = URedHSV_L.iHighS;

			iLowV = URedHSV_L.iLowV;
			iHighV = URedHSV_L.iHighV;
		}
		else if (Face == "R") {
			iLowH = RRedHSV_L.iLowH;
			iHighH = RRedHSV_L.iHighH;

			iLowS = RRedHSV_L.iLowS;
			iHighS = RRedHSV_L.iHighS;

			iLowV = RRedHSV_L.iLowV;
			iHighV = RRedHSV_L.iHighV;
		}
		else if (Face == "F") {
			iLowH = FRedHSV_L.iLowH;
			iHighH = FRedHSV_L.iHighH;

			iLowS = FRedHSV_L.iLowS;
			iHighS = FRedHSV_L.iHighS;

			iLowV = FRedHSV_L.iLowV;
			iHighV = FRedHSV_L.iHighV;
		}
		else if (Face == "L") {
			iLowH = LRedHSV_L.iLowH;
			iHighH = LRedHSV_L.iHighH;

			iLowS = LRedHSV_L.iLowS;
			iHighS = LRedHSV_L.iHighS;

			iLowV = LRedHSV_L.iLowV;
			iHighV = LRedHSV_L.iHighV;
		}
		else if (Face == "D") {
			iLowH = DRedHSV_L.iLowH;
			iHighH = DRedHSV_L.iHighH;

			iLowS = DRedHSV_L.iLowS;
			iHighS = DRedHSV_L.iHighS;

			iLowV = DRedHSV_L.iLowV;
			iHighV = DRedHSV_L.iHighV;
		}
	}
	else if (c == "Yellow") {
		if (Face == "B") {
			iLowH = BYellowHSV.iLowH;
			iHighH = BYellowHSV.iHighH;

			iLowS = BYellowHSV.iLowS;
			iHighS = BYellowHSV.iHighS;

			iLowV = BYellowHSV.iLowV;
			iHighV = BYellowHSV.iHighV;
		}
		else if (Face == "U") {
			iLowH = UYellowHSV.iLowH;
			iHighH = UYellowHSV.iHighH;

			iLowS = UYellowHSV.iLowS;
			iHighS = UYellowHSV.iHighS;

			iLowV = UYellowHSV.iLowV;
			iHighV = UYellowHSV.iHighV;
		}
		else if (Face == "R") {
			iLowH = RYellowHSV.iLowH;
			iHighH = RYellowHSV.iHighH;

			iLowS = RYellowHSV.iLowS;
			iHighS = RYellowHSV.iHighS;

			iLowV = RYellowHSV.iLowV;
			iHighV = RYellowHSV.iHighV;
		}
		else if (Face == "F") {
			iLowH = FYellowHSV.iLowH;
			iHighH = FYellowHSV.iHighH;

			iLowS = FYellowHSV.iLowS;
			iHighS = FYellowHSV.iHighS;

			iLowV = FYellowHSV.iLowV;
			iHighV = FYellowHSV.iHighV;
		}
		else if (Face == "L") {
			iLowH = LYellowHSV.iLowH;
			iHighH = LYellowHSV.iHighH;

			iLowS = LYellowHSV.iLowS;
			iHighS = LYellowHSV.iHighS;

			iLowV = LYellowHSV.iLowV;
			iHighV = LYellowHSV.iHighV;
		}
		else if (Face == "D") {
			iLowH = DYellowHSV.iLowH;
			iHighH = DYellowHSV.iHighH;

			iLowS = DYellowHSV.iLowS;
			iHighS = DYellowHSV.iHighS;

			iLowV = DYellowHSV.iLowV;
			iHighV = DYellowHSV.iHighV;
		}
	}
	else if (c == "Blue") {
		if (Face == "B") {
			iLowH = BBlueHSV.iLowH;
			iHighH = BBlueHSV.iHighH;

			iLowS = BBlueHSV.iLowS;
			iHighS = BBlueHSV.iHighS;

			iLowV = BBlueHSV.iLowV;
			iHighV = BBlueHSV.iHighV;
		}
		else if (Face == "U") {
			iLowH = UBlueHSV.iLowH;
			iHighH = UBlueHSV.iHighH;

			iLowS = UBlueHSV.iLowS;
			iHighS = UBlueHSV.iHighS;

			iLowV = UBlueHSV.iLowV;
			iHighV = UBlueHSV.iHighV;
		}
		else if (Face == "R") {
			iLowH = RBlueHSV.iLowH;
			iHighH = RBlueHSV.iHighH;

			iLowS = RBlueHSV.iLowS;
			iHighS = RBlueHSV.iHighS;

			iLowV = RBlueHSV.iLowV;
			iHighV = RBlueHSV.iHighV;
		}
		else if (Face == "F") {
			iLowH = FBlueHSV.iLowH;
			iHighH = FBlueHSV.iHighH;

			iLowS = FBlueHSV.iLowS;
			iHighS = FBlueHSV.iHighS;

			iLowV = FBlueHSV.iLowV;
			iHighV = FBlueHSV.iHighV;
		}
		else if (Face == "L") {
			iLowH = LBlueHSV.iLowH;
			iHighH = LBlueHSV.iHighH;

			iLowS = LBlueHSV.iLowS;
			iHighS = LBlueHSV.iHighS;

			iLowV = LBlueHSV.iLowV;
			iHighV = LBlueHSV.iHighV;
		}
		else if (Face == "D") {
			iLowH = DBlueHSV.iLowH;
			iHighH = DBlueHSV.iHighH;

			iLowS = DBlueHSV.iLowS;
			iHighS = DBlueHSV.iHighS;

			iLowV = DBlueHSV.iLowV;
			iHighV = DBlueHSV.iHighV;
		}
	}
	else if (c == "Green") {
		if (Face == "B") {
			iLowH = BGreenHSV.iLowH;
			iHighH = BGreenHSV.iHighH;

			iLowS = BGreenHSV.iLowS;
			iHighS = BGreenHSV.iHighS;

			iLowV = BGreenHSV.iLowV;
			iHighV = BGreenHSV.iHighV;
		}
		else if (Face == "U") {
			iLowH = UGreenHSV.iLowH;
			iHighH = UGreenHSV.iHighH;

			iLowS = UGreenHSV.iLowS;
			iHighS = UGreenHSV.iHighS;

			iLowV = UGreenHSV.iLowV;
			iHighV = UGreenHSV.iHighV;
		}
		else if (Face == "R") {
			iLowH = RGreenHSV.iLowH;
			iHighH = RGreenHSV.iHighH;

			iLowS = RGreenHSV.iLowS;
			iHighS = RGreenHSV.iHighS;

			iLowV = RGreenHSV.iLowV;
			iHighV = RGreenHSV.iHighV;
		}
		else if (Face == "F") {
			iLowH = FGreenHSV.iLowH;
			iHighH = FGreenHSV.iHighH;

			iLowS = FGreenHSV.iLowS;
			iHighS = FGreenHSV.iHighS;

			iLowV = FGreenHSV.iLowV;
			iHighV = FGreenHSV.iHighV;
		}
		else if (Face == "L") {
			iLowH = LGreenHSV.iLowH;
			iHighH = LGreenHSV.iHighH;

			iLowS = LGreenHSV.iLowS;
			iHighS = LGreenHSV.iHighS;

			iLowV = LGreenHSV.iLowV;
			iHighV = LGreenHSV.iHighV;
		}
		else if (Face == "D") {
			iLowH = DGreenHSV.iLowH;
			iHighH = DGreenHSV.iHighH;

			iLowS = DGreenHSV.iLowS;
			iHighS = DGreenHSV.iHighS;

			iLowV = DGreenHSV.iLowV;
			iHighV = DGreenHSV.iHighV;
		}
	}
	else if (c == "Orange") {
		if (Face == "B") {
			iLowH = BOrangeHSV.iLowH;
			iHighH = BOrangeHSV.iHighH;

			iLowS = BOrangeHSV.iLowS;
			iHighS = BOrangeHSV.iHighS;

			iLowV = BOrangeHSV.iLowV;
			iHighV = BOrangeHSV.iHighV;
		}
		else if (Face == "U") {
			iLowH = UOrangeHSV.iLowH;
			iHighH = UOrangeHSV.iHighH;

			iLowS = UOrangeHSV.iLowS;
			iHighS = UOrangeHSV.iHighS;

			iLowV = UOrangeHSV.iLowV;
			iHighV = UOrangeHSV.iHighV;
		}
		else if (Face == "R") {
			iLowH = ROrangeHSV.iLowH;
			iHighH = ROrangeHSV.iHighH;

			iLowS = ROrangeHSV.iLowS;
			iHighS = ROrangeHSV.iHighS;

			iLowV = ROrangeHSV.iLowV;
			iHighV = ROrangeHSV.iHighV;
		}
		else if (Face == "F") {
			iLowH = FOrangeHSV.iLowH;
			iHighH = FOrangeHSV.iHighH;

			iLowS = FOrangeHSV.iLowS;
			iHighS = FOrangeHSV.iHighS;

			iLowV = FOrangeHSV.iLowV;
			iHighV = FOrangeHSV.iHighV;
		}
		else if (Face == "L") {
			iLowH = LOrangeHSV.iLowH;
			iHighH = LOrangeHSV.iHighH;

			iLowS = LOrangeHSV.iLowS;
			iHighS = LOrangeHSV.iHighS;

			iLowV = LOrangeHSV.iLowV;
			iHighV = LOrangeHSV.iHighV;
		}
		else if (Face == "D") {
			iLowH = DOrangeHSV.iLowH;
			iHighH = DOrangeHSV.iHighH;

			iLowS = DOrangeHSV.iLowS;
			iHighS = DOrangeHSV.iHighS;

			iLowV = DOrangeHSV.iLowV;
			iHighV = DOrangeHSV.iHighV;
		}
	}

	// PrintHSV(imgHSV);

	cv::inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

	int count = 0;
	int totalPixNum = imgThresholded.cols*imgThresholded.rows;

	for (i = 0; i < imgThresholded.rows; i++) {
		cv::Vec3b *p = imgThresholded.ptr<cv::Vec3b>(i);
		for (j = 0; j < imgThresholded.cols; j++) {
			//cout << p[j] << endl;
			if (p[j] == pixel)
				count++;
		}
	}

	if (c == "Red") {
		if (Face == "B") {
			iLowH = BRedHSV_H.iLowH;
			iHighH = BRedHSV_H.iHighH;

			iLowS = BRedHSV_H.iLowS;
			iHighS = BRedHSV_H.iHighS;

			iLowV = BRedHSV_H.iLowV;
			iHighV = BRedHSV_H.iHighV;
		}
		else if (Face == "U") {
			iLowH = URedHSV_H.iLowH;
			iHighH = URedHSV_H.iHighH;

			iLowS = URedHSV_H.iLowS;
			iHighS = URedHSV_H.iHighS;

			iLowV = URedHSV_H.iLowV;
			iHighV = URedHSV_H.iHighV;
		}
		else if (Face == "R") {
			iLowH = RRedHSV_H.iLowH;
			iHighH = RRedHSV_H.iHighH;

			iLowS = RRedHSV_H.iLowS;
			iHighS = RRedHSV_H.iHighS;

			iLowV = RRedHSV_H.iLowV;
			iHighV = RRedHSV_H.iHighV;
		}
		else if (Face == "F") {
			iLowH = FRedHSV_H.iLowH;
			iHighH = FRedHSV_H.iHighH;

			iLowS = FRedHSV_H.iLowS;
			iHighS = FRedHSV_H.iHighS;

			iLowV = FRedHSV_H.iLowV;
			iHighV = FRedHSV_H.iHighV;
		}
		else if (Face == "L") {
			iLowH = LRedHSV_H.iLowH;
			iHighH = LRedHSV_H.iHighH;

			iLowS = LRedHSV_H.iLowS;
			iHighS = LRedHSV_H.iHighS;

			iLowV = LRedHSV_H.iLowV;
			iHighV = LRedHSV_H.iHighV;
		}
		else if (Face == "D") {
			iLowH = DRedHSV_H.iLowH;
			iHighH = DRedHSV_H.iHighH;

			iLowS = DRedHSV_H.iLowS;
			iHighS = DRedHSV_H.iHighS;

			iLowV = DRedHSV_H.iLowV;
			iHighV = DRedHSV_H.iHighV;
		}
		cv::inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
		int count2 = 0;
		for (i = 0; i < imgThresholded.rows; i++) {
			cv::Vec3b *p = imgThresholded.ptr<cv::Vec3b>(i);
			for (j = 0; j < imgThresholded.cols; j++) {
				if (p[j] == pixel)
					count2++;
			}
		}
		count += count2;
	}

	if (count > totalPixNum*RECOG_SIMILARITY_COE) return 1;		//符合阈值的像素点所占比例大于预设系数，判定取色块为当前颜色
	return 0;													//否则，判定取色块不是当前颜色
}

void FillBlocks(cv::Mat& A, string color, int num)			//num表示第几个色块
{
	switch (num) {
	case(1):					//第一个色块
		if (color == "White")
			rectangle(A, cv::Rect(0, 0, 120, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(0, 0, 120, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(0, 0, 120, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(0, 0, 120, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(0, 0, 120, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(0, 0, 120, 120), Orange, -1, 1, 0);
	case(2):
		if (color == "White")
			rectangle(A, cv::Rect(120, 0, 240, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(120, 0, 240, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(120, 0, 240, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(120, 0, 240, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(120, 0, 240, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(120, 0, 240, 120), Orange, -1, 1, 0);
	case(3):
		if (color == "White")
			rectangle(A, cv::Rect(240, 0, 360, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(240, 0, 360, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(240, 0, 360, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(240, 0, 360, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(240, 0, 360, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(240, 0, 360, 120), Orange, -1, 1, 0);
	case(4):
		if (color == "White")
			rectangle(A, cv::Rect(0, 120, 120, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(0, 120, 120, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(0, 120, 120, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(0, 120, 120, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(0, 120, 120, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(0, 120, 120, 240), Orange, -1, 1, 0);
	case(5):
		if (color == "White")
			rectangle(A, cv::Rect(120, 120, 240, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(120, 120, 240, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(120, 120, 240, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(120, 120, 240, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(120, 120, 240, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(120, 120, 240, 240), Orange, -1, 1, 0);
	case(6):
		if (color == "White")
			rectangle(A, cv::Rect(240, 120, 360, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(240, 120, 360, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(240, 120, 360, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(240, 120, 360, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(240, 120, 360, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(240, 120, 360, 240), Orange, -1, 1, 0);
	case(7):
		if (color == "White")
			rectangle(A, cv::Rect(0, 240, 120, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(0, 240, 120, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(0, 240, 120, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(0, 240, 120, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(0, 240, 120, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(0, 240, 120, 360), Orange, -1, 1, 0);
	case(8):
		if (color == "White")
			rectangle(A, cv::Rect(120, 240, 240, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(120, 240, 240, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(120, 240, 240, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(120, 240, 240, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(120, 240, 240, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(120, 240, 240, 360), Orange, -1, 1, 0);
	case(9):
		if (color == "White")
			rectangle(A, cv::Rect(240, 240, 360, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, cv::Rect(240, 240, 360, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, cv::Rect(240, 240, 360, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, cv::Rect(240, 240, 360, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, cv::Rect(240, 240, 360, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, cv::Rect(240, 240, 360, 360), Orange, -1, 1, 0);
	default:
		;
	}
}

void getHSV(cv::Mat hsv, int x, int y) {
	cv::Point p(x, y);
	printf("H=%d\t", hsv.at<cv::Vec3b>(p)[0]);
	printf("S=%d\t", hsv.at<cv::Vec3b>(p)[1]);
	printf("V=%d\n", hsv.at<cv::Vec3b>(p)[2]);
	return;
}

void PrintHSV(cv::Mat img, string hsv_name) {
	int i, j;
	fstream fout;
	fout.open("pic_hsv\\" + hsv_name + ".txt", ios::out);
	for (i = 0; i < img.rows; i++) {			//print HSV
		for (j = 0; j < img.cols; j++) {
			cv::Point p(i, j);
			fout << "H=" << int(img.at<cv::Vec3b>(p)[0]) << "\t" << "S=" << int(img.at<cv::Vec3b>(p)[1]) << "\t" << "V=" << int(img.at<cv::Vec3b>(p)[2]) << endl;
		}
	}
	fout.close();
}

void JudgeColor(cv::Mat &image, cv::Mat& Blank, string ColorName, string CaseName, string color[], vector<SamRec> &Ps) {
	resize(image, image, cv::Size(700, 500), 0, 0, 3);			//调整图片大小
	int i, j;

	//采色块,，两种采样方法
	cv::Mat P1, P2, P3, P4, P5, P6, P7, P8, P9;
	if (ColorName == "U" || ColorName == "D" || ColorName == "F") {
		P1 = image(cv::Range(Ps[9].y1, Ps[9].y2), cv::Range(Ps[9].x1, Ps[9].x2));
		P2 = image(cv::Range(Ps[10].y1, Ps[10].y2), cv::Range(Ps[10].x1, Ps[10].x2));
		P3 = image(cv::Range(Ps[11].y1, Ps[11].y2), cv::Range(Ps[11].x1, Ps[11].x2));
		P4 = image(cv::Range(Ps[12].y1, Ps[12].y2), cv::Range(Ps[12].x1, Ps[12].x2));
		P5 = image(cv::Range(Ps[13].y1, Ps[13].y2), cv::Range(Ps[13].x1, Ps[13].x2));
		P6 = image(cv::Range(Ps[14].y1, Ps[14].y2), cv::Range(Ps[14].x1, Ps[14].x2));
		P7 = image(cv::Range(Ps[15].y1, Ps[15].y2), cv::Range(Ps[15].x1, Ps[15].x2));
		P8 = image(cv::Range(Ps[16].y1, Ps[16].y2), cv::Range(Ps[16].x1, Ps[16].x2));
		P9 = image(cv::Range(Ps[17].y1, Ps[17].y2), cv::Range(Ps[17].x1, Ps[17].x2));
	}
	else if (ColorName == "B" || ColorName == "L" || ColorName == "R") {
		P1 = image(cv::Range(Ps[0].y1, Ps[0].y2), cv::Range(Ps[0].x1, Ps[0].x2));
		P2 = image(cv::Range(Ps[1].y1, Ps[1].y2), cv::Range(Ps[1].x1, Ps[1].x2));
		P3 = image(cv::Range(Ps[2].y1, Ps[2].y2), cv::Range(Ps[2].x1, Ps[2].x2));
		P4 = image(cv::Range(Ps[3].y1, Ps[3].y2), cv::Range(Ps[3].x1, Ps[3].x2));
		P5 = image(cv::Range(Ps[4].y1, Ps[4].y2), cv::Range(Ps[4].x1, Ps[4].x2));
		P6 = image(cv::Range(Ps[5].y1, Ps[5].y2), cv::Range(Ps[5].x1, Ps[5].x2));
		P7 = image(cv::Range(Ps[6].y1, Ps[6].y2), cv::Range(Ps[6].x1, Ps[6].x2));
		P8 = image(cv::Range(Ps[7].y1, Ps[7].y2), cv::Range(Ps[7].x1, Ps[7].x2));
		P9 = image(cv::Range(Ps[8].y1, Ps[8].y2), cv::Range(Ps[8].x1, Ps[8].x2));
	}

	cv::Rect ColorBlocks[10];
	ColorBlocks[1] = cv::Rect(0, 0, 120, 120);					//画出一个360*360的魔方识别结果图
	ColorBlocks[2] = cv::Rect(120, 0, 240, 120);
	ColorBlocks[3] = cv::Rect(240, 0, 360, 120);
	ColorBlocks[4] = cv::Rect(0, 120, 120, 240);
	ColorBlocks[5] = cv::Rect(120, 120, 240, 240);
	ColorBlocks[6] = cv::Rect(240, 120, 360, 240);
	ColorBlocks[7] = cv::Rect(0, 240, 120, 360);
	ColorBlocks[8] = cv::Rect(120, 240, 240, 360);
	ColorBlocks[9] = cv::Rect(240, 240, 360, 360);
	imwrite("P1.png", P1);					//保存小色块
	imwrite("P2.png", P2);
	imwrite("P3.png", P3);
	imwrite("P4.png", P4);
	imwrite("P5.png", P5);
	imwrite("P6.png", P6);
	imwrite("P7.png", P7);
	imwrite("P8.png", P8);
	imwrite("P9.png", P9);
	cv::Mat imgHSV[10];
	//Mat imgThresholded(200, 200, CV_8UC3);

	cvtColor(P1, imgHSV[1], cv::COLOR_BGR2HSV);
	cvtColor(P2, imgHSV[2], cv::COLOR_BGR2HSV);
	cvtColor(P3, imgHSV[3], cv::COLOR_BGR2HSV);
	cvtColor(P4, imgHSV[4], cv::COLOR_BGR2HSV);
	cvtColor(P5, imgHSV[5], cv::COLOR_BGR2HSV);
	cvtColor(P6, imgHSV[6], cv::COLOR_BGR2HSV);
	cvtColor(P7, imgHSV[7], cv::COLOR_BGR2HSV);
	cvtColor(P8, imgHSV[8], cv::COLOR_BGR2HSV);
	cvtColor(P9, imgHSV[9], cv::COLOR_BGR2HSV);

	if (CaseName == "case1") {
		if (ColorName == "B") {
			for (i = 1; i <= 9; i++) {				//对所有色块threshold
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "B") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "B") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "B") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "B") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "B") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "B") == 1)
					color[i] = "White";
			}
		}
		else if (ColorName == "R") {
			for (i = 1; i <= 9; i++) {				//对所有色块threshold
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "R") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "R") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "R") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "R") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "R") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "R") == 1)
					color[i] = "White";
			}
		}
		else if (ColorName == "D") {
			for (i = 1; i <= 9; i++) {				//对7个色块threshold
				if (i == 2 || i == 3)
					continue;
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "D") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "D") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "D") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "D") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "D") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "D") == 1)
					color[i] = "White";
			}
		}
		else if (ColorName == "L") {
			for (i = 1; i <= 9; i++) {				//对所有色块threshold
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "L") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "L") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "L") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "L") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "L") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "L") == 1)
					color[i] = "White";
			}
		}
		else if (ColorName == "U") {
			for (i = 1; i <= 9; i++) {				//对8个色块做threshold
				if (i == 8)
					continue;
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "U") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "U") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "U") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "U") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "U") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "U") == 1)
					color[i] = "White";
			}
		}
	}
	else if (CaseName == "case2") {
		if (ColorName == "D") {
			for (i = 1; i <= 9; i++) {				//对2个色块threshold
				if (i != 2 && i != 3)
					continue;
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "D") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "D") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "D") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "D") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "D") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "D") == 1)
					color[i] = "White";
			}
		}
		else if (ColorName == "F") {
			for (i = 1; i <= 9; i++) {				//对所有色块threshold
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "F") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "F") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "F") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "F") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "F") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "F") == 1)
					color[i] = "White";
			}
		}
		else if (ColorName == "U") {
			for (i = 1; i <= 9; i++) {				//对一个色块threshold
				if (i != 8)
					continue;
				PrintHSV(imgHSV[i], ColorName + "_" + CaseName + "_" + to_string(i));
				if (Color(imgHSV[i], "Red", "U") == 1)
					color[i] = "Red";
				else if (Color(imgHSV[i], "Orange", "U") == 1)
					color[i] = "Orange";
				else if (Color(imgHSV[i], "Yellow", "U") == 1)
					color[i] = "Yellow";
				else if (Color(imgHSV[i], "Blue", "U") == 1)
					color[i] = "Blue";
				else if (Color(imgHSV[i], "Green", "U") == 1)
					color[i] = "Green";
				else if (Color(imgHSV[i], "White", "U") == 1)
					color[i] = "White";
			}
		}
	}

	for (i = 1; i <= 9; i++)				//色块填充
		FillBlocks(Blank, color[i], i);
	line(Blank, cv::Point(0, 120), cv::Point(360, 120), cv::Scalar(0, 0, 0), 1, 8, 0);		//绘制分隔色块的黑线
	line(Blank, cv::Point(0, 240), cv::Point(360, 240), cv::Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, cv::Point(120, 0), cv::Point(120, 360), cv::Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, cv::Point(240, 0), cv::Point(240, 360), cv::Scalar(0, 0, 0), 1, 8, 0);
	for (i = 1; i <= 9; i++)
		if (color[i] == "")
			break;				//存在未识别出来的色块时，跳出循环
	if (i > 9)							//只有在全部色块识别出来才保存识别结果图片
		imwrite("pic_rec\\rec_" + ColorName + ".png", Blank);
	else
		cout << "Failed to recognize" + ColorName + "the first time" << endl;	//提示一下，说明第一次没有识别成功，这个在调试的时候用得到
}

string Print_str(string color[10], vector<string> standardcolor)		//order URFDLB
{
	int i;
	string str;
	for (i = 1; i <= 9; i++) {
		if (color[i] == standardcolor[0])
			str += "U";
		else if (color[i] == standardcolor[1])
			str += "R";
		else if (color[i] == standardcolor[2])
			str += "F";
		else if (color[i] == standardcolor[3])
			str += "D";
		else if (color[i] == standardcolor[4])
			str += "L";
		else if (color[i] == standardcolor[5])
			str += "B";
	}
	return str;
}

void Sample_Reset(vector<SamRec> &Sample_RF, vector<SamRec> &Sample_BU, vector<SamRec> &Sample_LD) {		//对采样色块的位置做初始化操作
	BWhiteHSV.iLowH = 0;
	BWhiteHSV.iHighH = 180;
	BWhiteHSV.iLowS = 0;
	BWhiteHSV.iHighS = 55;
	BWhiteHSV.iLowV = 100;
	BWhiteHSV.iHighV = 255;
	UWhiteHSV.iLowH = 0;
	UWhiteHSV.iHighH = 180;
	UWhiteHSV.iLowS = 0;
	UWhiteHSV.iHighS = 75;
	UWhiteHSV.iLowV = 100;
	UWhiteHSV.iHighV = 255;
	RWhiteHSV.iLowH = 0;
	RWhiteHSV.iHighH = 180;
	RWhiteHSV.iLowS = 0;
	RWhiteHSV.iHighS = 55;
	RWhiteHSV.iLowV = 80;
	RWhiteHSV.iHighV = 255;
	FWhiteHSV.iLowH = 0;
	FWhiteHSV.iHighH = 180;
	FWhiteHSV.iLowS = 0;
	FWhiteHSV.iHighS = 80;
	FWhiteHSV.iLowV = 70;
	FWhiteHSV.iHighV = 205;
	LWhiteHSV.iLowH = 0;
	LWhiteHSV.iHighH = 180;
	LWhiteHSV.iLowS = 0;
	LWhiteHSV.iHighS = 50;
	LWhiteHSV.iLowV = 100;
	LWhiteHSV.iHighV = 255;
	DWhiteHSV.iLowH = 0;
	DWhiteHSV.iHighH = 180;
	DWhiteHSV.iLowS = 0;
	DWhiteHSV.iHighS = 55;
	DWhiteHSV.iLowV = 100;
	DWhiteHSV.iHighV = 255;

	BRedHSV_L.iLowH = 0;
	BRedHSV_L.iHighH = 8;
	BRedHSV_L.iLowS = 43;
	BRedHSV_L.iHighS = 255;
	BRedHSV_L.iLowV = 46;
	BRedHSV_L.iHighV = 210;
	URedHSV_L.iLowH = 0;
	URedHSV_L.iHighH = 15;
	URedHSV_L.iLowS = 43;
	URedHSV_L.iHighS = 255;
	URedHSV_L.iLowV = 46;
	URedHSV_L.iHighV = 160;
	RRedHSV_L.iLowH = 0;
	RRedHSV_L.iHighH = 12;
	RRedHSV_L.iLowS = 43;
	RRedHSV_L.iHighS = 255;
	RRedHSV_L.iLowV = 40;
	RRedHSV_L.iHighV = 190;
	FRedHSV_L.iLowH = 0;
	FRedHSV_L.iHighH = 7;
	FRedHSV_L.iLowS = 43;
	FRedHSV_L.iHighS = 255;
	FRedHSV_L.iLowV = 46;
	FRedHSV_L.iHighV = 150;
	LRedHSV_L.iLowH = 0;
	LRedHSV_L.iHighH = 10;
	LRedHSV_L.iLowS = 43;
	LRedHSV_L.iHighS = 255;
	LRedHSV_L.iLowV = 46;
	LRedHSV_L.iHighV = 190;
	DRedHSV_L.iLowH = 0;
	DRedHSV_L.iHighH = 7;
	DRedHSV_L.iLowS = 43;
	DRedHSV_L.iHighS = 255;
	DRedHSV_L.iLowV = 30;
	DRedHSV_L.iHighV = 150;

	BRedHSV_H.iLowH = 160;
	BRedHSV_H.iHighH = 185;
	BRedHSV_H.iLowS = 43;
	BRedHSV_H.iHighS = 255;
	BRedHSV_H.iLowV = 46;
	BRedHSV_H.iHighV = 210;
	URedHSV_H.iLowH = 160;
	URedHSV_H.iHighH = 185;
	URedHSV_H.iLowS = 43;
	URedHSV_H.iHighS = 255;
	URedHSV_H.iLowV = 46;
	URedHSV_H.iHighV = 160;
	RRedHSV_H.iLowH = 160;
	RRedHSV_H.iHighH = 185;
	RRedHSV_H.iLowS = 43;
	RRedHSV_H.iHighS = 255;
	RRedHSV_H.iLowV = 40;
	RRedHSV_H.iHighV = 190;
	FRedHSV_H.iLowH = 160;
	FRedHSV_H.iHighH = 185;
	FRedHSV_H.iLowS = 43;
	FRedHSV_H.iHighS = 255;
	FRedHSV_H.iLowV = 46;
	FRedHSV_H.iHighV = 150;
	LRedHSV_H.iLowH = 160;
	LRedHSV_H.iHighH = 185;
	LRedHSV_H.iLowS = 43;
	LRedHSV_H.iHighS = 255;
	LRedHSV_H.iLowV = 46;
	LRedHSV_H.iHighV = 190;
	DRedHSV_H.iLowH = 160;
	DRedHSV_H.iHighH = 185;
	DRedHSV_H.iLowS = 43;
	DRedHSV_H.iHighS = 255;
	DRedHSV_H.iLowV = 30;
	DRedHSV_H.iHighV = 150;

	BYellowHSV.iLowH = 26;
	BYellowHSV.iHighH = 38;
	BYellowHSV.iLowS = 90;
	BYellowHSV.iHighS = 255;
	BYellowHSV.iLowV = 46;
	BYellowHSV.iHighV = 255;
	UYellowHSV.iLowH = 26;
	UYellowHSV.iHighH = 40;
	UYellowHSV.iLowS = 120;
	UYellowHSV.iHighS = 255;
	UYellowHSV.iLowV = 46;
	UYellowHSV.iHighV = 255;
	RYellowHSV.iLowH = 26;
	RYellowHSV.iHighH = 40;
	RYellowHSV.iLowS = 100;
	RYellowHSV.iHighS = 255;
	RYellowHSV.iLowV = 46;
	RYellowHSV.iHighV = 255;
	FYellowHSV.iLowH = 26;
	FYellowHSV.iHighH = 40;
	FYellowHSV.iLowS = 120;
	FYellowHSV.iHighS = 255;
	FYellowHSV.iLowV = 46;
	FYellowHSV.iHighV = 255;
	LYellowHSV.iLowH = 26;
	LYellowHSV.iHighH = 40;
	LYellowHSV.iLowS = 120;
	LYellowHSV.iHighS = 255;
	LYellowHSV.iLowV = 46;
	LYellowHSV.iHighV = 255;
	DYellowHSV.iLowH = 26;
	DYellowHSV.iHighH = 40;
	DYellowHSV.iLowS = 120;
	DYellowHSV.iHighS = 255;
	DYellowHSV.iLowV = 46;
	DYellowHSV.iHighV = 255;

	BBlueHSV.iLowH = 90;
	BBlueHSV.iHighH = 124;
	BBlueHSV.iLowS = 43;
	BBlueHSV.iHighS = 255;
	BBlueHSV.iLowV = 46;
	BBlueHSV.iHighV = 255;
	UBlueHSV.iLowH = 90;
	UBlueHSV.iHighH = 124;
	UBlueHSV.iLowS = 60;
	UBlueHSV.iHighS = 255;
	UBlueHSV.iLowV = 46;
	UBlueHSV.iHighV = 255;
	RBlueHSV.iLowH = 90;
	RBlueHSV.iHighH = 124;
	RBlueHSV.iLowS = 43;
	RBlueHSV.iHighS = 255;
	RBlueHSV.iLowV = 46;
	RBlueHSV.iHighV = 255;
	FBlueHSV.iLowH = 90;
	FBlueHSV.iHighH = 124;
	FBlueHSV.iLowS = 43;
	FBlueHSV.iHighS = 255;
	FBlueHSV.iLowV = 46;
	FBlueHSV.iHighV = 255;
	LBlueHSV.iLowH = 90;
	LBlueHSV.iHighH = 124;
	LBlueHSV.iLowS = 43;
	LBlueHSV.iHighS = 255;
	LBlueHSV.iLowV = 46;
	LBlueHSV.iHighV = 255;
	DBlueHSV.iLowH = 90;
	DBlueHSV.iHighH = 124;
	DBlueHSV.iLowS = 120;
	DBlueHSV.iHighS = 255;
	DBlueHSV.iLowV = 65;
	DBlueHSV.iHighV = 255;


	BGreenHSV.iLowH = 38;
	BGreenHSV.iHighH = 70;
	BGreenHSV.iLowS = 43;
	BGreenHSV.iHighS = 255;
	BGreenHSV.iLowV = 46;
	BGreenHSV.iHighV = 255;
	UGreenHSV.iLowH = 40;
	UGreenHSV.iHighH = 70;
	UGreenHSV.iLowS = 120;
	UGreenHSV.iHighS = 255;
	UGreenHSV.iLowV = 46;
	UGreenHSV.iHighV = 255;
	RGreenHSV.iLowH = 40;
	RGreenHSV.iHighH = 70;
	RGreenHSV.iLowS = 43;
	RGreenHSV.iHighS = 255;
	RGreenHSV.iLowV = 46;
	RGreenHSV.iHighV = 255;
	FGreenHSV.iLowH = 30;
	FGreenHSV.iHighH = 70;
	FGreenHSV.iLowS = 43;
	FGreenHSV.iHighS = 255;
	FGreenHSV.iLowV = 46;
	FGreenHSV.iHighV = 255;
	LGreenHSV.iLowH = 40;
	LGreenHSV.iHighH = 70;
	LGreenHSV.iLowS = 43;
	LGreenHSV.iHighS = 255;
	LGreenHSV.iLowV = 46;
	LGreenHSV.iHighV = 255;
	DGreenHSV.iLowH = 40;
	DGreenHSV.iHighH = 70;
	DGreenHSV.iLowS = 43;
	DGreenHSV.iHighS = 255;
	DGreenHSV.iLowV = 46;
	DGreenHSV.iHighV = 255;

	BOrangeHSV.iLowH = 0;
	BOrangeHSV.iHighH = 22;
	BOrangeHSV.iLowS = 100;
	BOrangeHSV.iHighS = 255;
	BOrangeHSV.iLowV = 210;
	BOrangeHSV.iHighV = 255;
	UOrangeHSV.iLowH = 0;
	UOrangeHSV.iHighH = 15;
	UOrangeHSV.iLowS = 100;
	UOrangeHSV.iHighS = 255;
	UOrangeHSV.iLowV = 160;
	UOrangeHSV.iHighV = 255;
	ROrangeHSV.iLowH = 0;
	ROrangeHSV.iHighH = 15;
	ROrangeHSV.iLowS = 100;
	ROrangeHSV.iHighS = 255;
	ROrangeHSV.iLowV = 190;
	ROrangeHSV.iHighV = 255;
	FOrangeHSV.iLowH = 0;
	FOrangeHSV.iHighH = 15;
	FOrangeHSV.iLowS = 100;
	FOrangeHSV.iHighS = 255;
	FOrangeHSV.iLowV = 150;
	FOrangeHSV.iHighV = 255;
	LOrangeHSV.iLowH = 0;
	LOrangeHSV.iHighH = 20;
	LOrangeHSV.iLowS = 70;
	LOrangeHSV.iHighS = 255;
	LOrangeHSV.iLowV = 190;
	LOrangeHSV.iHighV = 255;
	DOrangeHSV.iLowH = 0;
	DOrangeHSV.iHighH = 15;
	DOrangeHSV.iLowS = 180;
	DOrangeHSV.iHighS = 255;
	DOrangeHSV.iLowV = 150;
	DOrangeHSV.iHighV = 255;

	P9.x1 = P6.x1 = P3.x1 = 55;
	P9.x2 = P6.x2 = P3.x2 = 75;

	P8.x1 = P5.x1 = P2.x1 = 110;
	P8.x2 = P5.x2 = P2.x2 = 130;

	P7.x1 = P4.x1 = P1.x1 = 180;
	P7.x2 = P4.x2 = P1.x2 = 200;

	P18.x1 = P15.x1 = P12.x1 = 260;
	P18.x2 = P15.x2 = P12.x2 = 280;

	P17.x1 = P14.x1 = P11.x1 = 340;
	P17.x2 = P14.x2 = P11.x2 = 360;

	P16.x1 = P13.x1 = P10.x1 = 405;
	P16.x2 = P13.x2 = P10.x2 = 425;

	P9.y1 = P8.y1 = P17.y1 = P16.y1 = 120;
	P9.y2 = P8.y2 = P17.y2 = P16.y2 = 140;
	P7.y1 = P18.y1 = 110;
	P7.y2 = P18.y2 = 130;

	P6.y1 = P5.y1 = P4.y1 = P15.y1 = P14.y1 = P13.y1 = 220;
	P6.y2 = P5.y2 = P4.y2 = P15.y2 = P14.y2 = P13.y2 = 240;

	P2.y1 = P11.y1 = 320;
	P2.y2 = P11.y2 = 340;
	P3.y1 = P10.y1 = 310;
	P3.y2 = P10.y2 = 330;
	P1.y1 = P12.y1 = 320;
	P1.y2 = P12.y2 = 340;


	Sample_RF.push_back(P1);
	Sample_RF.push_back(P2);
	Sample_RF.push_back(P3);
	Sample_RF.push_back(P4);
	Sample_RF.push_back(P5);
	Sample_RF.push_back(P6);
	Sample_RF.push_back(P7);
	Sample_RF.push_back(P8);
	Sample_RF.push_back(P9);
	Sample_RF.push_back(P10);
	Sample_RF.push_back(P11);
	Sample_RF.push_back(P12);
	Sample_RF.push_back(P13);
	Sample_RF.push_back(P14);
	Sample_RF.push_back(P15);
	Sample_RF.push_back(P16);
	Sample_RF.push_back(P17);
	Sample_RF.push_back(P18);

	P10.x1 = P13.x1 = P16.x1 = 270;
	P10.x2 = P13.x2 = P16.x2 = 290;
	P9.x1 = 280;
	P9.x2 = 300;
	P6.x1 = 270;
	P6.x2 = 290;
	P3.x1 = 260;
	P3.x2 = 280;

	P5.x1 = P2.x1 = P11.x1 = P14.x1 = 360;
	P5.x2 = P2.x2 = P11.x2 = P14.x2 = 380;
	P8.x1 = 360;
	P8.x2 = 380;
	P17.x1 = 360;
	P17.x2 = 380;

	P4.x1 = 450;
	P4.x2 = 470;
	P15.x1 = 450;
	P15.x2 = 470;
	P18.x1 = 450;
	P18.x2 = 470;
	P7.x1 = 440;
	P7.x2 = 460;
	P1.x1 = P12.x1 = 460;
	P1.x2 = P12.x2 = 480;

	P9.y1 = P7.y1 = P8.y1 = 80;
	P9.y2 = P7.y2 = P8.y2 = 100;

	P6.y1 = P5.y1 = 125;
	P6.y2 = P5.y2 = 145;
	P4.y1 = 125;
	P4.y2 = 145;

	P3.y1 = P2.y1 = P1.y1 = 185;
	P3.y2 = P2.y2 = P1.y2 = 205;

	P10.y1 = P11.y1 = P12.y1 = 255;
	P10.y2 = P11.y2 = P12.y2 = 275;

	P13.y1 = P14.y1 = P15.y1 = 315;
	P13.y2 = P14.y2 = P15.y2 = 335;

	P18.y1 = P16.y1 = P17.y1 = 360;
	P18.y2 = P16.y2 = P17.y2 = 380;


	Sample_BU.push_back(P1);
	Sample_BU.push_back(P2);
	Sample_BU.push_back(P3);
	Sample_BU.push_back(P4);
	Sample_BU.push_back(P5);
	Sample_BU.push_back(P6);
	Sample_BU.push_back(P7);
	Sample_BU.push_back(P8);
	Sample_BU.push_back(P9);
	Sample_BU.push_back(P10);
	Sample_BU.push_back(P11);
	Sample_BU.push_back(P12);
	Sample_BU.push_back(P13);
	Sample_BU.push_back(P14);
	Sample_BU.push_back(P15);
	Sample_BU.push_back(P16);
	Sample_BU.push_back(P17);
	Sample_BU.push_back(P18);

	P4.x1 = 250;
	P4.x2 = 270;
	P16.x1 = 230;
	P16.x2 = 250;
	P7.x1 = 240;
	P7.x2 = 260;
	P17.x1 = 260;
	P17.x2 = 280;
	P1.x1 = 270;
	P1.x2 = 290;
	P18.x1 = 280;
	P18.x2 = 300;


	P13.x1 = P14.x1 = 380;
	P13.x2 = P14.x2 = 400;
	P2.x1 = P5.x1 = P8.x1 = 370;
	P2.x2 = P5.x2 = P8.x2 = 390;
	P15.x1 = 390;
	P15.x2 = 410;

	P3.x1 = P12.x1 = P9.x1 = P3.x1 = P6.x1 = P10.x1 = P11.x1 = 500;
	P3.x2 = P12.x2 = P9.x2 = P3.x2 = P6.x2 = P10.x2 = P11.x2 = 520;
	P12.x1 = 500;
	P12.x2 = 520;

	P3.y1 = 80;
	P3.y2 = 100;
	P2.y1 = 90;
	P2.y2 = 110;
	P1.y1 = 100;
	P1.y2 = 120;

	P4.y1 = P5.y1 = 170;
	P4.y2 = P5.y2 = 190;
	P6.y1 = 160;
	P6.y2 = 180;

	P8.y1 = P9.y1 = 250;
	P8.y2 = P9.y2 = 270;
	P7.y1 = 270;
	P7.y2 = 290;

	P16.y1 = P13.y1 = 360;
	P16.y2 = P13.y2 = 380;
	P10.y1 = 350;
	P10.y2 = 370;

	P17.y1 = P14.y1 = P11.y1 = 420;
	P17.y2 = P14.y2 = P11.y2 = 440;

	P18.y1 = P15.y1 = 470;
	P18.y2 = P15.y2 = 490;
	P12.y1 = 460;
	P12.y2 = 480;
	P18.y1 = 470;
	P18.y2 = 490;

	Sample_LD.push_back(P1);
	Sample_LD.push_back(P2);
	Sample_LD.push_back(P3);
	Sample_LD.push_back(P4);
	Sample_LD.push_back(P5);
	Sample_LD.push_back(P6);
	Sample_LD.push_back(P7);
	Sample_LD.push_back(P8);
	Sample_LD.push_back(P9);
	Sample_LD.push_back(P10);
	Sample_LD.push_back(P11);
	Sample_LD.push_back(P12);
	Sample_LD.push_back(P13);
	Sample_LD.push_back(P14);
	Sample_LD.push_back(P15);
	Sample_LD.push_back(P16);
	Sample_LD.push_back(P17);
	Sample_LD.push_back(P18);

}

string Recognition() {			//识别魔方一个面的色块，加参case和面参数，根据不同参数来调色块采样位置Ps

	vector<cv::Point> center;								//存放9个色块的中心位置,x和y，未来采样用
														//初始化6个空面
	cv::Mat B(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//B面
	cv::Mat D(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//D面
	cv::Mat F(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//F面
	cv::Mat L(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//L面
	cv::Mat R(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//R面
	cv::Mat U(360, 360, CV_8UC3, cv::Scalar(255, 255, 255));		//U面
	int i;
	cv::Mat image;
	vector <string> standardcolor;
	string tmp[6];				//接受返回的字符串
	string color_def;

	Sample_Reset(sampleRec_FR, sampleRec_UB, sampleRec_LD);		// 初始化参数

	image = cv::imread("pic_cam//cam_case1_BU.png");			//B面可以一次识别，识别完就保存图片
	JudgeColor(image, B, "B", "case1", Bcolor, sampleRec_UB);

	image = cv::imread("pic_cam//cam_case1_LD.png");			//第一次识别
	JudgeColor(image, D, "D", "case1", Dcolor, sampleRec_LD);
	image = cv::imread("pic_cam//cam_case2_LD.png");			//做第二次识别
	JudgeColor(image, D, "D", "case2", Dcolor, sampleRec_LD);


	image = cv::imread("pic_cam//cam_case2_RF.png");			//一次识别
	JudgeColor(image, F, "F", "case2", Fcolor, sampleRec_FR);


	image = cv::imread("pic_cam//cam_case1_LD.png");			//L只要识一次
	JudgeColor(image, L, "L", "case1", Lcolor, sampleRec_LD);

	image = cv::imread("pic_cam//cam_case1_RF.png");			//R只要识别一次
	JudgeColor(image, R, "R", "case1", Rcolor, sampleRec_FR);

	image = cv::imread("pic_cam//cam_case1_BU.png");
	JudgeColor(image, U, "U", "case1", Ucolor, sampleRec_UB);
	image = cv::imread("pic_cam//cam_case2_BU.png");			//做第二次识别
	JudgeColor(image, U, "U", "case2", Ucolor, sampleRec_UB);


	//下面的操作用来生成字符串
	string Ustandard = Ucolor[5];
	string Rstandard = Rcolor[5];
	string Fstandard = Fcolor[5];
	string Dstandard = Dcolor[5];
	string Lstandard = Lcolor[5];
	string Bstandard = Bcolor[5];
	standardcolor.push_back(Ustandard);
	standardcolor.push_back(Rstandard);
	standardcolor.push_back(Fstandard);
	standardcolor.push_back(Dstandard);
	standardcolor.push_back(Lstandard);
	standardcolor.push_back(Bstandard);

	tmp[0] = Print_str(Ucolor, standardcolor);
	tmp[1] = Print_str(Rcolor, standardcolor);
	tmp[2] = Print_str(Fcolor, standardcolor);
	tmp[3] = Print_str(Dcolor, standardcolor);
	tmp[4] = Print_str(Lcolor, standardcolor);
	tmp[5] = Print_str(Bcolor, standardcolor);

	for (i = 0; i < 6; i++)
		color_def += tmp[i];

	return color_def;			//颜色字符串
}

void Empty_Color(string Bcolor[], string Dcolor[], string Fcolor[], string Lcolor[], string Rcolor[], string Ucolor[])
{
	int i;
	for (i = 0; i <= 9; i++) {
		Bcolor[i] = "";
		Dcolor[i] = "";
		Fcolor[i] = "";
		Lcolor[i] = "";
		Rcolor[i] = "";
		Ucolor[i] = "";
	}
}

void Capture(string Case)
{
	cv::VideoCapture  captureB(0);
	cv::VideoCapture  captureD(1);
	//VideoCapture  captureF(2);
	//VideoCapture  captureL(3);
	//VideoCapture  captureR(4);
	//VideoCapture  captureU(5);
	if (!captureB.isOpened())
	{
		cout << "摄像头B打开失败！" << endl;
		return;
	}
	if (!captureD.isOpened())
	{
		cout << "摄像头D打开失败！" << endl;
		return;
	}
	/*
	if (!captureF.isOpened())
	{
		cout << "摄像头F打开失败！" << endl;
		return;
	}
	if (!captureL.isOpened())
	{
		cout << "摄像头L打开失败！" << endl;
		return;
	}
	if (!captureR.isOpened())
	{
		cout << "摄像头R打开失败！" << endl;
		return;
	}
	if (!captureU.isOpened())
	{
		cout << "摄像头U打开失败！" << endl;
		return;
	}
	*/

	char key;
	char filename[200];
	int count = 0;
	cv::namedWindow("【视频】", 1);
	cv::Mat frameB, frameD, frameF, frameL, frameR, frameU;		//order: BDFLRU

	while (1)
	{
		key = cv::waitKey(50);
		captureD >> frameD;
		captureB >> frameB;
		imshow("【视频B】", frameB);
		imshow("【视频D】", frameD);
		/*
		imshow("【视频F】", frameF);
		imshow("【视频L】", frameL);
		imshow("【视频R】", frameR);
		imshow("【视频U】", frameU);
		*/

		if (key == 27)
			break;				//按ESC键退出程序  
		if (key == 32)//按空格键进行拍照  
		{
			if (Case == "Case1") {
				sprintf(filename, "B.png");
				imwrite(filename, frameB);//图片保存到本工程目录中  
				/*
				sprintf(filename, "cam_case1_D.png");
				imwrite(filename, frameD);//图片保存到本工程目录中
				sprintf(filename, "cam_case1_F.png");
				imwrite(filename, frameF);//图片保存到本工程目录中
				sprintf(filename, "L.png");
				imwrite(filename, frameL);//图片保存到本工程目录中
				sprintf(filename, "cam_case1_R.png");
				imwrite(filename, frameR);//图片保存到本工程目录中
				sprintf(filename, "cam_case1_U.png");
				imwrite(filename, frameU);//图片保存到本工程目录中
				*/
				break;					//拍完照以后跳出循环并返回
			}
			else if (Case == "Case2") {			//case2只需要拍摄4个面
				sprintf(filename, "cam_case2_D.png");
				/*
				imwrite(filename, frameD);//图片保存到本工程目录中
				sprintf(filename, "cam_case2_F.png");
				imwrite(filename, frameF);//图片保存到本工程目录中
				sprintf(filename, "cam_case2_R.png");
				imwrite(filename, frameR);//图片保存到本工程目录中
				sprintf(filename, "cam_case2_U.png");
				imwrite(filename, frameU);//图片保存到本工程目录中
				*/
				break;					//拍完照以后跳出循环并返回
			}
		}
	}

	return;
}

void Show()
{
	cv::Mat image;
	Sample_Reset(sampleRec_FR, sampleRec_UB, sampleRec_LD);

	image = cv::imread("pic_cam//cam_case1_RF.png");
	resize(image, image, cv::Size(700, 500), 0, 0, 3);
	DrawLine(image, "RF", sampleRec_FR, sampleRec_UB, sampleRec_LD);
	imshow("My_pic_RF", image);

	image = cv::imread("pic_cam//cam_case1_LD.png");
	resize(image, image, cv::Size(700, 500), 0, 0, 3);
	DrawLine(image, "LD", sampleRec_FR, sampleRec_UB, sampleRec_LD);
	imshow("My_pic_LD", image);

	image = cv::imread("pic_cam//cam_case1_BU.png");
	resize(image, image, cv::Size(700, 500), 0, 0, 3);
	DrawLine(image, "BU", sampleRec_FR, sampleRec_UB, sampleRec_LD);
	imshow("My_pic_BU", image);

	cv::waitKey(0);
}

void DrawLine(cv::Mat image, string c, vector<SamRec> &Sample_RF, vector<SamRec> &Sample_BU, vector<SamRec> &Sample_LD)
{
	int i;
	cv::Point p1, p2;
	if (c == "RF") {
		for (i = 0; i < 18; i++) {
			p1.x = Sample_RF[i].x1;
			p1.y = Sample_RF[i].y1;
			p2.x = Sample_RF[i].x2;
			p2.y = Sample_RF[i].y2;
			line(image, p1, p2, cv::Scalar(0, 0, 0), 2);
		}
	}
	else if (c == "LD") {
		for (i = 0; i < 18; i++) {
			p1.x = Sample_LD[i].x1;
			p1.y = Sample_LD[i].y1;
			p2.x = Sample_LD[i].x2;
			p2.y = Sample_LD[i].y2;
			line(image, p1, p2, cv::Scalar(0, 0, 0), 2);
		}
	}
	else if (c == "BU") {
		for (i = 0; i < 18; i++) {
			p1.x = Sample_BU[i].x1;
			p1.y = Sample_BU[i].y1;
			p2.x = Sample_BU[i].x2;
			p2.y = Sample_BU[i].y2;
			line(image, p1, p2, cv::Scalar(0, 0, 0), 2);
		}
	}
}
