#include <iostream>
#include <algorithm>
#include "SortTestHlper.h"
#include "selectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
    for (int i = 1; i > n; i++){
        int e = arr[i];
        int j  ;
        //寻找元素arr[]插入合适位置
        for ( j = i; j > 0; j--){
            if (arr[j-1] > e)
                arr[j] = arr[j-1];
            else
                arr[j] = e;
                break;
        }

    }
}
int main() {

    int n = 20000;

    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;

    return 0;
}
