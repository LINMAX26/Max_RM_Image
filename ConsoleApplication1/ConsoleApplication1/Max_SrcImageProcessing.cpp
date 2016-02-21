#include <opencv2\opencv.hpp>
#include "Max_SrcImageProcessing.h"
#include <iostream>
using namespace cv;
using namespace std;
#define abs(x) ((x>0)?(x):-(x))





//��ʾ��ʼ��ֵ�����ͼ��
static void ShowBinarizationImage(Mat Image)
{
	namedWindow("��ʼ��ֵ�����ͼ��", WINDOW_NORMAL);
	imshow("��ʼ��ֵ�����ͼ��",Image);
}

//��ʼͼ���ֵ��
void SrcImageBinarization(Mat output,Mat target,Mat input, int ThresholdValue)
{
    //Mat output = input.clone();
	int nr = input.rows;
	int nl = input.cols*input.channels();//Max��Ϊ�γ���ͨ����

//	cvtColor(target, target, COLOR_BGR2Lab); //����ͼ�����ɫ�ռ�ת��  Ŀ��Ϊlab�ռ� Max��Lab�ռ�ָ����ɫ�ʿռ�
	
	cout << target;
//	cvtColor(input, input, COLOR_BGR2Lab); //����ͼ�����ɫ�ռ�ת��  Ŀ��Ϊlab�ռ� Max��Lab�ռ�ָ����ɫ�ʿռ�
    int *tar = target.ptr<int>(0);
	for (int i = 0; i < nr; i++)
	{
	    char *data = input.ptr<char>(i);
		unsigned char *data_out = output.ptr<unsigned char>(i);
		for (int j = 0; j < nl; j += 3)
		{
			if ((abs(data[j + 1] - tar[1]) + abs(data[j + 2] - tar[2])) <ThresholdValue)//Max:��ֵ�����أ�threshold_valueΪ�ٽ��
			{
				data_out[j] = 255;
				data_out[j + 1] = 255;
				data_out[j + 2] = 255;
			}
			else
			{
				data_out[j] = 0;
				data_out[j + 1] = 0;
				data_out[j + 2] = 0;
			}
		}
	}

	cvtColor(output, output, COLOR_BGR2GRAY);             //Ϊ��ʹ�ñ߽���Һ���ʹ�ûҶ�ͼ��//Max:��ֵ�����ͼ��װ��Ϊ�Ҷ�ͼ��
	
	Mat x(5, 5, CV_8UC1, Scalar(255));                    //��̬ѧ�����ں�
	erode(output, output, x); //Max:ͼ��ʴ
	dilate(output, output, Mat());//Max��ͼ�����ͣ�ȥ�����                         //��̬ѧ����
	

	//namedWindow("��ʼ��ֵ��", WINDOW_NORMAL);
	//imshow("��ʼ��ֵ��", output);


	ShowBinarizationImage(output);
	//return output;
}

//i++*i++*i++





