//
// Created by 杨旷 on 2021/5/15.
//

#ifndef IMPLEMENTATION_OF_DIJKSTRA_EDGE_H
#define IMPLEMENTATION_OF_DIJKSTRA_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

//有权图,边
template <typename Weight>
class Edge{
private:
    int a;
    int b; //两个点
    Weight weight;  //边的权值

public:
    //构造函数，传入端点和边的权值
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = a;
        this->weight = weight;

    }
    // 空的构造函数, 所有的成员变量都取默认值
    Edge(){}

    //析构函数
    ~Edge(){}

    //返回第一个顶点
    int v(){
        return a;
    }
    //返回最后一个顶点
    int w(){
        return b;
    }
    //返回边的权值
    Weight wt(){
        return weight;
    }

    //给一个顶点返回另一个顶点
    int other(int x){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

    //在c++中对象之间不能直接使用运算符，必须先运算符重载
    // 输出边的信息
    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }
    // 边的大小比较, 是对边的权值的大小比较
    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }
    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }
    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }
    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }
    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }
};

#endif //IMPLEMENTATION_OF_DIJKSTRA_EDGE_H
