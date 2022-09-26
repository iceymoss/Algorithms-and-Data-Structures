#include <iostream>

using namespace std;


// 递归的三路快速排序算法
template <typename T>
void __quickSort3Ways(T arr[], int l, int r){

    if( l>=r ){
        return;
    }

    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    //swap( arr[l], arr[rand()%(r-l+1)+l ] );

    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l+1;    // arr[lt+1...i) == v
    while( i < gt ){
        if( arr[i] < v ){
            swap( arr[i], arr[lt+1]);
            i ++;
            lt ++;
        }
        else if( arr[i] > v ){
            swap( arr[i], arr[gt-1]);
            gt --;
        }
        else{ // arr[i] == v
            i ++;
        }
    }

    swap( arr[l] , arr[lt] );

    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n){

    __quickSort3Ways( arr, 0, n-1);
}

int main(){
    int q[20] = {43,53,21,23,1,21,42,54,32,134,43,13,43,44,44,43,22,12,243,23};
    quickSort3Ways(q,20);
    for(int i=0; i<20; i++)
        cout<<q[i]<<endl;
    return 0;
}
