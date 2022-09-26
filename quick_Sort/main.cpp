#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){

    swap(arr[l] , arr[rand()%(r-l+1)+l]);

    T v = arr[l];

    int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
        }

    swap( arr[l] , arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {

    if( r - l <= 16 ){
        insertionSort(arr, l, r);
       return;
    }
    //if(l >= r)
    //    return;

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1 );
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));

    __quickSort(arr, 0, n-1);
}


// 比较Merge Sort和Quick Sort两种排序算法的性能效率
// 两种排序算法虽然都是O(nlogn)级别的, 但是Quick Sort算法有常数级的优势
// Quick Sort要比Merge Sort快, 即使我们对Merge Sort进行了优化
int main() {

    int n = 1000000;

    // 测试1 一般性测试
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    return 0;
}