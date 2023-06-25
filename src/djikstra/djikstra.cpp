#include "djikstra.hpp"

using namespace ilrd;

Graph::Graph(int V):V(V), adj(new std::list<iPair>[V]){}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
}

void Graph::shortestPath(int src)
{
    std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair> > pq;
    std::vector<int> dist(V, INF);
    pq.push(std::make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        std::list<std::pair<int, int> >::iterator i;
        for(i = adj[u].begin(); i != adj[u].end();++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
    std::cout << "Vertex Distance from Source " << std::endl;
    for(int i = 0; i < V; ++i)
    {
        std::cout << i << "\t\t" << dist[i] << std::endl;
    }
}