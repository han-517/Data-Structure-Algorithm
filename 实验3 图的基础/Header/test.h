//
// Created by Wjh on 2021/11/19.
//

#ifndef DL1116_TEST_H
#define DL1116_TEST_H
#include "../Header/AdjacencyList.h"
#include "../Header/AdjacencyMat.h"
void test()
{
    bool ch = false;
    std::cout << "请输入创建类型:\n[0/1]: 邻接矩阵/邻接表\n";
    std::cin >> ch;
    system("cls");
    if(ch)
    {
        //以邻接表为基础构建图
        std::cout << "---邻接表---\n";
        int len1, element1;
        std::cout << "输入节点个数\n";
        std::cin >> len1;
        eleType data1[MAXSIZE];
        std::cout << "输入节点\n";
        for(int i = 0; i < len1; i++) std::cin >> data1[i];
        auto * Graph1 = new AdjacencyList(data1, len1);
        Graph1->GraphCreat();
        std::cout << "\n遍历图\n";
        Graph1->GraphPrint();
        //std::cout << "\n输入你要查询的节点: ";
        //std::cin >> element1;
        std::cout << "\n深度优先搜索\n";
        Graph1->dfs();
        std::cout << "\n广度优先搜索\n";
        Graph1->bfs();
    }
    else
    {
        //以邻接矩阵构建图
        std::cout << "---邻接矩阵---";
        int len2, element2;
        std::cout << "\n输入节点个数\n";
        std::cin >> len2;
        eleType data2[MAXSIZE];
        std::cout << "输入节点\n";
        for(int i = 0; i < len2; i++) std::cin >> data2[i];
        auto * Graph2 = new AdjacencyMat(data2, len2);
        Graph2->GraphCreat();
        std::cout << "\n遍历图\n";
        Graph2->GraphPrint();
        //std::cout << "\n输入你要查询的节点: ";
        //std::cin >> element2;
        std::cout << "\n深度优先搜索\n";
        Graph2->dfs();
        std::cout << "\n广度优先搜索\n";
        Graph2->bfs();
    }
    puts("");
    system("Pause");
}

#endif //DL1116_TEST_H
