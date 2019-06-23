/*
 * @Date: 2019-06-24 02:10:06
 * @Author: Xiaobo Yang
 * @Email: hal_42@zju.edu.cn
 * @Company: Zhejiang University
 * @LastEditors: Xiaobo Yang
 * @LastEditTime: 2019-06-24 03:41:01
 * @Description: Library for HW4
 */


#ifndef _MORPH_LIB_H_
#define _MORPH_LIB_H_

Mat Dilation(const Mat A, const Mat B);
Mat Erosion(const Mat A, const Mat B);
Mat Intersection(const Mat A, const Mat B);
Mat Differece(const Mat A, const Mat B);
Mat Complementation(const Mat A);
static bool IsBelongTo(const Mat A, const Mat B);
static bool IsIntersectedTo(const Mat A, const Mat B);

#endif