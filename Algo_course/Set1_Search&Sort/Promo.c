# include <stdio.h>
# include <stdlib.h>


void merge_sort(unsigned long long array[], unsigned long size)
{
    if (size == 1) {return;}

    unsigned long long* first_half;
    unsigned long long* second_half;

    first_half = (unsigned long long*)malloc((size/2) * sizeof(unsigned long long));

    second_half = (unsigned long long*)malloc((size - (size/2)) * sizeof(unsigned long long));

    for (unsigned long i = 0; i < size/2; i++)
    {
        first_half[i] = array[i];
    }

    for (unsigned long i = 0; i <size - (size/2); i++)
    {
        second_half[i] = array[i + size/2];
    }

    merge_sort(first_half, size/2);
    merge_sort(second_half, size - (size/2));

    unsigned long i = 0, j = 0;

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
    // n is the number of items in the store
    // q is the number of queries
    // x is the number of items bought
    // y is the number of free items
    // p_i is the price of the i-th item
    unsigned long n, q, x, y; 
    unsigned long long p_i, total;

    // read value of n
    scanf("%lu %lu", &n, &q);

    // allocate dynamic memory for the prices of every item.
    unsigned long long *store_items_prices = (unsigned long long*)malloc(n * sizeof(unsigned long long));

    // fill the array
    for (unsigned long i = 0; i < n; i++)
    {
        scanf("%llu", &p_i);
        store_items_prices[i] = p_i;
    }

    // sort the array
    merge_sort(store_items_prices, n);

    for (unsigned long i = 1; i < n; i++)
    {
        store_items_prices[i] += store_items_prices[i-1];
    }

    for (unsigned long i = 0; i < q; i++)
    {
        scanf("%lu %lu", &x, &y);

        unsigned long first_idx = n-x-1;

        unsigned long final_idx = first_idx+y;

        if (n == x)
        {
            total = store_items_prices[final_idx];
        }
        else
        {
            total = store_items_prices[final_idx] - store_items_prices[first_idx];
        }
        printf("%llu\n", total);
    }

    free(store_items_prices);

    return 0;
}
