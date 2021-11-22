//
// Created by Wjh on 2021/11/16.
//

#include "../Header/AdjacencyList.h"
#include <cstring>
#include <queue>

AdjacencyList::AdjacencyList(eleType dat[], int len) {
    node = len; line = 0;
    memset(jud1, 0, sizeof jud1);
    memset(jud2, 0, sizeof jud2);
    for(int i = 0; i < len; i++)
    {
        this->Adjlist[i].data = dat[i];
        this->Adjlist[i].list = NULL;
    }
}

int AdjacencyList::nodesort(eleType v)
{
    //ToDo:算法优化
    int index = -1;
    for(int i = 0; i < node; i++)
        if(Adjlist[i].data == v) index = i;
    return index;
}

void AdjacencyList::GraphCreat()
{
    /*ToDo: 1.在输入不存在的节点时可以提示并需重新输入
     *      2.在数组中节点的数据检查时算法需要优化    */
    while(line < node * (node - 1))
    {
        std::cout << "请输入节点1 节点2 权重\n";
        eleType v1, v2; int wi;
        std::cin >> v1 >> v2 >> wi;
        if(v1 == v2 || v1 < 0 || v2 < 0) break;
        ++line;
        int index1 = nodesort(v1), index2 = nodesort(v2); //节点寻找
        auto p = (Llink) malloc(sizeof(Lnode));
        p->index = index2, p->weight = wi;
        p->next = Adjlist[index1].list;
        Adjlist[index1].list = p;
    }
}

void AdjacencyList::GraphPrint()
{
    for(int k = 0; k < node; k++)
    {
        std::cout << Adjlist[k].data << " -> " ;
        auto p = Adjlist[k].list; int idx = 0;
        while(p)
        {
            idx++;
            std::cout << Adjlist[p->index].data << " " << p->weight << " | ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}

void AdjacencyList::DFS(eleType v)
{
    int index = nodesort(v);
    if(!jud1[index])
    {
        std::cout << Adjlist[index].data << " ";
        jud1[index] = true;
    }
    auto p = Adjlist[index].list;
    while(p)
    {
        if(!jud1[p->index]) DFS(Adjlist[p->index].data);
        p = p->next;
    }
}
void AdjacencyList::dfs()
{
    for(int k = 0; k < node; k++)
    {
        if(!jud1[k] && k) puts("");
        DFS(Adjlist[k].data);
    }
}

void AdjacencyList::BFS(eleType v)
{
    int index = nodesort(v);
    std::queue<int> Que;
    if(!jud2[index])
    {
        std::cout << Adjlist[index].data << " ";
        jud2[index] = true;
        Que.push(index);
    }
    while(!Que.empty())
    {
        index = Que.front(); Que.pop();
        if(Adjlist[index].list)
        {
            auto q = Adjlist[index].list;
            while(q)
            {
                if(!jud2[q->index])
                {
                    std::cout << Adjlist[q->index].data << " ";
                    jud2[q->index] = true;
                    Que.push(q->index);
                }
                q = q->next;
            }
        }
    }
}
void AdjacencyList::bfs()
{
    for(int k = 0; k < node; k++)
    {
        if(!jud2[k] && k) puts("");
        BFS(Adjlist[k].data);
    }
}