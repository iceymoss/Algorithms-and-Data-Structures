#include<iostream>
using namespace std;

void selectionSort(int arr[ ] , int n)
{
    for (int i = 0 ; i < n ; i++ )
    {
        int minIndex = i;
        for (int j = i + 1 ; j < n ; j++ )
            if ( arr[j] <  arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex])  ;
    }
}

int main()
{
    int q[4] = {3,2,5,1};
    selectionSort(q, 4);
    for (int i = 0 ; i < 4 ;i++ )
        cout<< q[i] << endl;
}
