#include <iostream>
using namespace std;

template<typename T>
int partition(T arr[], int l, int r){
    int v = arr[l];
    int j = l;
    for(int i=j+1; i<=r; i++){
        if(arr[i] < v){
            swap(arr[j+1], arr[i]);
            j++;
        }

    }
    swap(arr[l], arr[j]);
    return j;

}

template<typename T>
void __quicksort(T arr[], int l, int r){
    if(l>=r)
        return;

    int p = partition(arr, l , r);
    __quicksort(arr, l, p-1);
    __quicksort(arr, p+1, r);

}
template<typename T>
void QuickSort(T arr[], int n){

    __quicksort(arr ,0, n-1);
}

int main() {
    int n;
    cout<<"请输入元素个数：";
    cin>>n;
    int a[n];
    int *p;
    p = a;
    for(int i=0; i<n; i++) {
        cin >> *(p+i);
    }
    QuickSort(p, n);
    for(int i=0; i<n; i++){
        cout<<*(p+i)<<endl;
    }
    return 0;
}
