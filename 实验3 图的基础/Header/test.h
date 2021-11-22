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
    std::cout << "�����봴������:\n[0/1]: �ڽӾ���/�ڽӱ�\n";
    std::cin >> ch;
    system("cls");
    if(ch)
    {
        //���ڽӱ�Ϊ��������ͼ
        std::cout << "---�ڽӱ�---\n";
        int len1, element1;
        std::cout << "����ڵ����\n";
        std::cin >> len1;
        eleType data1[MAXSIZE];
        std::cout << "����ڵ�\n";
        for(int i = 0; i < len1; i++) std::cin >> data1[i];
        auto * Graph1 = new AdjacencyList(data1, len1);
        Graph1->GraphCreat();
        std::cout << "\n����ͼ\n";
        Graph1->GraphPrint();
        //std::cout << "\n������Ҫ��ѯ�Ľڵ�: ";
        //std::cin >> element1;
        std::cout << "\n�����������\n";
        Graph1->dfs();
        std::cout << "\n�����������\n";
        Graph1->bfs();
    }
    else
    {
        //���ڽӾ��󹹽�ͼ
        std::cout << "---�ڽӾ���---";
        int len2, element2;
        std::cout << "\n����ڵ����\n";
        std::cin >> len2;
        eleType data2[MAXSIZE];
        std::cout << "����ڵ�\n";
        for(int i = 0; i < len2; i++) std::cin >> data2[i];
        auto * Graph2 = new AdjacencyMat(data2, len2);
        Graph2->GraphCreat();
        std::cout << "\n����ͼ\n";
        Graph2->GraphPrint();
        //std::cout << "\n������Ҫ��ѯ�Ľڵ�: ";
        //std::cin >> element2;
        std::cout << "\n�����������\n";
        Graph2->dfs();
        std::cout << "\n�����������\n";
        Graph2->bfs();
    }
    puts("");
    system("Pause");
}

#endif //DL1116_TEST_H
