//
// Created by atri on 22-10-25.
//
#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

#include "func.hpp"

using namespace std;
using namespace cv;
int main(){
	cv::Mat image_ = imread("/home/atri/c++projects/MyOpencvFunc/test.png");
	cv::imshow("ATRI",image_);
	waitKey(0);
	destroyAllWindows();
	return 0;
}