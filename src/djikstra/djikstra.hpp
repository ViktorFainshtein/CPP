
#include <iostream>
#include <bits/stdc++.h>
#include <list>

#define INF 0x3f3f3f3f
typedef std::pair<int, int> iPair;

namespace ilrd
{

class Graph
{
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);           //Time Complexity: O(E*logV) , Space Complexity: O(V)
private:
    int V;
    std::list<std::pair<int,int> >* adj;
};//class Graph

}//name space ilrd