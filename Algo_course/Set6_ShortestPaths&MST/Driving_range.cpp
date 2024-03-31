#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct g{
    vector<pair<int, int>>* dist;
    int numNodes;
    int* distance;
};

typedef struct g Graph;


Graph* create_new_graph(int numNodes)
{
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));

    new_graph->numNodes = numNodes;

    new_graph->dist = new vector<pair<int, int> > [numNodes];

    new_graph->distance = (int*)malloc(numNodes * sizeof(int));

    for (int i = 0; i < numNodes; i++)
    {
        new_graph->distance[i] = INT_MAX;
    }

    return new_graph;
}


void setEdge(Graph* graph, int v, int w, int wt)
{
    graph->dist[v].push_back(make_pair(wt, w));
}


void prim(Graph* graph, int start)   // start is the starting vertex.
{
    // mark starting vertex as visited:
    int current = start;
    graph->distance[start] = 0;

    // create priority queue with a heap:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> heap;      // pair<graph->dist, vertex>

    for (int i = 0; i < graph->dist[start].size(); i++)
    {
        heap.emplace(graph->dist[start][i]);
    }


    while (true)
    {
        if (heap.empty())  // not capable of reaching that vertex.
        {
            return;
        }
        current = heap.top().second;
        int current_distance = heap.top().first;
        heap.pop();

        if (graph->distance[current] < current_distance) { continue; }

        graph->distance[current] = current_distance;


        // update vertex graph->distances:
        for (auto i: graph->dist[current])
        {
            int dist_current_to_i = i.first;
            int i_idx = i.second;


            if (dist_current_to_i < graph->distance[i_idx])
            {
                graph->distance[i_idx] = dist_current_to_i;
                heap.emplace(graph->distance[i_idx], i_idx);
            }
        }
    }
}

int main()
{
    int N, M, X, Y, W;
    while (true)
    {
        cin >> N;
        cin >> M;

        if (N == 0 && M == 0) { return 0; }

        Graph* graph = create_new_graph(N);

        for (int i = 0; i < M; i++)
        {
            cin >> X >> Y >> W;
            setEdge(graph, X, Y, W);
            setEdge(graph, Y, X, W);
        }

        prim(graph, 0);

        int largest = 0;

        for (int i = 0; i < graph->numNodes; i++)
        {
            if (graph->distance[i] > largest) { largest = graph->distance[i]; }
        }

        if (largest == INT_MAX)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << largest << endl;
        }
    }
}
