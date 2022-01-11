//
// Created by Wjh on 2021/12/3.
//

#ifndef DL1203_ADJACENCYMAT_H
#define DL1203_ADJACENCYMAT_H

#if !defined(MAXSIZE) && !defined(eleType)
#define MAXSIZE 100
#define eleType int
#endif


class AdjacencyMat {
public:
    AdjacencyMat(eleType dat[], int len);
    /*构造函数: 参数1: dat[]节点数组，传入所有节点;
               参数2: len节点的个数，需正确传入节点个数;*/

    void GraphCreat();
    //建立节点之间的关系

    void GraphPrint();

    //遍历
    void DFS(eleType v);    //深度优先搜索(遍历节点k的所有连通区域)
    void dfs();             //遍历出所有连通的区域

    void BFS(eleType v);    //广度优先搜索(遍历节点k的所有连通区域)
    void bfs();             //遍历出所有连通的区域

    //最小生成树
    int prime(eleType v);   //求得最小生成树的边权之和

private:
    int nodesort(eleType v);    //返回查找的节点坐标，若未找到则返回-1

    eleType Node[MAXSIZE]; //储存所有节点

    int AdjMat[MAXSIZE][MAXSIZE];
    bool jud1[MAXSIZE], jud2[MAXSIZE];
    int node, line; //n为节点数，m为边数或弧数
};



#endif //DL1203_ADJACENCYMAT_H
