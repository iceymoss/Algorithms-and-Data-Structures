//
// Created by 杨旷 on 2021/4/11.
//

#ifndef UNION_FIND_UNIONFIND3_H
#define UNION_FIND_UNIONFIND3_H
#include<cassert>

using namespace std;
namespace UF3 {
    class UnionFind2 {
    private:
        // 我们的第二版Union-Find, 使用一个数组构建一棵指向父节点的树
        // parent[i]表示第i个元素所指向的父节点
        int *parent;
        int *size;
        int count;  //数据个数

    public:
        UnionFind2(int count) {
            parent = new int[count];
            size = new int[count];
            this->count = count;
            //初始化
            for (int i = 0; i < count; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        ~UnionFind2() {
            delete parent;
            delete size;
        }

        // 查找过程, 查找元素p所对应的集合编号
        // O(h)复杂度, h为树的高度
        int find(int p) {
            assert(p >= 0 && p <= count);
            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p
            while (p != parent[p])
                p = parent[p];
            return p;
        }

        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度
        void unionElments(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            //将节点数较大的指向节点数较小的
            if(size[pRoot] < size[qRoot]) {
                parent[pRoot] = qRoot;
                size[pRoot] = +size[qRoot];
            }
            else {
                parent[qRoot] = pRoot;
                size[qRoot] = pRoot;
            }
        }
    };
}
#endif //UNION_FIND_UNIONFIND3_H
