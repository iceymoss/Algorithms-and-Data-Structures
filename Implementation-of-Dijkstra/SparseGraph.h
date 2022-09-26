//
// Created by 杨旷 on 2021/5/15.
//

#ifndef IMPLEMENTATION_OF_DIJKSTRA_SPARSEGRAPH_H
#define IMPLEMENTATION_OF_DIJKSTRA_SPARSEGRAPH_H
#include <iostream>
#include "Edge.h"
#include <vector>
#include <cassert>

using namespace std;

//邻接表
template <typename Weight>
class SparseGraph{
private:
    int n, m;  //节点数和边数
    bool directed;   //是否为有权图
    vector<vector<Edge<Weight>* > > g ;// 图的具体数据

public:
    //构造函数，传入节点数和是否为有权图
    SparseGraph(int n, bool directed){
        assert(n >= 0);
        this->n = n;
        this->m = 0;  //初始化没有任何边
        this->directed = directed;
        // g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
        g = vector<vector<Edge<Weight> *> >(n, vector<Edge<Weight> *>());
    }


    ~SparseGraph(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                delete g[i][j];
            }
        }
    }

    //返回节点数
    int V(){
        return n;
    }
    //返回边数
    int E(){
        return m;
    }

    // 向图中添加一个边, 权值为weight
    void addEdge( int v, int w , Weight weight){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        g[v].push_back(new Edge<Weight>(v, w, weight));

        if(v != w && !directed){
            g[w].push_back(new Edge<Weight>(w, v, weight));
        }
        m++;
    }

    // 验证图中是否有从v到w的边
    Weight hasEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for(int i = 0; i < n; i++) {
            if (g[v][i]->othor(v) == w) {
                return true;
            }
        }
        return false;
    }
   //显示图信息
    void show(){
        for( int i = 0 ; i < n ; i ++ ) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); j++)
                cout << "( to:" << g[i][j]->w() << ",wt:" << g[i][j]->wt() << ")\t";
            cout << endl;

        }
    }

    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点向连的所有边
    class adjIterator{
    private:
        SparseGraph &G; // 图G的引用
        int v;
        int index;  //标记索引

    public:
        adjIterator(SparseGraph &graph, int v):G(graph){
            this->v = v;
            this->index = 0;

        }
        //析构函数
        ~adjIterator(){
        }

        // 返回图G中与顶点v相连接的第一个边
        Edge<Weight>* begin(){
            index = 0;
            if(G.g.size()){
                return G.g[v][index];
            }
            return NULL;
        }

        Edge<Weight>* next(){
            index += 1;
            if(index < G.g.size()){
                return G.g[v][index];
            }
            return NULL;
        }

        bool end(){
            return index >= G.g.size();
        }

    };

};
#endif //IMPLEMENTATION_OF_DIJKSTRA_SPARSEGRAPH_H
