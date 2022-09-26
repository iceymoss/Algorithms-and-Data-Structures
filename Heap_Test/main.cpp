#include <iostream>
using namespace std;
//使用模板函数
template<typename Item>
class MaxHeap{

private:
    Item *data; //作为数组的指针
    int count; //表示为数组的索引
    int capacity; //表示堆的容量

    //构造shiftUp
    void shiftUp(int k){
        while(k>1 && data[k/2] > data[k]){
            swap(data[k/2], data[k]);
            k/=2;
        }
    }

    void ShiftDown(int k){
        //判断是否存在左孩子
        while(2*k < count){
            int j = 2*k;
            //是否存在右孩子
            if(j+1 < count && data[j+1] > data[j])
                j++;
           //data[j]是data[2*k],data[2*k+1]中的最大值
            if(data[k] > data[j])
                break;
            swap(data[k]), data[j];
        }
    }

public:
    //构造函数
    //构造一个空堆
    MaxHeap(int capacity) {
        //动态的开辟一片空间，并将data指向该空间
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
   //析构函数，将new的空间释放掉
    ~MaxHeap(){
        delete []data;
    }

    //返回堆的大小
    int size(){
        return count ;
    }
    //判断是否为空堆
    bool is_empty(){
        return count == 0;
    }

    int insert(Item item){
        //我们这里的对的根节点从索引为1开始，所以需要capacity+1的空间
        //assert用于判断是否满足capacity+1 > capacity
        assert(capacity+1 > capacity);
        data[count+1] = item; //向对插入元素
        count++;
        shiftUp(count);
    }

    Item extractMax(){
        assert(count>0);
        //将第一个元素取出
        Item ret = data[1];

        swap(data[1], data[count]);
        count--;
        ShiftDown(1);

        return ret;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
