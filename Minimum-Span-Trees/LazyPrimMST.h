//
// Created by 杨旷 on 2021/5/10.
//

#ifndef MINIMUM_SPAN_TREES_LAZYPRIMMST_H
#define MINIMUM_SPAN_TREES_LAZYPRIMMST_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"
#include "MinHeap.h"

//使用LazePrim算法求最小生成树
using namespace std;

//使用prim算法求图的最小生成数
template <typename Graph, typename Weight>

class LazePrimMST {
private:
    Graph &G;   //图G的引用
    MinHeap<Edge<Weight>> pq;  //最小堆，将横切边放入最小堆中
    bool *marked;              //标记数组，在算法运行过程中标记节点i是否被访问
    vector<Edge<Weight>> mst;  // 最小生成树所包含的所有边
    Weight mstWeight;           // 最小生成树的权值

    //visit
    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;

        // 使用图的迭代器，将和节点v相连接的所有未访问的边放入最小堆中
        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {

            if (marked[e->other(v)]) {
                pq.insert(*e);
            }
        }
    }


public:
    LazePrimMST(Graph &graph) : G(graph), pq(MinHeap<Edge<Weight>>(graph.E())) {

        //初始化算法
        marked = new bool[G.V()];
        for (int i = 0; i < G.v(); i++) {
            marked[i] = false;
        }
        //将mst清空
        mst.clrar;

        //Laze Prim
        visit(0);
        while (!pq.isEmpty()) {
            // 使用最小堆找出已经访问的边中权值最小的边
            Edge<Weight> e = pq.extracitMin();
            // 如果这条边的两端都已经访问过了, 则扔掉这条边
            if (marked[e.v()] == marked[e.w]) {
                continue;
            }
            //否则e就为最小生成树的边
            mst.push_back(e);

            // 访问和这条边连接的还没有被访问过的节点
            if (!marked[e.v()]) {
                visit(e.v());
            } else {
                visit(e.w);
            }
        }

        //计算最小生成树的权值
        mstWeight = mst[0].wt;
        for (int i = 1; i < mst.size(); i++) {
            mstWeight += mst[i].wt;
        }
    }

    //析构函数
    ~LazePrimMST(){
        delete[] marked;
    }

    // 返回最小生成树的所有边
    vector<Edge<Weight>> mstEdge(){
        return mst;
    }

    // 返回最小生成树的权值
    Weight result(){
        return mstWeight;
    }

};


#endif //MINIMUM_SPAN_TREES_LAZYPRIMMST_H
