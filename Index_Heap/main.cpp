#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename Item>
class IndexMaxHeap {

//对内容进行私有化，不能让用户修改
private:
    //data为堆中的元素
    Item *data;
    //开辟新的空间，用来存储新的索引
    int *indexes;
    //count为元素对应的索引
    int count;
    //capacity表示堆的容量
    int capacity;

    void shiftUp(int k) {  //此时的是用来描述索引数组的位置
        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]){
            swap(indexes[k / 2], indexes[k]);
            k /= 2;
            }
    }

    void shiftDown(int k) {
        while (k * 2 <= count) {
            int j = k * 2;
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
                j++;

            if (data[indexes[k]] >= data[indexes[j]])
                break;
            swap(indexes[k], indexes[j]);
            k = j;
        }
    }

public:

    //构造函数，构造一个空堆，能容纳capacity个元素
    IndexMaxHeap(int capacity) {
        data = new Item(capacity + 1);
        indexes = new int[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
   //进行空间的释放
    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
    }

    //返回堆中元素个数
    int size() {
        return count;
    }

    //返回一个布尔值，表示堆是否为空
    bool isEmpty() {
        return count == 0;
    }
    //传入的对用户而言，是从0索引开始的
    void insert(int i, Item item) {

        //对capacity和进行范围限定
        assert(count + 1 <= capacity);
        assert(i+1>1 && i+1 <= capacity);
        //这里的索引为1开始的
        i+=1;
        data[i] = item;
        indexes[count+1] = i;
        count++;
        shiftUp(count);
    }

    void extractMax(){
        assert(count > 0);

        Item ret = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    int  extractMaxIndex() {
        assert(count > 0);

        int ret = indexes[1] - 1;

        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    Item getItem(int i){
        return data[i+1];
    }

    void change(int i, Item newItem){

        i+=1;
        data[i] = newItem;
        //找到indexes[j] = 1,j表示data[i]在堆中的位置
        //之后shiftUp(j), shiftDown(j)
        for(int j = 1; j <= count; j++)
            if(indexes[j] == i) {
                shiftUp(j);
                shiftDown(j);
            }
                return;
    }
};

