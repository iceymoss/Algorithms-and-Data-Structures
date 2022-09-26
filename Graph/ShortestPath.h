//
// Created by 杨旷 on 2021/5/4.
//

#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

//寻找无权图的最短路径
template <typename Graph>   //封装为统一接口
class ShortestPath{

private:
    Graph &G;            //图是引用
    int s;               //起始点
    bool *visited;       //记录dfs的过程中节点是否被标记
    int *from;           //记录路径，from[i]表示查询的路径上i的上一个节点
    int *ord;            //记录路径中节点的次序，ord[i]表示i节点在路径中的次序

public:
    //构造函数
    ShortestPath(Graph &graph, int s):G(graph){

        //算法初始化
        assert( s >= 0 && s < graph.V() );
        this->s = s;
        visited = new bool[graph.v()];
        from = new int[graph.v()];
        ord = new int[graph.v()];
        for(int i = 0; i < graph.v(); i++){
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }

        // 无向图最短路径算法, 从s开始广度优先遍历整张图
        queue<int> q;

        q.push( s );
        visited[s] = true;
        ord[s] = 0;
        while( !q.empty() ){
            //将队列中的首元素赋值给v
            int v = q.front();
            q.pop();             //将第一个元素取出队列

            typename Graph::adjIterator adj(G, v);
            for( int i = adj.begin(); !adj.end(); i = adj.next() ){
                if( !visited[i] ){
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i]  = ord[v] + 1;
                }
            }
        }

    }
    //析构函数
    ~ShortestPath(){
        delete[] visited;
        delete[] from;
        delete[] ord;

    }
    // 查询从s点到w点是否有路径
    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    // 查询从s点到w点的路径, 存放在vec中
    void path(int w,vector<int> vec){
        assert(w >= 0 && w < G.V());
        stack<int> s;
        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        int p = w;
        while(p != -1){
            s.push(p);
            p = from[p];
        }

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        vec.clear();
        while( !s.empty() ){
            vec.push_back( s.top());
            s.pop();
        }
    }

    // 打印出从s点到w点的路径
    void showPath(int w){

        assert( w >= 0 && w < G.V() );

        vector<int> vec;
        path(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i];
            if( i == vec.size()-1 )
                cout<<endl;
            else
                cout<<" -> ";
        }
    }

    // 查看从s点到w点的最短路径长度
    int length(int w){
        assert( w >= 0 && w < G.V() );
        return ord[w];
    }



};

#endif //GRAPH_SHORTESTPATH_H
