//
// Created by Wjh on 2021/12/17.
//

#include "../Header/BinarySortTree.h"
#include <algorithm>
BSTree::BSTree()
{
    this->root = (Tree) malloc(sizeof(TNode));
    this->root->data = -1;
    this->root->lc = this->root->rc = NULL;
}

int BSTree::searchtree(Tree T, int key)
{
    if(!T) return 0;
    if(T->data == key) return 1;
    if(key < T->data) return searchtree(T->lc, key);
    else return searchtree(T->rc, key);
}

BSTree::Tree BSTree::searchtree(Tree T, int key, Tree &p)
{
    if(!T) return 0;
    if(key == T->data) return T;
    p = T;
    if(key < T->data) return searchtree(T->lc, key, p);
    return searchtree(T->rc, key, p);
}

int BSTree::insert(Tree &T, int key)
{
    Tree p = T;
    if(searchtree(T, key, p)) return 0;
    Tree s = (Tree)malloc(sizeof(BSTree::TNode));
    s->data = key;
    s->lc = s->rc = NULL;
    if(!p) T = s;
    else
    {
        if (key < p->data) p->lc = s;
        else p->rc = s;
    }
    return 1;
}

int BSTree::deleteNode(Tree &T, int key)
{
    Tree p = T;
    if(!searchtree(T, key, p)) return 0;
    //删除操作
    if(p->lc == NULL && p->rc != NULL)
    {
        Tree q = p->rc;
        p->data = q->data;
        p->lc = q->lc, p->rc = q->rc;
        free(q);
    }
    else if(p->lc != NULL && p->rc == NULL)
    {
        Tree q = p->lc;
        p->data = q->data;
        p->lc = q->lc, p->rc = q->rc;
        free(q);
    }
    else if(p->lc != NULL && p->rc != NULL)
    {
        Tree q = p, s = p->lc;
        while(s->rc) {p = s; s = s->rc;}
        q->data = s->data;
        if(p == q) q->lc = s->lc;
        else p->rc = s->lc;
    }
}
