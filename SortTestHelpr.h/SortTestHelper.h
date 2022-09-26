//
// Created by liuybobobo on
//

#ifndef SELECTIONSORT_SORTTESTHELPER_R
#define SELECTIONSORT_SORTTESTHELPER_R
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;


namespace SortTestHelper
{
    //生成n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){

        assert( rangeL <= rangeR);
        int *arr = new int [n];
        srand(time(NULL));
        for(int i = 0;i < n; i++)
            arr[n] = rand() % ( rangeL - rangeR + 1) + rangeR;
        return arr;

    }

}
#endif