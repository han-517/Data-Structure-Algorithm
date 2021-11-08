//
// Created by Wjh on 2021/11/3.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <cstdint>
#include <string>
#include <cstring>
#include <vector>

class HuffTree {
public:
    struct HT_Node
    {
        char data;                   //存放节点的元素值
        int  Wight;                  //存放节点的权值
        int  parent, left, right;    //存放指向双亲节点，左右子节点的元素值
    };
    HuffTree(std::string code);
    void Init();                     //传入字符串参数，将字符串转换为Huffman树

    void Tree_Creat();               //创建哈夫曼树

    void Tree_Print();               //遍历哈夫曼树

    void Tree_Convert();             //求解哈夫曼编码

private:
    std::string                         Code;       //用户所输入的字符串，被处理前
    uint32_t                            Length;     //去重后的字符个数
    std::vector<std::pair<char, int>>   temp;       //储存字符及其权重大小
    HT_Node *                           Hufftree;   //储存构造好的哈夫曼树
    void WeightSort(int j, int &index1, int &index2);
};


#endif //HUFFMAN_TREE_H