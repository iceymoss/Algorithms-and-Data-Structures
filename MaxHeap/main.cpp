#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap {   //定义一个类

//对内容进行私有化，不能让用户修改
private:
    //data为堆中的元素
    Item *data;
    //count为元素对应的索引
    int count;
    //capacity表示堆的容量
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[k / 2] < data[k]){
            swap(data[k / 2], data[k]);
            k /= 2;
            }
    }

    void shiftDown(int k) {
        while (k * 2 <= count) {
            int j = k * 2;
            if (j + 1 <= count && data[j + 1] > data[j])
                j++;

            if (data[k] >= data[j])
                break;
            swap(data[k], data[j]);
            k = j;
        }
    }

public:

    //构造函数，构造一个空堆，能容纳capacity个元素
    MaxHeap(int capacity) {
        data = new Item(capacity + 1);
        count = 0;
        this->capacity = capacity;
    }

    ~MaxHeap() {
        delete[] data;
    }

    //返回堆中元素个数
    int size() {
        return count;
    }

    //返回一个布尔值，表示堆是否为空
    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        count++;
        shiftUp(count);

    }

    Item extractMax() {
        assert(count>0);
        Item ret = data[1];

        swap(data[1], data[count]);
        count--;
        shiftDown(1);

        return ret;
    }
};

//测试MaxHeap
int main() {
    MaxHeap<int> maxheap = MaxHeap<int>(100);

    srand(time(NULL));
    for(int i = 0; i < 50; i++)
        maxheap.insert( rand()%100 );

    while( !maxheap.isEmpty())
        cout<<maxheap.extractMax()<<" ";
    cout<<endl;
    return 0;
}

