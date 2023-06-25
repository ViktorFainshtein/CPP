#include "bfs.hpp"

using namespace ilrd;

Graph::Graph(int v)
{
    this->m_v = v;
    adj.resize(v);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    std::vector<bool> visited;
    visited.resize(m_v,false);

    std::list<int> queue;
    
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty())
    {
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        for(int i = 0; i < adj[s].size(); ++i)
        {
            int adjacent = adj[s].at(i);
            if(!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}
