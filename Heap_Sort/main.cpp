#include <iostream>

using namespace std;
//原始__shiftDown
//使用模板T
/*template<typename T>
//void  __shiftDown(T arr[], int n, int k){
    while(2*k+1 < n){
        //左孩子索引为j = k*2 + 1
        int j = k*2 + 1;
        //左孩子存在且左孩子大于右孩子
        if(j+1 < n && arr[j] < arr[j+1])
            j++;
        if(arr[k] >= arr[j])
            break;

        swap(arr[j], arr[j]);
        j = k;
    }

}*/

//这里对__shiftDown的优化
//优化逻辑为将swap换成了赋值
template<typename T>
void shiftDown(T arr[], int n, int k){
    T  e = arr[k];
    while(k*2 + 1 < n){
        int j = 2*k+1;
        if(j < n && arr[j] < arr[j+1]){
            j++;
        }

        if(e>arr[j]){
            break;
        }
        arr[k] = arr[j];

    }
}


template<typename T>
void HeapSort(T arr, int n ){
    // 注意，此时我们的堆是从0开始索引的
    // 从(最后一个元素的索引-1)/2开始
    // 最后一个元素的索引 = n-1
    for(int i = (n-1-1)/2; i >= 0; i--){
        __shiftDown(arr, n, i);
    }

    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);
        __shiftDown(arr, i, 0);
    }
}
