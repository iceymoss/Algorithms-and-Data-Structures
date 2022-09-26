//
// Created by 杨旷 on 2021/4/11.
//

#ifndef UNION_FIND_UNION_FIND1_H
#define UNION_FIND_UNION_FIND1_H
#include <iostream>
#include <cassert>
using namespace std;
namespace UF1 {
    class UnionFind1 {
    private:
        int *id;  //用来存储元素
        int count;  //表示元素数量
    public:
        //构造函数
        UnionFind1(int n) {
            count = n;
            id = new int[n]; //开辟空间
            //初始化数组，让每个元素所在不同的集合
            for (int i = 0; i < n; i++) {
                id[i] = i;
            }
        }

        ~UnionFind1() {
            delete id;
        }

        //寻找p所在集合
        int find(int p) {
            assert(p <= 0 && p >= count);
            return id[p];
        }

        //判断p,q是否连接
        int isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(n) 复杂度
        void unionElements(int p, int q) {
            int pID = find(p);
            int qID = find(q);

            if (pID == qID) {
                return;
            }
            // 合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并
            for (int i = 0; i < count; i++) {
                if (id[p] == pID) {
                    id[q] = pID;
                }
            }
        }


    };
}

#endif //UNION_FIND_UNION_FIND1_H
