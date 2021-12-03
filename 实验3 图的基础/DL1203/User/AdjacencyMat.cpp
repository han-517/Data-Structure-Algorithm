//
// Created by Wjh on 2021/12/3.
//

#include "../Header/AdjacencyMat.h"
#include <cstring>
#include <iostream>
#include <queue>

AdjacencyMat::AdjacencyMat(eleType dat[], int len)
{
    node = len; line = 0;
    memset(Node, 0, sizeof Node);
    memset(AdjMat, 0, sizeof AdjMat);
    memset(jud1, 0, sizeof jud1);
    memset(jud2, 0, sizeof jud2);
    for(int i = 0; i < len; i++) Node[i] = dat[i];
}

int AdjacencyMat::nodesort(eleType v)
{
    int index = -1;
    for(int i = 0; i < node; i++)
        if(Node[i] == v) index = i;
    return index;
}

void AdjacencyMat::GraphCreat()
{
    while(line < node * (node - 1) / 2)
    {
        std::cout << "";
        eleType v1, v2; int wi;
        std::cin >> v1 >> v2 >> wi;
        if(v1 == v2 || v1 < 0 || v2 < 0) break;
        ++line;
        int index1 = nodesort(v1), index2 = nodesort(v2);
        AdjMat[index1][index2] = wi, AdjMat[index2][index1] = wi;
    }
}

void AdjacencyMat::GraphPrint()
{
    for(int i = 0; i < node; i++)
        std::cout << "   " << Node[i];
    std::cout << std::endl;
    for(int i = 0; i < node; i++)
    {
        std::cout << Node[i] << "  ";
        for(int j = 0; j < node; j++)
            std::cout << AdjMat[i][j] << "   ";
        std::cout << std::endl;
    }
}

void AdjacencyMat::DFS(eleType v)
{
    int index = nodesort(v);
    if(!jud1[index])
    {
        std::cout << Node[index] << " ";
        jud1[index] = true;
    }
    for(int i = 0; i < node; i++)
        if(AdjMat[index][i] > 0 && !jud1[i]) DFS(Node[i]);
}
void AdjacencyMat::dfs()
{
    for(int k = 0; k < node; k++)
    {
        if(!jud1[k] && k)puts("");
        DFS(Node[k]);
    }
}

void AdjacencyMat::BFS(eleType v)
{
    int index = nodesort(v);
    std::queue<int> Que;
    if(!jud2[index])
    {
        std::cout << Node[index] << " ";
        jud2[index] = true;
        Que.push(index);
    }
    while(!Que.empty())
    {
        index = Que.front(); Que.pop();
        for(int i = 0; i < node; i++)
        {
            if(AdjMat[index][i] > 0 && !jud2[i])
            {
                std::cout << Node[i] << " ";
                jud2[i] = true;
                Que.push(nodesort(Node[i]));
            }
        }
    }
}
void AdjacencyMat::bfs()
{
    for(int k = 0; k < node; k++)
    {
        if(!jud2[k] && k) puts("");
        BFS(Node[k]);
    }
}

int AdjacencyMat::prime(eleType v)
{
    int res = 0; bool visted[node];
    int lowcost[node]; int index = nodesort(v);
    memset(visted, false, sizeof visted);
    memset(lowcost, 0x3f, sizeof lowcost);
    for(int i = 0; i < node; i++)
    {
        if(AdjMat[index][i]) lowcost[i] = AdjMat[index][i];
    }
    visted[index] = true;
    for(int i = 0; i < node - 1; i++)
    {
        int idxmin, weightmin = 0x3f3f3f3f;
        for(int j = 0; j < node; j++)
        {
            if(!visted[j] && weightmin > lowcost[j])
            {
                weightmin = lowcost[j];
                idxmin = j;
            }
        }
        index = idxmin;
        visted[index] = true;
        res += weightmin;
        for(int j = 0; j < node; j++)
            if(!visted[j] && lowcost[j] > AdjMat[index][j]) lowcost[j] = AdjMat[index][j];
    }

    return res;
}