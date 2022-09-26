//
// Created by 杨旷 on 2021/5/3.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

//路径查询算法
template <typename Graph>
class Path{

private:
    Graph &G;   // 图的引用
    int s;      // 起始点
    bool* visited;  // 记录dfs的过程中节点是否被访问
    int * from;     // 记录路径, from[i]表示查找的路径上i的上一个节点

    //图的深度优先遍历
    void dfs(int v){
        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for( int i = adj.begin(); !adj.end(); i = adj.next){
            if( !visited[i] ){
                from[i] = v;
                dfs(i);
           }
        }
    }

public:
    //构造函数，寻路算法，寻找graph从s点到其他的路径
    Path(Graph &graph, int s):G(graph){
        assert( s >= 0 && s < G.V() );

        visited = new bool[G.v()];
        from = new int[G.V()];
        for(int i = 0; i < G.v(); i++){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        //寻路算法
        dfs(s);
    }
    ~Path(){
        delete[] visited;
        delete[] from;
    }

    //查询从s到w是否有路径
    bool hasPath(int w){
        assert( w >= 0 && w < G.v() );
        return visited[w];
    }

    //查询从s到w的路径。存放在栈vec中
    void path(int w, vector<int> &vec) {

        assert(hasPath(w));
        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        vec.clear();
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }

    // 打印出从s点到w点的路径
    void showPath(int w){
        assert(hasPath(w));

        vector<int>vec;
        path(w, vec);
        for(int i = 0; i < vec.size(); i++){
            cout<<vec[i];
            if(i == vec.size() - 1)
                cout<<endl;
            else
                cout<<"->";
        }
    }
};

#endif //GRAPH_PATH_H
