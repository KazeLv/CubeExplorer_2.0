#include "CubeRecognizer.h"

static QMap<QString, QMap<QString, HSV>> map_face_color_hsv;		//存放hsv阈值数据的嵌套 map,访问方式为 map[faceName][colorName]
static QList<QString> list_faceID, list_colorID;					//两个下标list，用于通过整数 index 取得对应的字符串作为 map 的key值来访问 map_face_color_hsv;

static QMap<QString, vector<SamRec>> map_pic_id_samRec;				//存放采样框数据的 map ,其中每个元素为存储 samRec 类型的vector，对应一张图片的18个采样位置
QList<QString> list_picID;											//用于采样框map的下标list，通过整数 index 取得对应的照片名作为 map 的key值来访问 map_pic_id_samRec

static QMap<QString, vector<QString>> map_face_id_recogRes;			//存放识别结果，访问方式为 map[face][blockID]
static QMap<QString, cv::Scalar> map_color_scalar;					//存放预设颜色值，用于绘制识别结果图

static QMap<QString, vector<cv::Mat>> map_face_id_lastRecogMat;		//保存当前识别过程中的采样图片，方便识别结束时查看对比HSV数据

//new things-----------------------------------------------------------
static vector<CubeBlock> vec_samBlocks;									//保存拍摄采样的色块

//---------------------------------------------------------------------

//HSV模块
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

	list_colorID.append("red_h");	list_faceID.append("u"); 		//初始化两个下标list
	list_colorID.append("red_l");	list_faceID.append("r"); 		//
	list_colorID.append("orange");	list_faceID.append("f"); 		//
	list_colorID.append("blue");	list_faceID.append("d"); 		//
	list_colorID.append("green");	list_faceID.append("l"); 		//
	list_colorID.append("yellow");	list_faceID.append("b"); 		//
	list_colorID.append("white");

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
				QString::number(hsv.iLowH) + "_" + QString::number(hsv.iHighH) + "_" +		//以"iLowH_iHighH_iLowS_iHighS_iLowV_iHighV"的格式存储单个HSV结构
				QString::number(hsv.iLowS) + "_" + QString::number(hsv.iHighS) + "_" +		//
				QString::number(hsv.iLowV) + "_" + QString::number(hsv.iHighV));			//

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

//采样框模块
void iniRecMap() {
	vector<SamRec> sampleRec_FR, sampleRec_UB, sampleRec_LD;		//存储三张照片的采样框
	map_pic_id_samRec.insert("FR", sampleRec_FR);
	map_pic_id_samRec.insert("UB", sampleRec_UB);
	map_pic_id_samRec.insert("LD", sampleRec_LD);

	list_picID.append("FR");										//初始化图片 key 下标list，0对应 "FR"
	list_picID.append("UB");										//1对应 "UB"
	list_picID.append("LD");										//2对应 "LD"

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

	vec_samBlocks.resize(54);										//
}

QMap<QString, vector<SamRec>>& getSamRecMap() {
	return map_pic_id_samRec;
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
				QString::number(rec.x1) + "_" +
				QString::number(rec.x2) + "_" +
				QString::number(rec.y1) + "_" +
				QString::number(rec.y2));

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

//识别模块
void iniRecogVars() {
	//初始化识别结果 map 为 6*9 大小
	vector<QString> vec_fill;
	vec_fill.resize(9);
	map_face_id_recogRes.insert("f", vec_fill);
	map_face_id_recogRes.insert("r", vec_fill);
	map_face_id_recogRes.insert("u", vec_fill);
	map_face_id_recogRes.insert("b", vec_fill);
	map_face_id_recogRes.insert("l", vec_fill);
	map_face_id_recogRes.insert("d", vec_fill);

	//初始化绘制识别结果图所用的预设颜色 map
	map_color_scalar.insert("red", cv::Scalar(0, 0, 255));
	map_color_scalar.insert("orange", cv::Scalar(0, 165, 255));
	map_color_scalar.insert("blue", cv::Scalar(255, 0, 0));
	map_color_scalar.insert("green", cv::Scalar(0, 255, 0));
	map_color_scalar.insert("yellow", cv::Scalar(0, 255, 255));
	map_color_scalar.insert("white", cv::Scalar(255, 255, 255));

	//初始化识别采样图存储map
	vector<cv::Mat> vec_mat_fill;
	vec_mat_fill.resize(9);
	map_face_id_lastRecogMat.insert("f", vec_mat_fill);
	map_face_id_lastRecogMat.insert("r", vec_mat_fill);
	map_face_id_lastRecogMat.insert("u", vec_mat_fill);
	map_face_id_lastRecogMat.insert("b", vec_mat_fill);
	map_face_id_lastRecogMat.insert("l", vec_mat_fill);
	map_face_id_lastRecogMat.insert("d", vec_mat_fill);
}

