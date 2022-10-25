/*************************************************************************
 > File Name: func.hpp
 > Author: united_pooh
 > Mail: united_pooh@outlook.com
 > Created Time: 2022年10月18日 星期二 23时36分04秒
 ************************************************************************/
#ifndef FUNC_H
#define FUNC_H
#include "opencv2/opencv.hpp"
#include "iostream"

using namespace std;
using namespace cv;

Mat AveragePooling(Mat && img_, int && step_ = 2, const int & border_type_ = BORDER_REFLECT_101){
	cv::copyMakeBorder(img_,img_,0,step_ - (img_.rows % step_),0,step_ - (img_.cols % step_),border_type_,3);
	int width_ = img_.cols;
	int height_ = img_.rows;
	int channel_ = img_.channels();
	int val_ = 0;
	Mat new_img_ = Mat::zeros(height_ / step_,width_ / step_,CV_8UC3);
	for(int i = 0;i < height_;i += step_){
		for(int j = 0;j < width_;j += step_){
			for(int n = 0;n < channel_;n++){
				val_ = 0;
				for(int i_ = 0;i_ < step_;i_++){
					for(int j_ = 0;j_ < step_;j_++){
						val_ += img_.at<cv::Vec3b>(i + i_,j + j_)[n];
					}
				}
				val_ /= step_ * step_;
				new_img_.at<Vec3b>(i/step_,j/step_)[n] = val_;
			}
		}
	}
	return new_img_;
}
Mat AveragePooling(const Mat & img_, int && step_ = 2 , const int & border_type_ = BORDER_REFLECT_101){
	Mat copy_img_;
	cv::copyMakeBorder(img_,copy_img_,0,step_ - (img_.rows % step_),0,step_ - (img_.cols % step_),border_type_,3);
	int width_ = copy_img_.cols;
	int height_ = copy_img_.rows;
	int channel_ = img_.channels();
	int val_ = 0;
	Mat new_img_ = Mat::zeros(height_ / step_,width_ / step_,CV_8UC3);
	for(int i = 0;i < height_;i += step_){
		for(int j = 0;j < width_;j += step_){
			for(int n = 0;n < channel_;n++){
				val_ = 0;
				for(int i_ = 0;i_ < step_;i_++){
					for(int j_ = 0;j_ < step_;j_++){
						val_ += copy_img_.at<cv::Vec3b>(i + i_,j + j_)[n];
					}
				}
				val_ /= step_ * step_;
				new_img_.at<Vec3b>(i/step_,j/step_)[n] = val_;
			}
		}
	}
	return new_img_;
}
Mat MaxPooling(const Mat & img_, const int & step_ = 2, const int & border_type_ = BORDER_REFLECT_101){
	Mat copy_img_;
	cv::copyMakeBorder(img_,copy_img_,0,step_ - (img_.rows % step_),0,step_ - (img_.cols % step_),border_type_,3);
	int width_ = copy_img_.cols;
	int height_ = copy_img_.rows;
	int channel_ = img_.channels();
	int max_ = 0;
	Mat new_img_ = Mat::zeros(height_ / step_,width_ / step_,CV_8UC3);
	for(int i = 0;i < height_;i += step_){
		for(int j = 0;j < width_;j += step_){
			for(int n = 0;n < channel_;n++){
				max_ = 0;
				for(int i_ = 0;i_ < step_;i_++){
					for(int j_ = 0;j_ < step_;j_++){
						if(copy_img_.at<cv::Vec3b>(i + i_,j + j_)[n] > max_)
							max_ = copy_img_.at<cv::Vec3b>(i+i_,j+j_)[n];
					}
				}
				new_img_.at<Vec3b>(i/step_,j/step_)[n] = max_;
			}
		}
	}
	return new_img_;
}
Mat MaxPooling(Mat && img_, const int & step_ = 2, const int & border_type_ = BORDER_REFLECT_101){
	cv::copyMakeBorder(img_,img_,0,step_ - (img_.rows % step_),0,step_ - (img_.cols % step_),border_type_,3);
	int width_ = img_.cols;
	int height_ = img_.rows;
	int channel_ = img_.channels();
	int max_ = 0;
	Mat new_img_ = Mat::zeros(height_ / step_,width_ / step_,CV_8UC3);
	for(int i = 0;i < height_;i += step_){
		for(int j = 0;j < width_;j += step_){
			for(int n = 0;n < channel_;n++){
				max_ = 0;
				for(int i_ = 0;i_ < step_;i_++){
					for(int j_ = 0;j_ < step_;j_++){
						if(img_.at<cv::Vec3b>(i + i_,j + j_)[n] > max_)
							max_ = img_.at<cv::Vec3b>(i+i_,j+j_)[n];
					}
				}
				new_img_.at<Vec3b>(i/step_,j/step_)[n] = max_;
			}
		}
	}
	return new_img_;
}

#endif
