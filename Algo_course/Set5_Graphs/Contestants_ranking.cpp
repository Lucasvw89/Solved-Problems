#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


using namespace std;


struct g{
    int** matrix;
    int numNodes;
    int* visited;
};

typedef struct g Graph;


Graph* create_new_graph(int numNodes)
{
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));

    new_graph->numNodes = numNodes;

    new_graph->matrix = (int**) malloc(numNodes * sizeof (int*));

    new_graph->visited = (int*)malloc(numNodes * sizeof(int));

    for (int i = 0; i < numNodes; i++)
    {
        new_graph->visited[i] = 0;

        new_graph->matrix[i] = (int*) calloc(numNodes, sizeof(int));
    }

    return new_graph;
}


void setEdge(Graph* graph, int v, int w)
{
    graph->matrix[v][w] = 1;
    graph->matrix[w][v] = 1;
}


void BFS(Graph* graph, int start, map<int, string>& map_hash)
{
    int size_of_ranking;
    int current_node;
    int rank = 1;

    queue<int> que;
    que.push(start);

    graph->visited[start] = 1;

    while (!que.empty())
    {
        size_of_ranking = que.size();
        vector<string> names;

        for (int i = 0; i < size_of_ranking; i++)
        {
            current_node = que.front();
            que.pop();

            for (int j = 0; j < graph->numNodes; j++)
            {
                if (graph->matrix[current_node][j] && !graph->visited[j]) {
                    graph->visited[j] = 1;
                    que.push(j);

                    names.push_back(map_hash[j]);
                }
            }
        }
        sort(names.begin(), names.end());
        for (int j = 0; j < names.size(); j++)
        {
            cout << names[j] << " " << rank << endl;
        }
        rank++;
    }

    vector<string> forgotten;

    for (int j = 0; j < graph->numNodes; j++)
    {
        if(!graph->visited[j] && map_hash[j] != "")
        {
            forgotten.push_back(map_hash[j]);
        }
    }

    sort(forgotten.begin(), forgotten.end());

    for (int j = 0; j < forgotten.size(); j++)
    {
        cout << forgotten[j] << " undefined" << endl;
    }
}


int main()
{
    int T, N;

    string name1, name2, name3;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        Graph* graph = create_new_graph(3*N);
        int current_idx = 0;

        map<string, int> hash_map;
        map<int, string> map_hash;

        for (int j = 0; j < N; j++)
        {
            cin >> name1 >> name2 >> name3;

            if (hash_map.find(name1) == hash_map.end())
            {
                hash_map[name1] = current_idx;
                map_hash[current_idx] = name1;
                current_idx++;
            }
            if (hash_map.find(name2) == hash_map.end())
            {
                hash_map[name2] = current_idx;
                map_hash[current_idx] = name2;
                current_idx++;
            }
            if (hash_map.find(name3) == hash_map.end())
            {
                hash_map[name3] = current_idx;
                map_hash[current_idx] = name3;
                current_idx++;
            }

            setEdge(graph,hash_map[name1], hash_map[name2]);
            setEdge(graph,hash_map[name2], hash_map[name3]);
            setEdge(graph,hash_map[name1], hash_map[name3]);
        }

        cout << current_idx << endl << "Ahmad 0" << endl;

        BFS(graph, hash_map["Ahmad"], map_hash);



        free(graph);
    }
    return 0;
}
