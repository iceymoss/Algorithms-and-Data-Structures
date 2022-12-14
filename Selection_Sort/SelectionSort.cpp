#include <iostream>
#include<string>
#include<algorithm>
#include "students.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

int main() {

    // 测试模板函数，传入整型数组
    int n = 100000;
    int  *arr = SortTestHelper::generateRandomArray(n,0, 100000);
    selectionSort( arr ,n );
    for( int i = 0 ; i < n ; i ++ )
        cout<<arr[i]<<" ";
    cout<<endl;
    SortTestHelper::testSort("Selection Sort", selectionSort,arr,n);

    delete[] arr;

    return 0;
}