#include <iostream>
#include <algorithm>

using namespace std;

//双向快速排序partition
//将数组分为arr[l,p-1]<arr[p],arr[p+1,r]>arr[q]
template<typename T>
int _partiotion2(T arr[], int l, int r){
    T v = arr[l];
    int i = l+1,j = r;
    while(true){
        while(l >= r&&arr[i] < v)
            i++;
        while(r >= l+1&&arr[j] > v)
            j--;
        if(l>r)
            break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    return j;


}
//运用递归，进行自我调用
template<typename T>
void __quickSort(T arr[], int l, int r ) {
    if (l >= r) {
        return;
    }
    //调用双向快速排序的partition
    int p = _partition2(arr, l, r);

    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}
//仍然使用模板类型T
template<typename T>
void quickSort(T arr, int n ){
    __quickSort(arr, 0, n-1);

}
int main() {
    int Q[20] = {1,3,4,5,8,65,4,332,32,43,2,3,53,54,332,23,1,23,23,34};
       quickSort( Q, 20);
       for(int i = 0; i < 20; i++)
           cout<<Q[i]<<endl;
}
