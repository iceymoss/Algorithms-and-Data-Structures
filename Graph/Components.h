//
// Created by 杨旷 on 2021/5/3.
//

#ifndef GRAPH_COMPONENTS_H
#define GRAPH_COMPONENTS_H
#include <iostream>
#include <cassert>
using namespace std;

//求无权图的联通分量
template <typename Graph>
class Component{
private:
    Graph &G;       //图的引用
    bool *visited;  //记录深度遍历已经被访问过的节点
    int ccount;     //记录联通分量
    int *id;        //每个节点对应的联通分量

    //dfs遍历
    void dfs(int v){

        visited[v] = true;
        id[v] = ccount;
        //传入迭代器
        typename Graph::adjIterator adj(G, v);
        for(int i = adj.begin(); !adj.end(); i = adj.next()){
            if(!visited[i]){
                dfs(i);
            }
        }
    }

public:
    //构造函数，求无权图的联通分量
    Component(Graph &graph):G(graph){

        //算法初始化
        id = new int[G.V()];
        visited = new bool[G.v()];
        ccount  = 0;
        for(int i = 0; i < G.v(); i++){
            visited[i] = false;
            id[i] = -1;
        }

        for(int i = 0; i < G.v(); i++){
            //如果visited[i]没有被访问过
            if(!visited[i]){
                dfs(i);
                ccount ++;
            }
        }
    }
    //析构函数
    ~Component(){
        delete[] visited;
        delete[] id;
    }

    //返回图的联通分量
    int count(){
        return ccount;
    }

    //查询v和w是否联通
    bool isComponent(int v, int w){
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[v] = id[w];
    }
};

#endif //GRAPH_COMPONENTS_H
