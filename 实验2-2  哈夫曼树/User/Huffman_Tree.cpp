//
// Created by Wjh on 2021/11/3.
//

#include "../Header/Huffman_Tree.h"
#include <iostream>

HuffTree::HuffTree(std::string code)
{
    this->Code = code;
}

void HuffTree::Init()
{
    Length = 0; uint32_t len = Code.length();
    for(int i = 0, j; i < len; i++)
    {
        for(j = 0; j < Length; j++)
        {
            if(Code[i] == temp[j].first)
            {temp[j].second++; break;}
        }
        if(j == Length++) temp.push_back({Code[i], 1});
    }
    Length = temp.size();
    Hufftree = new HT_Node[2 * Length];
    for(int i = 1; i < 2 * Length; i++)
        Hufftree[i].data   = 0,
        Hufftree[i].Wight  = 0,
        Hufftree[i].parent = 0,
        Hufftree[i].left   = 0,
        Hufftree[i].right  = 0;
}

void HuffTree::Tree_Creat()
{
    int s1 = 0, s2 = 0;
    for(int i = 1; i <= Length; i++)
        Hufftree[i].data = temp[i-1].first,
        Hufftree[i].Wight = temp[i-1].second;
    for(int i = Length + 1; i <= 2 * Length - 1; i++)
    {
        WeightSort(i, s1, s2);
        Hufftree[i].left = s1, Hufftree[i].right = s2;
        Hufftree[i].Wight = Hufftree[s1].Wight + Hufftree[s2].Wight;
    }
    Hufftree[0] = Hufftree[2 * Length - 1];
}

void HuffTree::WeightSort(int j, int &index1, int &index2)
{
    int min = 0x3f3f3f3f;
    for(int i = 1; i < j; i++)
        if(Hufftree[i].parent == 0 && Hufftree[i].Wight < min)
        {index1 = i, min = Hufftree[i].Wight;}
    Hufftree[index1].parent = j;
    min = 0x3f3f3f3f;
    for(int i = 1; i < j; i++)
        if(Hufftree[i].parent == 0 && Hufftree[i].Wight < min)
        {index2 = i, min = Hufftree[i].Wight;}
    Hufftree[index2].parent = j;
}

void HuffTree::Tree_Print()
{
    std::cout << "\t哈夫曼树\n";
    std::cout << "字符    权重    父节点    左节点    右节点\n";
    for(int i = 1; i < 2 * Length; i++)
        std::cout << Hufftree[i].data   << "        "
                  << Hufftree[i].Wight  << "        "
                  << Hufftree[i].parent << "        "
                  << Hufftree[i].left   << "        "
                  << Hufftree[i].right  << "        "
                  << std::endl;
}

void HuffTree::Tree_Convert()
{
    for(int i = 1; i <= Length; i++)
    {
        std::vector<int> tmp; int j = i;
        while(Hufftree[j].parent != 0)
        {
            int np = Hufftree[j].parent;
            if(Hufftree[np].left == j)
            {tmp.push_back(0);}
            else {tmp.push_back(1);}
            j = np;
        }
        std::cout << "字符" << Hufftree[i].data << "的编码是：";
        for(int k = tmp.size() - 1; k >= 0; k--)
            std::cout << tmp[k];
        std::cout <<  std::endl;
    }
}
