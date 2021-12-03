#include <iostream>
#include <cstring>
#include "../Header/AdjacencyMat.h"
#include "../Header/AdjacencyList.h"

int main() {
    //实验4.1
    std::cout << "---邻接矩阵---";
    int len2, element2;
    std::cout << "\n输入节点个数\n";
    std::cin >> len2;
    eleType data2[MAXSIZE];
    std::cout << "输入节点\n";
    for(int i = 0; i < len2; i++) std::cin >> data2[i];
    auto * Graph2 = new AdjacencyMat(data2, len2);
    std::cout << "\n构建图的边\n";
    Graph2->GraphCreat();
    std::cout << "\n遍历图\n";
    Graph2->GraphPrint();
    std::cout << "\n输入节点: ";
    std::cin >> element2;
    std::cout << "最小生成树: ";
    std::cout << Graph2->prime(element2) << std::endl;

    //实验4.2
    std::cout << "---邻接表---\n";
    int len1, element1, v, length;
    std::cout << "输入节点个数\n";
    std::cin >> len1;
    eleType data1[MAXSIZE];
    std::cout << "输入节点\n";
    for(int i = 0; i < len1; i++) std::cin >> data1[i];
    auto * Graph1 = new AdjacencyList(data1, len1);
    Graph1->GraphCreat();
    std::cout << "\n遍历图\n";
    Graph1->GraphPrint();
    std::cout << "\n输入你要查询的路径: ";
    while(std::cin >> element1 >> v >> length)
    {
        std::cout << "是否存在（1代表存在，0代表不存在）：" << Graph1->findline(element1, v, length) << std::endl;
    }



    return 0;
}