QMap<QString, vector<cv::Mat>>& getLastRecogMatMap() {
	return map_face_id_lastRecogMat;
}

int isColor(cv::Mat imgHSV, QString color, QString face)
{
	HSV hsv;
	if (color == "red") hsv = map_face_color_hsv[face]["red_l"];
	else hsv = map_face_color_hsv[face][color];

	cv::Mat imgThresholded;

	cv::inRange(imgHSV, cv::Scalar(hsv.iLowH, hsv.iLowS, hsv.iLowV), cv::Scalar(hsv.iHighH, hsv.iHighS, hsv.iHighV), imgThresholded); //阈值化处理图片，符合阈值的像素点三通道置为全255

	int count = 0;
	int totalPixNum = imgThresholded.cols*imgThresholded.rows;

	for (int i = 0; i < imgThresholded.rows; i++) {				//遍历阈值化处理后的图片
		cv::Vec3b *p = imgThresholded.ptr<cv::Vec3b>(i);
		for (int j = 0; j < imgThresholded.cols; j++) {
			if (p[j] == cv::Vec3b{ 255,255,255 })				//如果当前像素为(255,255,255)，则计数器加一
				count++;										//
		}
	}

	if (color == "red") {						//红色HSV阈值有两个区间，需要分别进行计算累加
		hsv = map_face_color_hsv[face]["red_h"];
		cv::inRange(imgHSV, cv::Scalar(hsv.iLowH, hsv.iLowS, hsv.iLowV), cv::Scalar(hsv.iHighH, hsv.iHighS, hsv.iHighV), imgThresholded);
		int count1 = 0;
		for (int i = 0; i < imgThresholded.rows; i++) {				//遍历阈值化处理后的图片
			cv::Vec3b *p = imgThresholded.ptr<cv::Vec3b>(i);
			for (int j = 0; j < imgThresholded.cols; j++) {
				if (p[j] == cv::Vec3b{ 255,255,255 })				//如果当前像素为(255,255,255)，则计数器加一
					count1++;										//
			}
		}
		count += count1;
	}

	if (count > totalPixNum*RECOG_SIMILARITY_COE) return 1;		//符合阈值的像素点所占比例大于预设系数，判定取色块为当前颜色
	return 0;													//否则，判定取色块不是当前颜色
}

