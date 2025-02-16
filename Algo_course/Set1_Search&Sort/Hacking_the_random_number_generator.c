#include <stdio.h>
#include <stdlib.h>


int minimum(long a, long b)
{
    if (a<b) {return a;}
    return b;
}


void merge_sort(long array[], size_t size)
{
    if (size == 1) {return;}

    long* first_half;
    long* second_half;

    first_half = (long*)malloc((size/2) * sizeof(long));

    second_half = (long*)malloc((size - (size/2)) * sizeof(long));

    for (size_t i = 0; i < size/2; i++)
    {
        first_half[i] = array[i];
    }

    for (size_t i = 0; i <size - (size/2); i++)
    {
        second_half[i] = array[i + size/2];
    }

    merge_sort(first_half, size/2);
    merge_sort(second_half, size - (size/2));

    long i = 0, j = 0;

    while(i < size/2 && j < size - (size/2)){
        if (first_half[i] <= second_half[j]){
            array[i+j] = first_half[i];
            i++;
        }
        else{
            array[i+j] = second_half[j];
            j++;
        }
    }
    
    while (i < size/2){
        array[i+j] = first_half[i];
        i++;
    }
    while (j < size - (size/2)){
        array[i+j] = second_half[j];
        j++;
    }
    free(first_half);
    free(second_half);
}


int main()
{
    long n, k, mini, total = 0;
    scanf("%ld %ld", &n, &k);

    long * set = (long *)malloc(n * sizeof(long));

    for (long i = 0; i < n; i++)
    {
        scanf("%ld", &set[i]);
    }

    merge_sort(set, n);

    for (long i = 0; i < n; i++)
    {
        mini = minimum(n, i+k+1);
        for (long j = i; j < mini; j++)
        {
            if(set[j] == set[i] + k) {total += 1;}
        }
    }

    printf("%ld", total);

    free(set);

    return 0;
}
