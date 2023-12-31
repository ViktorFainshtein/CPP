#include "bfs.hpp"

using namespace ilrd;

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    std::cout << "Following is Breadth First Traversal (starting from vertex 2):"
                << std::endl;
    
    g.BFS(2);

    std::cout << std::endl;

    return 0;
}