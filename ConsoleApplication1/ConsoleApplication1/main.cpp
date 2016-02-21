#include <opencv2/opencv.hpp>
#include <iostream>
#include "My_Inc.h"

using namespace cv;
using namespace std;






int main()
{
	VideoCapture capture(1);
	Mat frame;
	
	Mat Aim=getExpectionTargetColor();

	while (1)
	{
		double t = (double)getTickCount();//Max:初始时间获取

		//获取图像
		capture >> frame;
		resize(frame, frame, Size(300, 300));            //帧像素改变
		imshow("当前图像",frame);
		Mat contours = frame.clone();
		Mat output   = frame.clone();
		cvtColor(Aim,Aim, COLOR_BGR2Lab);
		cvtColor(contours, contours, COLOR_BGR2Lab);
		
		SrcImageBinarization(output,Aim,contours,40);






		//运行时间计算
		t = ((double)getTickCount() - t) / getTickFrequency();
		waitKey(30);
		cout << "time is:" << t << endl;
	}
	return 0;
}