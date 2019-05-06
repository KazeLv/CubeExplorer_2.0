#ifndef CUBE_EXPLORER_H
#define CUBE_EXPLORER_H

#define STRATEGY 1

#include<vector>
#include<string>
#include<fstream>
#include<iostream>

//��ʾĳ����е��״̬�Ľṹ����ΪHandState�ĳ�Ա
struct HandStateForOne {
	bool isReady = true;	//��е���Ƿ�����ȷ�ķ��򣨼���ʼ״̬��U-D���򣬲�������һֻ��е�ֵ�ת����
	bool isTight = true;	//��е���Ƿ�н�
};

//��ʾ��е��״̬�Ľṹ������left��ʾ���֣�right��ʾ����
struct HandState {
	HandStateForOne left;
	HandStateForOne right;
	//���췽��������CubicExplore��Ĺ��캯����Ĭ�ϲ���������
	HandState(bool lr=true,bool lt=true,bool rr=true,bool rt=true){
		left.isReady = lr;
		left.isTight = lt;
		right.isReady = rr;
		right.isTight = rt;
	}
};

//��ʾ��е�ָ�������ö��
enum class Operation {
	R,		//����˳ʱ��ת��
	_R ,	//������ʱ��ת��
	F,		//����˳ʱ��ת��
	_F ,	//������ʱ��ת��
	R2 ,	//R��ת��180��
	F2 ,	//F��ת��180��
	LeftLoose,	//�����ɿ�		
	LeftTight,	//���ּн�
	RightLoose,	//�����ɿ�
	RightTight	//���ּн�
};

using namespace std;

ostream& operator<<(ostream&, const Operation&);

//��ʾħ���������һ����
class CubeExplorer {
private:
	vector<string> vecStrSerial;		//����ת����Ĵ��������ַ���
	vector<string> strNorVec;			//string����������ָ��õ���һ������ʾ������ʽ�������ַ���
	vector<Operation> macVec;			//�Զ���ö������Operation����������ת����õ��Ļ�е�ֲ�������
	string target;						//�ַ������洢��Ҫ�������ͨ��ʽ����
public:
	HandState handState;	//�Զ�����HandState���ͣ���ʾ��ǰ��е��״̬
	int transCnt = 0;					//��¼ħ����ת����
	
	CubeExplorer(char* cstr="", HandState& hs=HandState(true,true,true,true));
	
	friend ostream& operator<<(ostream&, const Operation&);		//��Ԫ���������غ���֧��Operation���ͺ�cout��ֱ��ʹ�ã���Ҫ���ڵ���

	void SetTarget(string);
	vector<string>& GetVecStrSerial();

	//���²����������ħ��������װ��еצ����
	void OnR(vector<string>::iterator&);		//R��˳ʱ��ת��
	void On_R(vector<string>::iterator&);		//R����ʱ��ת��
	void OnR2(vector<string>::iterator&);		//R��ת��180��
	void OnF(vector<string>::iterator&);		//F������
	void On_F(vector<string>::iterator&);		//
	void OnF2(vector<string>::iterator&);		//
	void OnRR(vector<string>::iterator&);		//ħ����R��˳ʱ�뷽������ת��
	void On_RR(vector<string>::iterator&);		//ħ����R����ʱ�뷽������ת��
	void OnRR2(vector<string>::iterator&);		//ħ����R����ʱ�뷽������ת��180��
	void OnFF(vector<string>::iterator&);		//F����
	void On_FF(vector<string>::iterator&);		//
	void OnFF2(vector<string>::iterator&);		//

	void GetLeftReadyAndTight();	//ʹ���ָ�λ���н���U-D״̬(90/270��״̬)
	void GetRightReadyAndTight();	//ʹ���ָ�λ���н���U-D״̬(90/270��״̬)
	void LeftLoose();				//�ɿ�����
	void LeftTight();				//�н�����
	void LeftReady();				//���ָ�λ��U-D״̬(90/270��״̬)
	void RightLoose();				//�ɿ�����
	void RightTight();				//�н�����
	void RightReady();				//���ָ�λ��U-D״̬(90/270��״̬)
	void GetShortestWay();			//���ĳ�Ա��������target�д洢����ͨ��ʽ����ת��Ϊ��е�ֲ������в��洢��macVec������
	void ShowOperations();			//��ӡ�������У���Ҫ���ڵ��ԺͲ���
	void Reset();
};


#endif