
#pragma once

#include <bits/stdc++.h>
#include <vector>

namespace ilrd
{
class Graph
{
public:
    Graph(int v);                       //CTOR
    void addEdge(int v, int w);         //Add Edges
    void BFS(int s);                    //Run Bfs Algo On The Graph
private:
    int m_v;                              //num of vertices
    std::vector< std::vector<int> > adj;    //array containing adjacency lists
};//class Graph
}//namespace ilrd