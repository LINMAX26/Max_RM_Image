#include <opencv2\opencv.hpp>
#include "Max_SrcImageProcessing.h"
#include <iostream>
using namespace cv;
using namespace std;
#define abs(x) ((x>0)?(x):-(x))





//显示初始二值化后的图像
static void ShowBinarizationImage(Mat Image)
{
	namedWindow("初始二值化后的图像", WINDOW_NORMAL);
	imshow("初始二值化后的图像",Image);
}

//初始图像二值化
void SrcImageBinarization(Mat output,Mat target,Mat input, int ThresholdValue)
{
    //Mat output = input.clone();
	int nr = input.rows;
	int nl = input.cols*input.channels();//Max：为何乘以通道？

//	cvtColor(target, target, COLOR_BGR2Lab); //输入图像的颜色空间转换  目标为lab空间 Max：Lab空间指亮度色彩空间
	
	cout << target;
//	cvtColor(input, input, COLOR_BGR2Lab); //输入图像的颜色空间转换  目标为lab空间 Max：Lab空间指亮度色彩空间
    int *tar = target.ptr<int>(0);
	for (int i = 0; i < nr; i++)
	{
	    char *data = input.ptr<char>(i);
		unsigned char *data_out = output.ptr<unsigned char>(i);
		for (int j = 0; j < nl; j += 3)
		{
			if ((abs(data[j + 1] - tar[1]) + abs(data[j + 2] - tar[2])) <ThresholdValue)//Max:二值化像素，threshold_value为临界点
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

	cvtColor(output, output, COLOR_BGR2GRAY);             //为了使用边界查找函数使用灰度图像//Max:二值化后的图像装换为灰度图像
	
	Mat x(5, 5, CV_8UC1, Scalar(255));                    //形态学运算内核
	erode(output, output, x); //Max:图像腐蚀
	dilate(output, output, Mat());//Max：图像膨胀，去除躁点                         //形态学运算
	

	//namedWindow("初始二值化", WINDOW_NORMAL);
	//imshow("初始二值化", output);


	ShowBinarizationImage(output);
	//return output;
}

//i++*i++*i++





