//
// Created by 风 on 2021/2/25.
//

#ifndef HEAPIFY_HEAP_H
#define HEAPIFY_HEAP_H
#include <iostream>

using namespace std;
template<typename Item>
class MaxHeap{

private:
    Item *data;

    //count为索引
    int count;

    //capcacity为容量
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[k / 2] < data[k]) {
            swap(data[k / 2], data[k]);
            k = k / 2;
        }
    }

    void shiftDown(int k){
            while(k*2 <=  count){
                int j = k*2 ;
                if(j+1 <= count && data[j]<data[j+1])
                    j++;
                if(data[k]>data[j])
                    break;
                swap(data[k], data[j]);
                k = j;
            }
        }

public:
    //构造函数，构造一个空堆，可容纳capacity个元素
    MaxHeap(int capacity) {
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
       MaxHeap(Item arr[], int n) {
        data = new Item[n+1];
        capacity = n;

        for(int i = 0; i < n; i++)
            data[i+1] = arr[i];
        count = 0;

        for(int i = count/2; i>=1; i--)
            shiftDown(i);
    }



    ~MaxHeap(){
        delete[] data;
    }
    bool isEmpty(){
        return count == 0;
    }
    //向最大堆中插入一个一个新元素 item
    void insert(Item item){
        assert(count+1<=capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }
    Item extractMax(){
        assert(count>0);
        Item ret = data[1];
        swap(data[count], data[1]);
        count--;
        shiftDown(1);
        return ret;
    }

};

#endif //HEAPIFY_HEAP_H
