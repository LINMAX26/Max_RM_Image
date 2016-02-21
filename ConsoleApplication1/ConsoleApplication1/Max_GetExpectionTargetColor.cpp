#include <opencv2/opencv.hpp>
#include <iostream>
#include "Max_GetExpectionTargetColor.h"
using namespace cv;
using namespace std;

//��ʼĬ��Ŀ����ɫ����ֵ
#define INITTARGETCOLOR_R 200
#define INITTARGETCOLOR_G 50
#define INITTARGETCOLOR_B 60
//��������Ŀ��RGB�ṹ��
struct ExpectionTargetColor
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};
//�ı�����Ŀ����ɫ
static ExpectionTargetColor ChangeExpectionTargetColor(ExpectionTargetColor Aim)
{
	cout << "������RGB�Ĵ�С" << endl;
	cout << "R:"; cin >> Aim.R;
	cout << "G:"; cin >> Aim.G;
	cout << "B:"; cin >> Aim.B;
	return Aim;

}
//��ʾ����Ŀ����ɫ
static Mat ShowExpectionTargetColor(ExpectionTargetColor Aim)
{
	Mat AIM(1, 1, CV_8UC3);
	Mat target(1, 1, CV_8UC3);

	unsigned char *data = AIM.ptr<unsigned char>(0);
	data[0] = Aim.B;
	data[1] = Aim.G;
	data[2] = Aim.R;
	namedWindow("����Ŀ����ɫ", WINDOW_NORMAL);
	imshow("����Ŀ����ɫ", AIM);
	//cvtColor(AIM, target, COLOR_BGR2Lab);
	return AIM;
}
//��ȡ����Ŀ����ɫ
Mat getExpectionTargetColor()
{
	ExpectionTargetColor Aim;
	Aim.R = INITTARGETCOLOR_R;
	Aim.G = INITTARGETCOLOR_G;
	Aim.B = INITTARGETCOLOR_B;
	Mat res(1, 1, CV_8UC3);
	cout << "��ǰĿ��RGB��" << Aim.R << "\t" << Aim.G << "\t" << Aim.B << endl;
	cout << "�Ƿ�ı�Ŀ����ɫ��Y/N";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'Y':
	case 'y':Aim = ChangeExpectionTargetColor(Aim); break;
	case 'N':
	case 'n':
	default:
		break;
	}
	res = ShowExpectionTargetColor(Aim);
	return res;
}
