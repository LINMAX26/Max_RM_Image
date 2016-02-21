#include <opencv2/opencv.hpp>
#include <iostream>
#include "Max_GetExpectionTargetColor.h"
using namespace cv;
using namespace std;

//初始默认目标颜色期望值
#define INITTARGETCOLOR_R 200
#define INITTARGETCOLOR_G 50
#define INITTARGETCOLOR_B 60
//定义期望目标RGB结构体
struct ExpectionTargetColor
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};
//改变期望目标颜色
static ExpectionTargetColor ChangeExpectionTargetColor(ExpectionTargetColor Aim)
{
	cout << "请输入RGB的大小" << endl;
	cout << "R:"; cin >> Aim.R;
	cout << "G:"; cin >> Aim.G;
	cout << "B:"; cin >> Aim.B;
	return Aim;

}
//显示期望目标颜色
static Mat ShowExpectionTargetColor(ExpectionTargetColor Aim)
{
	Mat AIM(1, 1, CV_8UC3);
	Mat target(1, 1, CV_8UC3);

	unsigned char *data = AIM.ptr<unsigned char>(0);
	data[0] = Aim.B;
	data[1] = Aim.G;
	data[2] = Aim.R;
	namedWindow("理想目标颜色", WINDOW_NORMAL);
	imshow("理想目标颜色", AIM);
	//cvtColor(AIM, target, COLOR_BGR2Lab);
	return AIM;
}
//获取期望目标颜色
Mat getExpectionTargetColor()
{
	ExpectionTargetColor Aim;
	Aim.R = INITTARGETCOLOR_R;
	Aim.G = INITTARGETCOLOR_G;
	Aim.B = INITTARGETCOLOR_B;
	Mat res(1, 1, CV_8UC3);
	cout << "当前目标RGB：" << Aim.R << "\t" << Aim.G << "\t" << Aim.B << endl;
	cout << "是否改变目标颜色？Y/N";
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
