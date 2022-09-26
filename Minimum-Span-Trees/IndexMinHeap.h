//
// Created by 杨旷 on 2021/5/10.
//

#ifndef MINIMUM_SPAN_TREES_INDEXMINHEAP_H
#define MINIMUM_SPAN_TREES_INDEXMINHEAP_H

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

//最小索引堆

template <typename Item>
class IndexMinHeap{

private:
    Item data;   //数据数组
    int count;   //数据对应索引
    int capacity; //堆的容量
    int *indexes; //最小索引堆中的索引，indexes[x] = i 表示索引在x的位置
    int *reverse; // 最小索引堆中的反向索引, reverse[i] = x 表示索引i在x的位置

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    void shiftUP(int k){
        while(data[indexes[k]] < data[indexes[k/2]]){
            swap(indexes[k], indexes[k/2]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    void shiftDown(int k){
        //2*k <= count 至少存在左孩子
        while(2*k <= count){
            int j = 2*k;
            //右孩子存在时
            if(data[indexes[j]] > data[indexes[j+1]]){
                j += 1;
            }
            //只有左孩子时
            if(data[indexes[j]] >= data[indexes[k]]){
                break;
            }
            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;

        }
    }

public:
    //构造函数
    IndexMinHeap(int capacity){
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];

        for(int i = 0;i < capacity; i++){
            reverse[i] = 0;
        }
        count = 0;
        this->capacity = capacity;

    }
    //析构函数
    ~IndexMinHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    //返回堆中元素个数
    int size(){
        return count;
    }

    //返回一个布尔值，表示索引堆是否为空
    bool isEmpty(){
        return count == 0;
    }

    //向最小索引堆中插入新元素，新元素索引为i，元素为item
    //传入的对于用户来说是从0索引的
    void insert(int index, Item item){
        index += 1;
        data[index] = item;
        indexes[count+1] = index;
        //reverse[index] = count+1 表示用来记录真正元素的索引对应在索引堆中的位置
        reverse[index] = count+1;
        count ++;
        shiftUP(count);
    }

    // 从最小索引堆中取出堆顶元素, 即索引堆中所存储的最小数据
    Item extractMin(){
        assert(count > 0);

        Item ret = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        count--;
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        shiftDown(count);
        return ret;
    }

    //获取最小索引堆中堆顶元素
    Item getMin(){
        assert(count > 0);
        return data[indexes[1]];
    }

    //获取最小索引堆中堆顶元素的索引
    int getIndexes(){
        assert(count > 0);
        return indexes[1]-1;
    }

    //看索引所在位置是否存在元素
    bool contain(int index){
        return reverse[index+1] != 0;
    }

    // 获取最小索引堆中索引为i的元素
    Item getItem(int index){
        assert(contain(index));
        return data[index+1];
    }

    //将最小索引堆中索引为i元素修改成newItem
    void change(int index, Item newItem){

        assert( contain(index) );
        index += 1;
        data[index] = newItem;

        shiftUP(reverse[index]);
        shiftDown(reverse[index]);
    }


};


#endif //MINIMUM_SPAN_TREES_INDEXMINHEAP_H
