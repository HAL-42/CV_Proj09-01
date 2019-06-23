/*
 * @Date: 2019-06-24 02:08:59
 * @Author: Xiaobo Yang
 * @Email: hal_42@zju.edu.cn
 * @Company: Zhejiang University
 * @LastEditors: Xiaobo Yang
 * @LastEditTime: 2019-06-24 04:29:04
 * @Description: main
 */

#include "HW4.h"
#include "morph_lib.h"

int main(){
    Mat A = ReadImg(".\\fig\\head.tif", 0);
    Mat B(3, 3, CV_8UC1, Scalar::all(255));
    Mat boundary = Differece(A, Erosion(A, B));
    WriteImg(boundary, ".\\fig\\head_boundary.tif", true);
	waitKey(0);
    return 0;
}

