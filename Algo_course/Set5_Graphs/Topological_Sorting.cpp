#include <iostream>
#include <vector>
#include <queue>


using namespace std;


int main()
{
    int n, m;
    int x, y;


    cin >> n >> m;
    vector<int> adj[n];
    vector<int> answer;

    int* dependencies = (int*) calloc(n, sizeof (int));

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        dependencies[y - 1]++;
        adj[x - 1].push_back(y - 1);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        if (dependencies[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int current = pq.top();
        answer.push_back(current + 1);
        pq.pop();

        for(int i = 0; i < adj[current].size(); i++)
        {
            dependencies[adj[current][i]]--;
            if (dependencies[adj[current][i]] == 0)
            {
                pq.push(adj[current][i]);
            }
        }
    }

    if (answer.size() < n)
    {
        cout << "Sandro fails." << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << answer[i] << " ";
        }
    }

    return 0;
}

