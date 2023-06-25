#pragma once
#include <bits/stdc++.h>
#include <vector>
#include <map>


namespace ilrd
{

class Graph
{
public:
    std::map<int, bool> visited;
    std::map<int, std::list<int> > adj;

    void addEdge(int v, int w);
    void DFS_rec(int v);
    void DFS_iter(int v);
};

}//namespace ilrd