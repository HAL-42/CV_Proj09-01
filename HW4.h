/*
 * @Date: 2019-06-24 02:12:14
 * @Author: Xiaobo Yang
 * @Email: hal_42@zju.edu.cn
 * @Company: Zhejiang University
 * @LastEditors: Xiaobo Yang
 * @LastEditTime: 2019-06-24 02:35:55
 * @Description: Common include here
 */


#ifndef _HW2_H_
#define _HW2_H_

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
#include <iostream>
#include <exception>

int WriteImg(const Mat img, String img_name = NULL, bool is_show = true);
Mat ReadImg(String img_path, int option = 0);

#endif

