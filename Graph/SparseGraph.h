//
// Created by 杨旷 on 2021/5/3.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稀疏图—邻接表
class SparseGraph{
private:
    int n, m;   //节点数和边数
    bool directed;   //是否为无向图
    vector<vector<int>> g;   //图的具体数据

public:SparseGraph(int n,bool directed){
        assert(n >= 0);
        this->n = n;
        this->directed = directed;
        // g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
        g = vector<vector<int>>(n, vector<int>());
    }

    ~SparseGraph(){}

    int getV(){
        return n;
    }
    int getE(){
        return m;
    }

    // 向图中添加一个边
    void addEdga(int v, int w){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        //将w放入g[v][i]中,将w与v相连
        g[v].push_back(w);
        if(v != w && !directed){
            g[w].push_back(v);
        }
        m ++;
    }

    // 验证图中是否有从v到w的边
    bool hasEdga(int v, int w){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        for(int i = 0; i <= g[v].size(); i++){
            if(g[v][i] == w)
                return true;
            return false;
        }
    }

    //显示图中信息
    void show(){
        for(int i = 0; i < n; i++){
            cout<<"vector"<<":\t";
            for(int j = 0; j < g[i].size(); j++){
                cout<<g[i][j]<<":\t";
            }
            cout<<endl;
        }
    }
    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点向连的所有顶点
    class adjIterator{
    private:
        SparseGraph &G;  //图的引用
        int v;  //传入节点
        int index;   //对应索引

    public:
        adjIterator(SparseGraph &graph, int v):G(graph){
            this->v = v;
            this->index = 0;
        }

        ~adjIterator(){}
        // 返回图G中与顶点v相连接的第一个顶点
        int begin(){
            index = 0;
            if( G.g[v].size() ){
                return  G.g[v][index];
            }
            return -1;
        }

        // 返回图G中与顶点v相连接的下一个顶点
        int next(){
            index++;
            if(index < G.g[v].size())
                return G.g[v][index];
        }
        bool end(){
            return index >= G.g[v].size();
        }
    };
};

#endif //GRAPH_SPARSEGRAPH_H
