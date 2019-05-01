#ifndef CUBE_RECOGNIZER_H
#define CUBE_RECOGNIZER_H

#define RECOG_SIMILARITY_COE 0.25		//ʶ������ϵ������ȡɫ���з�����ֵ�����ص���ռ�������ڸ�ֵʱ�ж���ȡɫ��Ϊ��Ӧ��ɫ

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
	int index;					//ɫ�����
	cv::Mat matSample;			//����ͼ
	int meanH;					//H��ֵ
	int meanS;					//S��ֵ
	int meanV;
	//float ratioH170;			//Hֵ����170�����ص�����������жϸ�ֵ����ĺ�ɫ�飬���������䵼�µľ�ֵʧ��
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

void sampleFromPic(cv::Mat image, QString picName, int caseID);
string recognizeNew();

#endif
