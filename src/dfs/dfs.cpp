#include "dfs.hpp"

using namespace ilrd;

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS_rec(int v)
{
    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
        {
            DFS_rec(*i);
        }
    }
}

void Graph::DFS_iter(int v)
{
    std::stack<int> stack;
    stack.push(v);

    while(!stack.empty())
    {
        v = stack.top();
        std::cout << v << " ";
        stack.pop();
        
        if(visited[v] == false)
        {
            visited[v] = true;
            for(int i = 0; i < this->adj[v].size(); ++i)
            {
                int node = adj[v].front();
                adj[v].pop_front();
                if(visited[node] == false)
                {
                    stack.push(node);
                }
            }
        }
    }
}