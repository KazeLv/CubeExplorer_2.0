#ifndef CUBE_RECOGNIZER_H
#define CUBE_RECOGNIZER_H

#define RECOG_SIMILARITY_COE 0.25		//识别相似系数，当取色块中符合阈值的像素点所占比例大于该值时判定该取色块为对应颜色

#include<iostream>
#include<qmap.h>
#include<qdir.h>
#include<qtextstream.h>
#include<core/core.hpp>
#include<opencv2/opencv.hpp>
#include<highgui/highgui.hpp>
#include<fstream>
#include<vector>

using namespace std;

typedef struct{
	int x1, x2;
	int y1, y2;
}SamRec;

typedef struct _hsv{
	int iLowH, iHighH;
	int iLowS, iHighS;
	int iLowV, iHighV;

	bool operator==(const struct _hsv& target) {
		return (target.iLowH == this->iLowH) && (target.iHighH == this->iHighH) && (target.iLowS == this->iLowS) && (target.iHighS == this->iHighS) && (target.iLowV == this->iLowV) && (target.iHighV == this->iHighV);
	}
}HSV;

struct CubeBlock {
	int index;
	cv::Mat matSample;
	int meanH;
	int meanS;
	bool bJudged = false;
};

void iniHSVMap();
QMap<QString, QMap<QString, HSV>>& getHSVMap();
void saveHSVData();

void iniRecMap(); 
QMap<QString, vector<SamRec>>& getSamRecMap();
void setSampleRec(QString strFaceGroup, SamRec rect2set, int nFaceID, int nFockID);

void iniRecogVars();
QMap<QString, vector<cv::Mat>>& getLastRecogMatMap();
int isColor(cv::Mat imgHSV, QString color, QString face);
void judgeColor(cv::Mat image, QString picName, int caseID);
string recognize();

#endif
