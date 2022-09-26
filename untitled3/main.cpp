#include <iostream>
#include <string>
using namespace std;
template<typename T>
//函数声明
void selectionSort( T arr[] , int n)
{
    for(int i = 0 ; i < n; i++ )
    {
        //寻找[i,n]区间里的最小值
        int minIndex = i ;
        for(int j = i + 1; j < n; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;
        //交换值
        swap( arr[i] , arr[minIndex] ) ;
    }
}
int main() {
    float b[5] = {1.1, 2.2, 5.3, 53.5};
    selectionSort(b, 5);
    for (int q = 0; q < 5; q++) {
        cout << b[q] << endl;
    }
    string c[5] = {"d", "a", "q", "t", "v"};
    selectionSort(c, 5);
    for (int i = 0; i < 5; i++) {
        cout << c[i] << endl;
    }
}