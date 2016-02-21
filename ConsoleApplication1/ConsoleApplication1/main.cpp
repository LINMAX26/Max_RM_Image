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
		double t = (double)getTickCount();//Max:��ʼʱ���ȡ

		//��ȡͼ��
		capture >> frame;
		resize(frame, frame, Size(300, 300));            //֡���ظı�
		imshow("��ǰͼ��",frame);
		Mat contours = frame.clone();
		Mat output   = frame.clone();
		cvtColor(Aim,Aim, COLOR_BGR2Lab);
		cvtColor(contours, contours, COLOR_BGR2Lab);
		
		SrcImageBinarization(output,Aim,contours,40);






		//����ʱ�����
		t = ((double)getTickCount() - t) / getTickFrequency();
		waitKey(30);
		cout << "time is:" << t << endl;
	}
	return 0;
}