void judgeColor(cv::Mat image, QString picName, int caseID) {
	vector<SamRec> vec_samRec1, vec_samRec2;				//分别存放picName指定图片所采样的两个面的采样框数据，从小到大需满足kociemba算法序号要求
	vector<vector<SamRec>> vec_samRec;						//存放picName指定图片所采样的两个面的采样框数据，从小到大需满足kociemba算法序号要求
	vector<int> vec_specialBlockID;							//存放特殊块（在case1中会被遮挡的快）的序号(0~17)
	//首先根据kociemba算法对魔方块排序的要求，将对应面的采样框按照序号放到vec_samRec临时容器中
	if (picName == "FR") {
		//F面的采样框数据
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
		//R面的采样框数据
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
		
		//F面的1号和7号块会在case1中被遮挡
		vec_specialBlockID.push_back(0);
		vec_specialBlockID.push_back(1);
		vec_specialBlockID.push_back(6);
		vec_specialBlockID.push_back(7);
	}
	else if (picName == "UB") {
		//U面采样框数据
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
		//B面采样框数据
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

		//U面的7号块会在case1中被遮挡
		vec_specialBlockID.push_back(7);
	}
	else if (picName == "LD") {
		//L面采样框数据
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
		//D面采样框数据
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

		//D面的1号块（在图中为10号块）会在case1中被遮挡
		vec_specialBlockID.push_back(10);
		vec_specialBlockID.push_back(11);
	}

	//然后根据不同的case进行不同的识别方案
	//case1时，忽略special块，仅识别未被遮挡的块
	//case2时，忽略case1能够处理的色块，仅识别special块
	cv::Mat mat_t, mat_hsv;
	QString faceName;
	vector<SamRec> vec_samRec_t;
	for (int faceID = 0; faceID < 2; faceID++) {
		faceName = picName[faceID].toLower();
		vec_samRec_t = vec_samRec[faceID];
		for (int i = 0; i < vec_samRec_t.size(); i++) {
			//判断是否忽略当前色块，关键点是利用抑或条件使得两种case得到不同的结果：
			//case1，当前序号若存在于specialBlockID容器中，判断结果为 1^0=1，continue进行忽略；否则判断结果为 0^0=0
			//case2，当前序号若不存在于specialBlockID容器中，判断结果为 0^1=1，continue进行忽略；否则判断结果为 1^1=0
			if (std::find(vec_specialBlockID.cbegin(), vec_specialBlockID.cend(), (faceID * 9 + i)) != vec_specialBlockID.cend() ^ (caseID == 2)) continue;

			//截取得到采样框内的图片并进行转换、识别
			mat_t = image(cv::Range(vec_samRec_t[i].y1, vec_samRec_t[i].y2), cv::Range(vec_samRec_t[i].x1, vec_samRec_t[i].x2));	
			map_face_id_lastRecogMat[faceName][i] = mat_t;														//将采样图保存到map，以供识别结束之后的调试使用
			cv::cvtColor(mat_t, mat_hsv, cv::COLOR_BGR2HSV);													//转换为HSV图片
			if (isColor(mat_hsv, "red", faceName)) map_face_id_recogRes[faceName][i] = "red";					//穷举法判断当前块属于哪一个颜色
			else if (isColor(mat_hsv, "orange", faceName)) map_face_id_recogRes[faceName][i] = "orange";		//
			else if (isColor(mat_hsv, "blue", faceName)) map_face_id_recogRes[faceName][i] = "blue";			//
			else if (isColor(mat_hsv, "green", faceName)) map_face_id_recogRes[faceName][i] = "green";			//
			else if (isColor(mat_hsv, "yellow", faceName)) map_face_id_recogRes[faceName][i] = "yellow";		//
			else if (isColor(mat_hsv, "white", faceName)) map_face_id_recogRes[faceName][i] = "white";			//
			else map_face_id_recogRes[faceName][i] = "unkown";													//若在穷举范围内没有找到结果，则存储为"unkown"
		}
	}
}

//固定参数法识别
string recognize() {
	//对三张拍摄图片依次读取并进行识别，识别结果存放到 map_face_id_recogRes 中
	cv::Mat image;

//策略1--------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------

//策略2--------------------------------------------------------------------------------
	//image = cv::imread("pic_cam/cam_FR.jpg");
	//cv::resize(image, image, cv::Size(640, 480));
	//judgeColor(image, "FR");

	//image = cv::imread("pic_cam/cam_UB.jpg");
	//cv::resize(image, image, cv::Size(640, 480));
	//judgeColor(image, "UB");

	//image = cv::imread("pic_cam/cam_LD.jpg");
	//cv::resize(image, image, cv::Size(640, 480));
	//judgeColor(image, "LD");
//-------------------------------------------------------------------------------------

	//根据识别结果绘制识别结果示意图，存放到本地文件夹"./pic_res"
	//并对识别结果进行排列得到 kociemba 算法所需要的字符串序列（U-R-F-D-L-B）
	QString str_res;
	QMap<QString, QString> map_color_face;
	for (int i = 0; i < 6; i++) map_color_face.insert(map_face_id_recogRes[list_faceID[i]][4], list_faceID[i]);		//存储各面中心块颜色，用以得到色块序号（U-R-F-D-L-B）

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
			str_res.append(map_color_face[vec_res[j]]);		//单个面内从0-8依次排列即可
		}
		line(mat_res, cv::Point(0, 120), cv::Point(360, 120), cv::Scalar(0, 0, 0), 1, 8, 0);						//绘制分隔色块的黑线
		line(mat_res, cv::Point(0, 240), cv::Point(360, 240), cv::Scalar(0, 0, 0), 1, 8, 0);
		line(mat_res, cv::Point(120, 0), cv::Point(120, 360), cv::Scalar(0, 0, 0), 1, 8, 0);
		line(mat_res, cv::Point(240, 0), cv::Point(240, 360), cv::Scalar(0, 0, 0), 1, 8, 0);

		imwrite("pic_res/res_" + list_faceID[i].toStdString() + ".png", mat_res);
	}

	return str_res.toUpper().toStdString();
}


