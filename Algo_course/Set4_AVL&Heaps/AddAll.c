#include <stdlib.h>
#include <stdio.h>


void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}


void Heapify(int H[], int n)
{
    int i;
    for (i = n / 2; i >= 1 ; i--)
    {
        int k = i; int v = H[k];
        int heap = 0;

        while (heap == 0 && (2 * k) <= n)
        {
            int j = 2 * k;
            if (j < n)
            {
                if (H[j] >= H[j + 1])
                {
                    j = j + 1;
                }
            }
            if (v < H[j])
            {
                heap = 1;
            }
            else
            {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}


int calculate_min_cost(int heap[], int N)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (N > 1)
    {
        Heapify(heap, N);

        a = heap[1];

        swap(&heap[1], &heap[N]);

        N = N - 1;

        Heapify(heap, N);

        b = heap[1];
        c += (a + b);
        heap[1] = (a + b);
    }
    return c;
}


int main()
{
    int N, i = 1;

    while (1)
    {
        scanf("%d", &N);
        if (N == 0) {return 0;}

        int* heap = (int*)malloc((N+1) * sizeof(int));
        heap[0] = 0;

        for (i = 1; i < N + 1; i++)
        {
            scanf("%d", &heap[i]);
        }

        int custo_final = calculate_min_cost(heap, N);

        printf("%d\n", custo_final);
    }
}
