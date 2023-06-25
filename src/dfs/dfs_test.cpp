#include "dfs.hpp"

using namespace ilrd;

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
/*     std::cout << "Following is Depth First Traversal"
            " (starting from vertex 2) - Recursive method: " << std::endl;
 
    g.DFS_rec(2);

    std::cout << std::endl; */

    std::cout << "Following is Depth First Traversal"
        " (starting from vertex 2) - linear method: " << std::endl;

    g.DFS_iter(2);

    std::cout << std::endl;

    return 0;
}