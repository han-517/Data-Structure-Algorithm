//
// Created by Wjh on 2021/12/3.
//

#ifndef DL1203_ADJACENCYLIST_H
#define DL1203_ADJACENCYLIST_H
#include <iostream>

#define eleType int
#define MAXSIZE 100

class AdjacencyList
{
public:
    AdjacencyList(eleType dat[], int len);
    /*构造函数1  参数1: dat[]节点数组，传入所有节点;
               参数2: len节点的个数，需正确传入节点个数; */

    //AdjacencyList(eleType dat[], int len, int linenum);
    /*构造函数2  参数1: dat[]节点数组，传入所有节点;
                参数2: len节点的个数，需正确传入节点个数;
                参数3: linenum边或弧的数量;           */

    void GraphCreat();
    //建立节点之间的关系

    //void GraphCreat(int linenum);

    void GraphPrint();
    //输出图的形状

    //遍历
    void DFS(eleType v);    //深度优先遍历(遍历节点k的所有连通区域)
    void dfs();             //遍历出所有连通的区域

    void BFS(eleType v);    //广度优先遍历(遍历节点k的所有连通区域)
    void bfs();             //遍历出所有连通的区域

    //判断节点v1到节点v2是否存在路径为k的简单路径
    int findline(eleType v1, eleType v2, int k);

private:
    int nodesort(eleType v);    //返回查找的节点坐标，若未找到则返回-1

    //节点结构
    typedef struct Lnode
    {
        int index;
        int weight;
        Lnode * next;
    }*Llink;
    //邻接表的结构
    struct Adjnode
    {
        eleType data; //顶点数据元素
        Llink list;   //邻接点链表头指针
    };
    Adjnode Adjlist[MAXSIZE];
    bool jud1[MAXSIZE], jud2[MAXSIZE];
    int length = 0; bool visted[MAXSIZE];
    int node, line; //n为节点数，m为边数或弧数
};

#endif //DL1203_ADJACENCYLIST_H
