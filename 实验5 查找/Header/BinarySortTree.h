//
// Created by Wjh on 2021/12/17.
//

#ifndef DL1216_BINARYSORTTREE_H
#define DL1216_BINARYSORTTREE_H
class BSTree
{
private:
    typedef struct TNode
    {
        int data;
        TNode *lc;  //左孩子
        TNode *rc;  //右孩子
    }TNode, *Tree;

public:
    Tree root;

    BSTree();

    //查找二叉排序树，若存在则返回1，不存在返回1
    int searchtree(Tree T, int key);

    //查找二叉排序树是否存在这个节点，并返回这个节点，否则返回0
    Tree searchtree(Tree T, int key, Tree &p);

    //二叉排序树插入节点，如果树里存在这个节点则不进行插入操作。若成功插入则返回1
    int insert(Tree &T, int key);

    //若查找不成功，则返回0，不执行删除操作;否则删除该节点并返回1
    int deleteNode(Tree &T, int key);
};
#endif //DL1216_BINARYSORTTREE_H
