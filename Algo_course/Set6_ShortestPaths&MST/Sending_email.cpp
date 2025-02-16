#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct g{
    vector<pair<int, int>>* dist;
    int numNodes;
    int* mark;
    int* distance;
};

typedef struct g Graph;


Graph* create_new_graph(int numNodes)
{
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));

    new_graph->numNodes = numNodes;

    new_graph->dist = new vector<pair<int, int> > [numNodes];

    new_graph->mark = (int*)malloc(numNodes * sizeof(int));
    new_graph->distance = (int*)malloc(numNodes * sizeof(int));

    for (int i = 0; i < numNodes; i++)
    {
        new_graph->mark[i] = 0;
        new_graph->distance[i] = INT_MAX;
        // new_graph->graph->dist[i];
    }

    return new_graph;
}


void setEdge(Graph* graph, int v, int w, int wt)
{
    graph->dist[v].push_back(make_pair(wt, w));
    graph->dist[w].push_back(make_pair(wt, v));
}


void dijkstra(Graph* graph, int start, int final)   // start is the starting vertex.     // final is the objective vertex
{
    // mark starting vertex as visited:
    int current = start;
    graph->distance[start] = 0;
    graph->mark[start] = 1;

    // create priority queue with a heap:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> heap;      // pair<graph->dist, vertex>

    for (int i = 0; i < graph->dist[start].size(); i++)
    {
        heap.emplace(graph->dist[start][i]);
    }


    while (graph->mark[final] == 0)
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

        graph->mark[current] = 1;

        // update vertex graph->distances:

        for (auto i: graph->dist[current])
        {
            int dist_current_to_i = i.first;
            int i_idx = i.second;


            if (graph->distance[current] + dist_current_to_i < graph->distance[i_idx])
            {
                graph->distance[i_idx] = graph->distance[current] + dist_current_to_i;
                heap.emplace(graph->distance[i_idx], i_idx);
            }
        }
    }
}


int main()
{
    int N, n, m, S, T, w;
    int x, y;
    int exists = 0, idx = -1;

    cin >> N;



    for (int case_num = 1; case_num <= N; case_num++)
    {
        cin >> n;
        cin >> m;
        cin >> S;
        cin >> T;

        Graph* graph = create_new_graph(n);

        for (int j = 0; j < m; j++)
        {
            cin >> x;
            cin >> y;

            cin >> w;

            setEdge(graph, x, y, w);
        }
        dijkstra(graph, S, T);

        if (graph->distance[T] != INT_MAX){
            exists = 1;
            idx = T;
        }


        if (exists == 0) {cout << "Case #" << case_num << ": " << "unreachable" << endl;}

        else {cout << "Case #" << case_num << ": " << graph->distance[T] << endl;}

        free(graph);
        idx = -1;
        exists = 0;
    }

    return 0;
}
