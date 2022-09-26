//
// Created by 杨旷 on 2021/5/15.
//

#ifndef IMPLEMENTATION_OF_DIJKSTRA_DENSEGRAPH_H
#define IMPLEMENTATION_OF_DIJKSTRA_DENSEGRAPH_H
#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

//邻接矩阵
template <typename Weight>
class DenseGraph{
    int n, m;     //节点和边
    bool directed;  //是否为有权图
    vector<vector<Edge<Weight>* > >g; //图的具体数据

public:
    DenseGraph(int n, bool directed){
        assert(n > 0);
        this->n = n;
        this->m = 0;
        this->directed = directed;
        // g初始化为n*n的矩阵, 每一个g[i][j]指向一个边的信息, 初始化为NULL
        g = vector<vector<Edge<Weight> *>>(n, vector<Edge<Weight> *>(n, NULL));

    }

    //析构函数
    ~DenseGraph(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                delete g[i][j];
            }
        }
    }

    //返回节点数
    int V(){
        return n;
    };
    //返回边数
    int E(){
        return m;
    }

    //向图中添加权值为weight边
    void addEdge(int v, int w,Weight weight){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        //如果存在g[v][w]则将其释放
        if(hasEdge(v, w)){
            delete g[v][w];
            if(v != w && !directed){
                delete g[w][v] ;
            }
        }

        g[v][w] = new Edge<Weight>(v, w, weight);
        if(v != w && !directed){
            g[w][v] = Edge<Weight>(w, v, weight);
        }
        m++;
    }


    //验证是否有v到w的边
    Edge<Weight> hasEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w] != NULL;
    }

    // 显示图的信息
    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ )
                if( g[i][j] )
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL\t";
            cout<<endl;
        }
    }

    //邻边迭代器，传入一个图和一个节点
    // 迭代在这个图中和这个顶点向连的所有边
    class adjIterator{
    private:
        DenseGraph &G;   //图G的引用
        int v;
        int index;

    public:
        adjIterator(DenseGraph &graph, int v){
            this->v = v;   // 索引从-1开始, 因为每次遍历都需要调用一次next()
            this->index = -1;
        }

        Edge<Weight>* begin(){
            index = -1;
            return next;
        }
        // 返回图G中与顶点v相连接的下一个边
        Edge<Weight>* next() {
            for (index += 1; index < G.V(); index++) {
                if (G.g[v][index]) {
                    return G.g[v][index];
                }
            }
        }

        // 查看是否已经迭代完了图G中与顶点v相连接的所有边
        bool end(){
            return index >= G.V();
        }

    };




};

#endif //IMPLEMENTATION_OF_DIJKSTRA_DENSEGRAPH_H
