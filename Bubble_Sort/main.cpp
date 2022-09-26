#include <iostream>

using namespace std;

void swap(int array[], int i, int j){
    int temp =  array[i];
    array[i] = array[j];
    array[j] = temp;
}
void BubbleSort(int arr[],int n) {
    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n - 1; j++)
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
    }


int main() {
    int a[20] = {12, 1, 5, 45,34 , 56,64,76, 21, 32, 3, 43, 2, 1, 23, 65, 88, 55 , 345 , 53};
    BubbleSort(a, 20);
    for(int i = 0; i < 20; i++)
        cout<<a[i]<<endl;
    return 0;
}
