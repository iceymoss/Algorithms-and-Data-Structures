#include <iostream>
#include "SortTestHelper.h"
#include "insertionSort.h"
using namespace std;
// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge(T arr[], int l, int mid, int r){

   
    //* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间
    T aux[r-l+1];
    //T *aux = new T[r-l+1];

    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
            arr[k] = aux[j-l]; j ++;
        }
        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i-l]; i ++;
        }
        else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i-l]; i ++;
        }
        else{  // 左半部分所指元素 >= 右半部分所指元素
            arr[k] = aux[j-l]; j ++;
        }
    }

    //delete[] aux;
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r){

    if( l >= r )  //递归限制条件
        return;
    //将数组进行切分
    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    //归并操作
    __merge(arr, l, mid, r);
}
//构造函数
template<typename T>
void mergeSort(T arr[], int n){
    //函数调用
    //索引我0的数组，该数组一共n个元素
    __mergeSort( arr , 0 , n-1 );
}




int main() {

    // Merge Sort是我们学习的第一个O(nlogn)复杂度的算法
    // 可以在1秒之内轻松处理100万数量级的数据
    // 注意：不要轻易尝试使用SelectionSort, InsertionSort或者BubbleSort处理100万级的数据
    // 否则，你就见识了O(n^2)的算法和O(nlogn)算法的本质差异：）
    int n = 5000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    // 对于近乎有序的数组, 数组越有序, InsertionSort的时间性能越趋近于O(n)
    // 所以可以尝试, 当swapTimes比较大时, MergeSort更快
    // 但是当swapTimes小到一定程度, InsertionSort变得比MergeSort快
    int swapTimes = 10;
    assert( swapTimes >= 0 );

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}