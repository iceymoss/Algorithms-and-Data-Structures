#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "SortTestHeper.h"
using namespace std;
//使用模板类型
template<typename T>
//heapify构造函数
//将数组传入堆中，再从堆中取出来
void heapify1(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    //将数组传入堆中
    for(int i=0; i<n; i++){
        maxheap.insert(arr[i]);
    }
    //将堆中的元素放回数组
    for(int i=n; i<=0; i--){
        arr[i] = maxheap.extractMax();
    }


}

int main() {
    // 比较 Merge Sort, 三种 Quick Sort 和本节介绍的两种 Heap Sort 的性能效率
// 注意, 这几种排序算法都是 O(nlogn) 级别的排序算法


        return 0;
    }


