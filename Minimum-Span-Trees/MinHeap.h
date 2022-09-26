//
// Created by 杨旷 on 2021/5/10.
//

#ifndef MINIMUM_SPAN_TREES_MINHEAP_H
#define MINIMUM_SPAN_TREES_MINHEAP_H

#include <algorithm>
#include <cassert>

using namespace std;

//最小堆
template <typename Item>
class MinHeap{

private:
    Item *data; //原始数据对应的数组
    int count;  //数据对应的索引
    int capacity;

    void shiftUp(int k){
        while(k > 1 && data[k] < data[k/2]){
            swap(data[k]), data[k/2];
            k /= 2;
        }
    }

    void shiftDown(int k){
        while(2*k <= count){
            int j = 2*k;
            //右孩子存在
            if(j+1 < count && data[j] > data[j+1]) {
                j++;
            }
            //右孩子不存在
            if(data[k] <= data[j]){
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }


public:
    //构造函数，构造一个空堆可容纳capacity个元素
    MinHeap(int capacity ){

        data = new Item[capacity + 1];    //开capacity+1的空间，对应第一个元素从索引值1开始
        count = 0;
        this->capacity = capacity;

    }
    //构造函数，通过给定一个定数组创建一个最小堆
    MinHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for(int i = 0; i < n; i++){
            data[i+1] = arr[i];
        }
        count = n;

       // for(int i = count/2; i >= 1; i--){
        //    shiftDown(i);
       // }
    }

    //析构函数
    ~MinHeap(){
        delete[] data;
    }

    //返回堆中的元素个数
    int size(){
        return count;
    }

    //返回一个布尔值，表示堆是否为空
    bool isEmpty(){
        return count == 0;
    }

    //向最小堆中，插入一个新元素item
    Item insert(Item item){
        assert(count + 1 <= capacity);
        data[count+1] = item;
        shiftUp(count+1);
        count ++;

    }
    // 从最小堆中取出堆顶元素, 即堆中所存储的最小数据
    Item extracitMin(){
        assert(count > 0);
        Item ret = data[1];
        swap(data[1], data[count]);
        count --;
        shiftDown(1);
        return ret;
    }
    Item getMin(){
        assert(count > 0);
        return data[1];
    }

};

#endif //MINIMUM_SPAN_TREES_MINHEAP_H
