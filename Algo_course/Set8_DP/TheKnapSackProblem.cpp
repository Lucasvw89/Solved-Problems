#include <iostream>
#include <stdlib.h>

using namespace std;


int max(int a, int b)
{
    return (a > b) ? a : b;
}


int main()
{
    int S, N;
    cin >> S >> N;

    int* values = (int*)malloc((N + 1) * sizeof(int));
    int* wheights = (int*)malloc((N + 1) * sizeof(int));

    values[0] = 0;
    wheights[0] = 0;

    int wheight, value;
    for (int i = 1; i <= N; i++)
    {
        cin >> wheight >> value;
        values[i] = value;
        wheights[i] = wheight;
    }

    int** best = (int**)malloc((N + 1) * sizeof(int*));

    for (int i = 0; i < N+1; i++)
    {
        best[i] = (int*)malloc((S+1) * sizeof(int));
        for (int j = 0; j < S+1; j++)
        {
            best[i][j] = 0;
        }
    }


    for (int item = 1; item <= N; item++)
    {
        for (int capacity = 1; capacity < S+1; capacity++)
        {
            if (capacity - wheights[item] >= 0)
            {
                best[item][capacity] = max(values[item] + best[item - 1][capacity - wheights[item]], best[item - 1][capacity]);
            }
            else
            {
                best[item][capacity] = best[item - 1][capacity];
            }
        }
    }

    cout << best[N][S];

    return 0;
}
