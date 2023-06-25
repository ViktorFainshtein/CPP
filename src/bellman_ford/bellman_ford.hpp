
#include <bits/stdc++.h>

typedef struct Edge
{
    int src, dest, weight;
}Edge_t;

typedef struct Graph
{
    int V, E;
    Edge_t *edge;
}Graph_t;

Graph_t *createGraph(int V, int E);

void printArr(int dist[], int n);

void BellmanFord(Graph_t *graph, int src);