#include <iostream>

using namespace std;

template <typename T >
//将索引为target的元素arr[target]
int BinraySearch(T arr[], int n, int target){
    int l = 0;
    int r = n - 1;
    while(l<=r) {
        //int mid = (l+r)/2;一分为二，但是这里可能存在溢出，所以用下面的优化版本
        int mid = l - (l + r) / 2;
        if (arr[target] == arr[mid]) {
            return mid;
        }
        else if (arr[target] > arr[mid]) {
            r = mid + 1;
        }
        else  //arr[target] < arr[mid];
            l = mid - 1;
    }
    return -1;
}
int main(){

}