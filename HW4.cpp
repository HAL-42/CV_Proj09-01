/*
 * @Date: 2019-06-24 03:50:06
 * @Author: Xiaobo Yang
 * @Email: hal_42@zju.edu.cn
 * @Company: Zhejiang University
 * @LastEditors: Xiaobo Yang
 * @LastEditTime: 2019-06-24 03:50:45
 * @Description: General Function for HW4
 */


#include "HW4.h"
#include "morph_lib.h"

int WriteImg(const Mat img, String img_name, bool is_show)
{
	Mat show_img = img.clone();
	if (show_img.type() == CV_32FC1) {
		normalize(show_img, show_img, 0, 255, NORM_MINMAX);
		show_img.convertTo(show_img, CV_8UC1);
	}

	try {
		if (!img_name.empty()) {
			imwrite(img_name, show_img);
		}
		if (is_show) {
			namedWindow(img_name, WINDOW_NORMAL);
			imshow(img_name, show_img);
		}
	}
	catch (std::runtime_error e) {
		std::cerr << "Something Wrong when Wrting Image to " << img_name << ":" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

Mat ReadImg(String img_path, int option)
{
	Mat img = imread(img_path, option);
	if (img.empty()) {
		std::cerr << "Something Wrong when Read Image at " << img_path << std::endl;
	}
	return img;
}
