#include <iostream>
#include <stdlib.h>
#include <queue>
#include <climits>

using namespace std;


int min(int a, int b) { return (a < b) ? a : b; }


int abs(int a) { return (a >= 0) ? a : (-1 * a); }


int main()
{
    int N, K;
    cin >> N >> K;

    int* heights = (int*) malloc(N*sizeof (int));
    int* cost = (int*) malloc(N*sizeof (int));
    int* mark = (int*) malloc(N*sizeof (int));

    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
        cost[i] = INT_MAX;
        mark[i] = 0;
    }
    cost[0] = 0;

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    int current = 0;
    mark[current] = 0;

    while(mark[N-1] == 0)
    {
        // update costs for the next K rocks:
        for (int i = current + 1; i <= min(current + K, N-1); i++)  // min(current + K, N-1) is to prevent sigsegev.
        {
            int original_cost = cost[i];
            cost[i] = min(cost[i], cost[current] + abs(heights[current] - heights[i]));
            int new_cost = cost[i];

            if (new_cost < original_cost)
                heap.push(make_pair(cost[i], i));
        }

        current = heap.top().second;
        heap.pop();
        mark[current] = 1;
    }

    cout << cost[N-1];

    return 0;
}