//HSV排序法识别
string recognizeNew() {
	string strResult('u',54);
	int cntWhite = 9, cntRed = 9, cntOrange = 9, cntYellow = 9, cntGreen = 9, cntBlue = 9;

////获取所有的采样块并按kociemba要求的顺序存储到容器中
	cv::Mat image;
	int startIndex;

	//FR
	vector<SamRec>& vec_samRect = map_pic_id_samRec["FR"];
	//case1
	image = cv::imread("pic_cam/cam_case1_FR.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	startIndex = 18;										//F面
	vec_samBlocks[startIndex + 2].matSample = image(cv::Range(vec_samRect[2].y1, vec_samRect[2].y1), cv::Range(vec_samRect[2].x1, vec_samRect[2].x2));
	vec_samBlocks[startIndex + 3].matSample = image(cv::Range(vec_samRect[3].y1, vec_samRect[3].y1), cv::Range(vec_samRect[3].x1, vec_samRect[3].x2));
	vec_samBlocks[startIndex + 4].matSample = image(cv::Range(vec_samRect[4].y1, vec_samRect[4].y1), cv::Range(vec_samRect[4].x1, vec_samRect[4].x2));
	vec_samBlocks[startIndex + 5].matSample = image(cv::Range(vec_samRect[5].y1, vec_samRect[5].y1), cv::Range(vec_samRect[5].x1, vec_samRect[5].x2));
	vec_samBlocks[startIndex + 8].matSample = image(cv::Range(vec_samRect[8].y1, vec_samRect[8].y1), cv::Range(vec_samRect[8].x1, vec_samRect[8].x2));
	startIndex = 9;											//R面
	vec_samBlocks[startIndex + 0].matSample = image(cv::Range(vec_samRect[9].y1, vec_samRect[9].y1), cv::Range(vec_samRect[9].x1, vec_samRect[9].x2));
	vec_samBlocks[startIndex + 1].matSample = image(cv::Range(vec_samRect[10].y1, vec_samRect[10].y1), cv::Range(vec_samRect[10].x1, vec_samRect[10].x2));
	vec_samBlocks[startIndex + 2].matSample = image(cv::Range(vec_samRect[11].y1, vec_samRect[11].y1), cv::Range(vec_samRect[11].x1, vec_samRect[11].x2));
	vec_samBlocks[startIndex + 3].matSample = image(cv::Range(vec_samRect[12].y1, vec_samRect[12].y1), cv::Range(vec_samRect[12].x1, vec_samRect[12].x2));
	vec_samBlocks[startIndex + 4].matSample = image(cv::Range(vec_samRect[13].y1, vec_samRect[13].y1), cv::Range(vec_samRect[13].x1, vec_samRect[13].x2));
	vec_samBlocks[startIndex + 5].matSample = image(cv::Range(vec_samRect[14].y1, vec_samRect[14].y1), cv::Range(vec_samRect[14].x1, vec_samRect[14].x2));
	vec_samBlocks[startIndex + 6].matSample = image(cv::Range(vec_samRect[15].y1, vec_samRect[15].y1), cv::Range(vec_samRect[15].x1, vec_samRect[15].x2));
	vec_samBlocks[startIndex + 7].matSample = image(cv::Range(vec_samRect[16].y1, vec_samRect[16].y1), cv::Range(vec_samRect[16].x1, vec_samRect[16].x2));
	vec_samBlocks[startIndex + 8].matSample = image(cv::Range(vec_samRect[17].y1, vec_samRect[17].y1), cv::Range(vec_samRect[17].x1, vec_samRect[17].x2));

	//case2，补充之前被遮挡的色块
	image = cv::imread("pic_cam/cam_case2_FR.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	startIndex = 18;										//F面
	vec_samBlocks[startIndex + 0].matSample = image(cv::Range(vec_samRect[0].y1, vec_samRect[0].y1), cv::Range(vec_samRect[0].x1, vec_samRect[0].x2));
	vec_samBlocks[startIndex + 1].matSample = image(cv::Range(vec_samRect[1].y1, vec_samRect[1].y1), cv::Range(vec_samRect[1].x1, vec_samRect[1].x2));
	vec_samBlocks[startIndex + 6].matSample = image(cv::Range(vec_samRect[6].y1, vec_samRect[6].y1), cv::Range(vec_samRect[6].x1, vec_samRect[6].x2));
	vec_samBlocks[startIndex + 7].matSample = image(cv::Range(vec_samRect[7].y1, vec_samRect[7].y1), cv::Range(vec_samRect[7].x1, vec_samRect[7].x2));

	//UB
	vector<SamRec>& vec_samRect = map_pic_id_samRec["UB"];
	//case1
	image = cv::imread("pic_cam/cam_case1_UB.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	startIndex = 0;											//U面
	vec_samBlocks[startIndex + 0].matSample = image(cv::Range(vec_samRect[2].y1, vec_samRect[2].y1), cv::Range(vec_samRect[2].x1, vec_samRect[2].x2));
	vec_samBlocks[startIndex + 1].matSample = image(cv::Range(vec_samRect[5].y1, vec_samRect[5].y1), cv::Range(vec_samRect[5].x1, vec_samRect[5].x2));
	vec_samBlocks[startIndex + 2].matSample = image(cv::Range(vec_samRect[8].y1, vec_samRect[8].y1), cv::Range(vec_samRect[8].x1, vec_samRect[8].x2));
	vec_samBlocks[startIndex + 3].matSample = image(cv::Range(vec_samRect[1].y1, vec_samRect[1].y1), cv::Range(vec_samRect[1].x1, vec_samRect[1].x2));
	vec_samBlocks[startIndex + 4].matSample = image(cv::Range(vec_samRect[4].y1, vec_samRect[4].y1), cv::Range(vec_samRect[4].x1, vec_samRect[4].x2));
	vec_samBlocks[startIndex + 5].matSample = image(cv::Range(vec_samRect[7].y1, vec_samRect[7].y1), cv::Range(vec_samRect[7].x1, vec_samRect[7].x2));
	vec_samBlocks[startIndex + 6].matSample = image(cv::Range(vec_samRect[0].y1, vec_samRect[0].y1), cv::Range(vec_samRect[0].x1, vec_samRect[0].x2));
	vec_samBlocks[startIndex + 8].matSample = image(cv::Range(vec_samRect[6].y1, vec_samRect[6].y1), cv::Range(vec_samRect[6].x1, vec_samRect[6].x2));
	startIndex = 45;										//B面
	vec_samBlocks[startIndex + 0].matSample = image(cv::Range(vec_samRect[15].y1, vec_samRect[15].y1), cv::Range(vec_samRect[15].x1, vec_samRect[15].x2));
	vec_samBlocks[startIndex + 1].matSample = image(cv::Range(vec_samRect[12].y1, vec_samRect[12].y1), cv::Range(vec_samRect[12].x1, vec_samRect[12].x2));
	vec_samBlocks[startIndex + 2].matSample = image(cv::Range(vec_samRect[9].y1, vec_samRect[9].y1), cv::Range(vec_samRect[9].x1, vec_samRect[9].x2));
	vec_samBlocks[startIndex + 3].matSample = image(cv::Range(vec_samRect[16].y1, vec_samRect[16].y1), cv::Range(vec_samRect[16].x1, vec_samRect[16].x2));
	vec_samBlocks[startIndex + 4].matSample = image(cv::Range(vec_samRect[13].y1, vec_samRect[13].y1), cv::Range(vec_samRect[13].x1, vec_samRect[13].x2));
	vec_samBlocks[startIndex + 5].matSample = image(cv::Range(vec_samRect[10].y1, vec_samRect[10].y1), cv::Range(vec_samRect[10].x1, vec_samRect[10].x2));
	vec_samBlocks[startIndex + 6].matSample = image(cv::Range(vec_samRect[17].y1, vec_samRect[17].y1), cv::Range(vec_samRect[17].x1, vec_samRect[17].x2));
	vec_samBlocks[startIndex + 7].matSample = image(cv::Range(vec_samRect[14].y1, vec_samRect[14].y1), cv::Range(vec_samRect[14].x1, vec_samRect[14].x2));
	vec_samBlocks[startIndex + 8].matSample = image(cv::Range(vec_samRect[11].y1, vec_samRect[11].y1), cv::Range(vec_samRect[11].x1, vec_samRect[11].x2));

	//case2，补充之前被遮挡的色块
	image = cv::imread("pic_cam/cam_case2_UB.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	startIndex = 0;											//U面
	vec_samBlocks[startIndex + 7].matSample = image(cv::Range(vec_samRect[3].y1, vec_samRect[3].y1), cv::Range(vec_samRect[3].x1, vec_samRect[3].x2));

	//LD
	vector<SamRec>& vec_samRect = map_pic_id_samRec["LD"];
	//case1
	image = cv::imread("pic_cam/cam_case1_LD.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	startIndex = 36;										//L面
	vec_samBlocks[startIndex + 0].matSample = image(cv::Range(vec_samRect[11].y1, vec_samRect[11].y1), cv::Range(vec_samRect[11].x1, vec_samRect[11].x2));
	vec_samBlocks[startIndex + 1].matSample = image(cv::Range(vec_samRect[14].y1, vec_samRect[14].y1), cv::Range(vec_samRect[14].x1, vec_samRect[14].x2));
	vec_samBlocks[startIndex + 2].matSample = image(cv::Range(vec_samRect[17].y1, vec_samRect[17].y1), cv::Range(vec_samRect[17].x1, vec_samRect[17].x2));
	vec_samBlocks[startIndex + 3].matSample = image(cv::Range(vec_samRect[10].y1, vec_samRect[10].y1), cv::Range(vec_samRect[10].x1, vec_samRect[10].x2));
	vec_samBlocks[startIndex + 4].matSample = image(cv::Range(vec_samRect[13].y1, vec_samRect[13].y1), cv::Range(vec_samRect[13].x1, vec_samRect[13].x2));
	vec_samBlocks[startIndex + 5].matSample = image(cv::Range(vec_samRect[16].y1, vec_samRect[16].y1), cv::Range(vec_samRect[16].x1, vec_samRect[16].x2));
	vec_samBlocks[startIndex + 6].matSample = image(cv::Range(vec_samRect[9].y1, vec_samRect[9].y1), cv::Range(vec_samRect[9].x1, vec_samRect[9].x2));
	vec_samBlocks[startIndex + 7].matSample = image(cv::Range(vec_samRect[7].y1, vec_samRect[12].y1), cv::Range(vec_samRect[12].x1, vec_samRect[12].x2));
	vec_samBlocks[startIndex + 8].matSample = image(cv::Range(vec_samRect[8].y1, vec_samRect[15].y1), cv::Range(vec_samRect[15].x1, vec_samRect[15].x2));
	startIndex = 27;										//D面
	vec_samBlocks[startIndex + 0].matSample = image(cv::Range(vec_samRect[8].y1, vec_samRect[8].y1), cv::Range(vec_samRect[8].x1, vec_samRect[8].x2));
	vec_samBlocks[startIndex + 3].matSample = image(cv::Range(vec_samRect[5].y1, vec_samRect[5].y1), cv::Range(vec_samRect[5].x1, vec_samRect[5].x2));
	vec_samBlocks[startIndex + 4].matSample = image(cv::Range(vec_samRect[4].y1, vec_samRect[4].y1), cv::Range(vec_samRect[4].x1, vec_samRect[4].x2));
	vec_samBlocks[startIndex + 5].matSample = image(cv::Range(vec_samRect[3].y1, vec_samRect[3].y1), cv::Range(vec_samRect[3].x1, vec_samRect[3].x2));
	vec_samBlocks[startIndex + 6].matSample = image(cv::Range(vec_samRect[2].y1, vec_samRect[2].y1), cv::Range(vec_samRect[2].x1, vec_samRect[2].x2));
	vec_samBlocks[startIndex + 7].matSample = image(cv::Range(vec_samRect[1].y1, vec_samRect[1].y1), cv::Range(vec_samRect[1].x1, vec_samRect[1].x2));
	vec_samBlocks[startIndex + 8].matSample = image(cv::Range(vec_samRect[0].y1, vec_samRect[0].y1), cv::Range(vec_samRect[0].x1, vec_samRect[0].x2));

	//case2，补充之前被遮挡的色块
	image = cv::imread("pic_cam/cam_case2_LD.jpg");
	cv::resize(image, image, cv::Size(640, 480));
	startIndex = 18;										//D面
	vec_samBlocks[startIndex + 1].matSample = image(cv::Range(vec_samRect[7].y1, vec_samRect[7].y1), cv::Range(vec_samRect[7].x1, vec_samRect[7].x2));
	vec_samBlocks[startIndex + 2].matSample = image(cv::Range(vec_samRect[6].y1, vec_samRect[6].y1), cv::Range(vec_samRect[6].x1, vec_samRect[6].x2));

	for (int i = 0; i < vec_samBlocks.size(); i++) {		//每个色块记录自己原始的位置
		vec_samBlocks[i].index = i;							//
	}

////计算得到各个采样图的HSV均值
	int cntH150 = 0;

	for (int index = 0; index < vec_samBlocks.size(); index++) {
		int sumH = 0, sumS = 0;
		int cntH = 0, cntS = 0;
		cv::Mat mat_hsv;
		cv::cvtColor(vec_samBlocks[index].matSample, mat_hsv, cv::COLOR_BGR2HSV);
		for (int i = 0; i < mat_hsv.rows; i++) {				//遍历图片每个像素
			for (int j = 0; j < mat_hsv.cols; j++) {
				cv::Point p(j, i);
				if (mat_hsv.at<cv::Vec3b>(p)[0] >= 0 && mat_hsv.at<cv::Vec3b>(p)[0] <= 180) {
					sumH += mat_hsv.at<cv::Vec3b>(p)[0];
					cntH++;
					if (mat_hsv.at<cv::Vec3b>(p)[0] >= 150) cntH150++;
				}
				if (mat_hsv.at<cv::Vec3b>(p)[1] >= 0 && mat_hsv.at<cv::Vec3b>(p)[1] <= 255) {
					sumS += mat_hsv.at<cv::Vec3b>(p)[1];
					cntS++;
				}
			}
		}
		vec_samBlocks[index].meanH = (float)sumH / cntH;
		vec_samBlocks[index].meanH = (float)sumS / cntS;

		if ((float)cntH150 / cntH > 0.03) {							//挑选出H在170-180之间的红色块，避免区间跳跃导致的均值失真
			vec_samBlocks[index].bJudged = true;
			strResult[index] = 'r';
		}
	}

////对S进行排序，取最小的6个作为白色块
	sort(vec_samBlocks.begin(), vec_samBlocks.end(), [](CubeBlock &a, CubeBlock &b) {return a.meanS < b.meanS; });

	int i = 0;									
	while (cntWhite > 0) {
		if (vec_samBlocks[i].bJudged == false) {
			strResult[vec_samBlocks[i].index] = 'w';
			cntWhite--;
		}
		i++;
	}

////对H进行排序，从小到大以此为红色（可能有）、橙色、黄色、绿色、蓝色
	sort(vec_samBlocks.begin(), vec_samBlocks.end(), [](CubeBlock &a, CubeBlock &b) {return a.meanH < a.meanS; });

	for (int i = 0; i < vec_samBlocks.size(); i++) {
		if (vec_samBlocks[i].bJudged == false) {
			if (cntRed > 0) {
				vec_samBlocks[i].bJudged == true;
				strResult[vec_samBlocks[i].index] = 'r';
				cntRed--;
			}
			else if (cntOrange > 0) {
				vec_samBlocks[i].bJudged == true;
				strResult[vec_samBlocks[i].index] = 'o';
				cntOrange--;
			}
			else if (cntYellow > 0) {
				vec_samBlocks[i].bJudged == true;
				strResult[vec_samBlocks[i].index] = 'y';
				cntYellow--;
			}
			else if (cntGreen > 0) {
				vec_samBlocks[i].bJudged == true;
				strResult[vec_samBlocks[i].index] = 'g';
				cntGreen--;
			}
			else if (cntBlue > 0) {
				vec_samBlocks[i].bJudged == true;
				strResult[vec_samBlocks[i].index] = 'b';
				cntBlue--;
			}
		}
	
	}

	return strResult;
}
