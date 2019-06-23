/*
 * @Date: 2019-06-24 02:10:53
 * @Author: Xiaobo Yang
 * @Email: hal_42@zju.edu.cn
 * @Company: Zhejiang University
 * @LastEditors: Xiaobo Yang
 * @LastEditTime: 2019-06-24 03:49:16
 * @Description: Library for HW4
 */

#include "HW4.h"
#include "morph_lib.h"

Mat Erosion(const Mat A, const Mat B){
    Mat padded_A;
    copyMakeBorder(A, padded_A, 1, 1, 1, 1, BORDER_CONSTANT, Scalar::all(0));
    Mat rslt(A.size(), CV_8UC1, Scalar::all(0));
    for(int row = 1; row <= A.size[0]; row++){
        for(int col = 1; col <= A.size[1]; col++){
            Mat roi_padded_A = padded_A(Rect(col-1, row-1, 3, 3));
            if(IsBelongTo(B, roi_padded_A)){
                rslt.at<uchar>(row-1, col-1) = 255;
            }
        }
    }
    return rslt;
}

Mat Dilation(const Mat A, const Mat B){
    Mat padded_A;
    copyMakeBorder(A, padded_A, 1, 1, 1, 1, BORDER_CONSTANT, Scalar::all(0));
    Mat rslt(A.size(), CV_8UC1, Scalar::all(0));
    for(int row = 1; row <= A.size[0]; row++){
        for(int col = 1; col <= A.size[1]; col++){
            Mat roi_padded_A = padded_A(Rect(col-1, row-1, 3, 3));
            if(IsIntersectedTo(B, roi_padded_A)){
                rslt.at<uchar>(row-1, col-1) = 255;
            }
        }
    }
    return rslt;
}

Mat Intersection(const Mat A, const Mat B){
    if(A.size() != B.size() || A.type() != B.type()){
        std::cerr << "Size of A, B are different!!!" << std::endl;
    }

    Mat rslt(A.size(), CV_8UC1, Scalar::all(0));
    auto it_A = A.begin<uchar>();
    auto it_B = B.begin<uchar>();
    auto it_rslt = rslt.begin<uchar>();
    for(; it_A < A.end<uchar>(); it_A++){
        if(*it_A > 0 && *it_B > 0){
            *it_rslt = 255;
        }
        it_B++;
        it_rslt++;
    }
    return rslt;
}

Mat Differece(const Mat A, const Mat B){
    if(A.size() != B.size() || A.type() != B.type()){
        std::cerr << "Size of A, B are different!!!" << std::endl;
    }

    Mat rslt(A.size(), CV_8UC1, Scalar::all(0));
    auto it_A = A.begin<uchar>();
    auto it_B = B.begin<uchar>();
    auto it_rslt = rslt.begin<uchar>();
    for(; it_A < A.end<uchar>(); it_A++){
        if(*it_A > 0 && *it_B == 0){
            *it_rslt = 255;
        }
        it_B++;
        it_rslt++;
    }
    return rslt;
}

Mat Complementation(const Mat A){
    Mat rslt(A.size(), CV_8UC1, Scalar::all(0));
    auto it_A = A.begin<uchar>();
    auto it_rslt = rslt.begin<uchar>();
    for(; it_A < A.end<uchar>(); it_A++){
        if(*it_A == 0){
            *it_rslt = 255;
        }
        it_rslt++;
    }
    return rslt;
}

static bool IsBelongTo(const Mat A, const Mat B){
    if(A.size() != B.size() || A.type() != B.type()){
        std::cerr << "Size of A, B are different!!!" << std::endl;
    }

    bool flag = true;
    auto it_a = A.begin<uchar>();
    auto it_b = B.begin<uchar>();
    for(; it_a < A.end<uchar>(); it_a++){
        if(*it_a > 0 && *it_b == 0){
            flag = false;
            break;
        }
        it_b++;
    }
    return flag;
}

static bool IsIntersectedTo(const Mat A, const Mat B){
    if(A.size() != B.size() || A.type() != B.type()){
        std::cerr << "Size of A, B are different!!!" << std::endl;
    }

    bool flag = false;
    auto it_a = A.begin<uchar>();
    auto it_b = B.begin<uchar>();
    for(; it_a < A.end<uchar>(); it_a++){
        if(*it_a > 0 && *it_b > 0){
            flag = true;
            break;
        }
        it_b++;
    }
    return flag;
}