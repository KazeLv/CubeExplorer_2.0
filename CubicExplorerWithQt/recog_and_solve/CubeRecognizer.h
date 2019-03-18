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

	bool operator==(struct _hsv& target) {
		return (target.iLowH == this->iLowH) && (target.iHighH == this->iHighH) && (target.iLowS == this->iLowS) && (target.iHighS == this->iHighS) && (target.iLowV == this->iLowV) && (target.iHighV == this->iHighV);
	}
}HSV;

void iniHSVMap();
QMap<QString, QMap<QString, HSV>>& getHSVMap();
void saveHSVData();

void iniRecMap(); 
QMap<QString, vector<SamRec>>& getSamRecMap();
void setSampleRec(QString strFaceGroup, SamRec rect2set, int nFaceID, int nFockID);

//Color Recognition
int Color(cv::Mat imgHSV, QString color, QString Face);

//unused
void ColorTest(cv::Mat imgHSV, string c);
void FillBlocks(cv::Mat& A, string color, int num);
void getHSV(cv::Mat hsv, int x, int y);
void PrintHSV(cv::Mat img, string hsv_name);
void JudgeColor(cv::Mat &image, cv::Mat& Blank, string ColorName, string CaseName, string color[], vector<SamRec> &Ps);
string Print_str(string color[10], vector <string> standardcolor);
void Sample_Reset(vector<SamRec> &Sample_RF, vector<SamRec> &Sample_BU, vector<SamRec> &Sample_LD);
string Recognition();
void Empty_Color(string Bcolor[], string Dcolor[], string Fcolor[], string Lcolor[], string Rcolor[], string Ucolor[]);
void Capture(string Case);
void Show();
void DrawLine(cv::Mat image, string c, vector<SamRec> &Sample_RF, vector<SamRec> &Sample_BU, vector<SamRec> &Sample_LD);

#endif
