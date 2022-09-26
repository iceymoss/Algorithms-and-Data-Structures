//
// Created by 杨旷 on 2021/5/3.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
//稠密图
class DenseGraph{

private:
    int n, m;   //节点数和边数
    bool directed;   //是否为有向图
    vector<vector<bool>> g;   //图的具体数据

public:
    DenseGraph(int n, bool directed){
        assert(n >= 0);
        this->n = n;
        this->m = 0;
        this->directed = directed;
        // g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
        g = vector<vector<bool>>(n, vector<bool>(n, false));
    }

    ~DenseGraph(){}

    //返回图中节点的个数
    int getV(){
        return n;
    }
    //返回图中边的条数
    int getE(){
        return m;
    }

    //向图中添加一条边
    void addEdga(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if(hasEdga(v, w)){
            return;
        }

        g[v][w] = true;
        //无向图是双向的
        if(!directed){
            g[w][v] = true;
        }

        m++;
    }

    //验证图中是否有v到w的边
    bool hasEdga(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

    //显示图中信息
    void show(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<g[i][j]<<"\t";
            cout<<endl;
            }
        }
    }

    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点向连的所有顶点
    class adjIterator{
    private:
        DenseGraph &G;   //图G的引用
        int v;         //传入一个节点
        int index;   //对应的索引

    public:
        adjIterator(DenseGraph &graph, int v): G(graph){
            assert(v >= 0 && v < G.n);
            this->v = v;
            // 索引从-1开始, 因为每次遍历都需要调用一次next()
            this->index = -1;
        }
        ~adjIterator(){}

        // 返回图G中与顶点v相连接的第一个顶点
        int begin(){
            index = -1;
            return next();
        }
        // 返回图G中与顶点v相连接的下一个顶点
        int next(){
            for(index += 1; index <= G.getV(); index ++){
                if( G.g[v][index] ){
                    return index;
                }
                return -1;
            }
        }

        // 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
        bool end(){
            return index >= G.getV();
        }
    };
};
#endif //GRAPH_DE// NSEGRAPH_H
