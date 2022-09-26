//
// Created by 风 on 2021/2/3.
//

#ifndef MERGE_SORT_INSERTSORT_H
#define MERGE_SORT_INSERTSORT_H
#include<iostream>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {

        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

#endif //MERGE_SORT_INSERTSORT_H
