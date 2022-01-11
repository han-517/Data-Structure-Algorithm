#include <iostream>
#include <cstring>
#include "../Header/AdjacencyMat.h"
#include "../Header/AdjacencyList.h"

int main() {
    //ʵ��4.1
    std::cout << "---�ڽӾ���---";
    int len2, element2;
    std::cout << "\n����ڵ����\n";
    std::cin >> len2;
    eleType data2[MAXSIZE];
    std::cout << "����ڵ�\n";
    for(int i = 0; i < len2; i++) std::cin >> data2[i];
    auto * Graph2 = new AdjacencyMat(data2, len2);
    std::cout << "\n����ͼ�ı�\n";
    Graph2->GraphCreat();
    std::cout << "\n����ͼ\n";
    Graph2->GraphPrint();
    std::cout << "\n����ڵ�: ";
    std::cin >> element2;
    std::cout << "��С������: ";
    std::cout << Graph2->prime(element2) << std::endl;

    //ʵ��4.2
    std::cout << "---�ڽӱ�---\n";
    int len1, element1, v, length;
    std::cout << "����ڵ����\n";
    std::cin >> len1;
    eleType data1[MAXSIZE];
    std::cout << "����ڵ�\n";
    for(int i = 0; i < len1; i++) std::cin >> data1[i];
    auto * Graph1 = new AdjacencyList(data1, len1);
    Graph1->GraphCreat();
    std::cout << "\n����ͼ\n";
    Graph1->GraphPrint();
    std::cout << "\n������Ҫ��ѯ��·��: ";
    while(std::cin >> element1 >> v >> length)
    {
        std::cout << "�Ƿ���ڣ�1������ڣ�0�������ڣ���" << Graph1->findline(element1, v, length) << std::endl;
    }



    return 0;
}
