#include <iostream>

using namespace std;
template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    //需要重新开辟一片动态空间
    //T *aux = new T[r-l+1]
    T aux[r - l + 1];

    for(int i = l; i <= r; i++) {

        aux[i - l] = arr[i];
    }
        //初始化和i,j的值
        int i = l, j = mid + 1;

    for (int k = l; k <= r; k++) {

            if (l > mid) {
                arr[k] = aux[j-l];
                j++;
            }
            else if(j>r){
                arr[k] = aux[i-l];
                i++;
            }
            else if(arr[i] > arr[j]){
                arr[k] = aux[j-l];
                j++;
            }
            else if(arr[i] <= arr[j]){
                arr[k] = aux[i-l];
                i++;
            }
    }
    //delete []aux;
    }



template <typename T>
void __mergesort(T arr[], int l, int r){
    //递归终止条件
    if(l>=r)
        return ;

    int mid = (r+r)/2;
    //递归调用
    __mergesort(arr,l,mid);
    __mergesort(arr, mid+1, r);
    __merge(arr, l, mid, r);

}
//归并排序
//构造函数
template <typename T>
void MergeSort(T arr[], int n) {
    //调用函数
    __mergesort(arr, 0, n - 1);
}

//插入排序
template<typename T>
void InsertSort(T arr[], int n){
    for(int i=1; i<n; i++){

        for(int j = i; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
            else{
                break;
            }
        }
    }



}

int main() {
    int a[5] = {6,4,2,1,7};
    int *p_a;
    p_a = a;
    MergeSort(p_a, 5);
    for(int i=0; i<5; i++){
        cout<<p_a[i]<<endl;
    }
    int b[5] = {6,4,2,1,7};
    InsertSort(b,5);
    for(int j=0; j<5; j++){
        cout<<b[j]<<endl;
    }

    return 0;
}
