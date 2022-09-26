#include<iostream>

using namespace std;

int main(){
    int sum;
    int arr[6];
    for(int i = 0; i<6; i++){
        cin>>arr[i];
    }
     for(int i = 0; i<6; i++) {
         sum = sum + arr[i];
     }
     cout<<sum/6<<endl;
}

//使用模板函数
/*template <typename T>
void InsertionSort(T arr[], int n){
    //第一个元素已经排在第一个位置，这里从索引为1开始
    for(int i = 1; i < n; i++){
        //将arr[i]的值赋值给e
        int e = arr[i];
        int j;
        // j保存元素e应该插入的位置
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
    return;
}
int main(){
    int q[10] = {2, 4, 1, 2, 6, 4, 2, 1, 1, 6};
    //InsertionSort函数的调用
    InsertionSort(q, 10);
    for(int i = 0; i < 10; i++)
        cout<<q[i]<<endl;
    return 0;

}*/