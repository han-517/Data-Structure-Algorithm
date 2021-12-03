//
// Created by Wjh on 2021/12/3.
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
    int index = -1;
    for(int i = 0; i < node; i++)
        if(Adjlist[i].data == v) index = i;
    return index;
}

void AdjacencyList::GraphCreat()
{
    while(line < node * (node - 1))
    {
        std::cout << "";
        eleType v1, v2; int wi;
        std::cin >> v1 >> v2 >> wi;
        if(v1 == v2 || v1 < 0 || v2 < 0) break;
        ++line;
        int index1 = nodesort(v1), index2 = nodesort(v2);
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

int AdjacencyList::findline(eleType v1, eleType v2, int k)
{
    int index = nodesort(v1); std::vector<int> tmp;
    std::queue<std::pair<int, int>> Que;
    if(!jud2[index])
    {
        //std::cout << Adjlist[index].data << " ";
        jud2[index] = true;
        Que.push({index,0});
    }
    while(!Que.empty())
    {
        index = Que.front().first;
        if(Adjlist[index].list)
        {
            auto q = Adjlist[index].list;
            while(q)
            {
                if(!jud2[q->index])
                {
                    if(Adjlist[q->index].data == v2)
                    {
                        tmp.push_back(Que.front().second + q->weight);
                    }
                    else
                    {
                        //std::cout << Adjlist[q->index].data << " ";
                        jud2[q->index] = true;
                        Que.push({q->index,Que.front().second + q->weight});
                    }
                }
                q = q->next;
            }
        }
        Que.pop();
    }
    memset(jud2, 0, sizeof jud2);
    for(auto i : tmp) if(i == k) return 1;
    return 0;
}