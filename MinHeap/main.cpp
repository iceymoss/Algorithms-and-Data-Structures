#include <iostream>
#include<string>
#include<algorithm>
#include<ctime>
#include<cassert>
using namespace std;
template<typename T>
class MinHeap {
//对相应数据进行保护
private:

    int count;//定义count为堆的索引
    T *data;//指针类型
    int capacity;
    //插入操作
    void shiftUp(int k){
        while(k>1 && data[k/2] < data[k]){
            swap(data[k/2], data[k]);
            k = k / 2;
        }
    }
    //去除操作
    void shiftDown(int k) {
        //判断是否有做孩子
        while (2 * k < count) {
            int j = 2 * k;
            //判断是否拥有右孩子
            if (j + 1 <= count && data[j] > data[j + 1])
                j++;
            if(data[k] < data[j])
                break;
            swap(data[k], data[j]);
            k = j;
        }

    }

//用户可修改使用
public:
    //构造一个空堆
    MinHeap(T capacity) {
        data = new T(capacity + 1);
        count = 0;

    }
   //释放空间
    ~MinHeap() {
        delete[] data;
    }
    //返回堆的数量
    int size(){
        return count;
    }
    //判断是否为空
    bool IsEmpty(){
            return count == 0;
    }

    void insert(T t){
        assert(count+1 <= capacity);
        data[count+1] = t;
        count ++;
        shiftUp(count);
    }

    T extractMin(){
        assert(count > 0);
        //将第一个元素去掉
        T ret = data[count+1];
        swap(data[1], data[count+1]);
        count --;
        shiftDown(count);
    }

    void Heapif(){
        //todo
    }

};

int main() {

    MinHeap<int> minheap = MinHeap<int>(100);

    srand(time(NULL));
    for( int i = 0 ; i < 50 ; i ++ )
        minheap.insert( rand()%100 );

    return 0;
}

