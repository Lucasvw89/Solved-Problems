#include <stdio.h>
#include <stdlib.h>


struct node
{
    int content;
    struct node* next_node;
    struct node* previous_node;
};

typedef struct node* Node;


struct list
{
    Node header_node;
    Node tail_pointer;
    Node cursor;
    int size;
};

typedef struct list* List;


Node create_new_list_head()
{
    Node new_head = (Node)malloc(sizeof(struct node));
    new_head->next_node = NULL;
    new_head->previous_node = NULL;
    new_head->content = 0;

    return new_head;
}


List create_new_list()
{
    List new_list = (List)malloc(sizeof(struct list));
    new_list->header_node = create_new_list_head();
    new_list->tail_pointer = new_list->cursor = new_list->header_node;
    new_list->size = 0;

    return new_list;
}


void create_new_node(List list)
{
    list->tail_pointer->next_node = (Node)malloc(sizeof(struct node));
    list->tail_pointer->next_node->previous_node = list->tail_pointer;
    list->tail_pointer = list->tail_pointer->next_node;
    list->tail_pointer->content = 0;
    list->size++;
}


void push(List list, int item)
{
    create_new_node(list);
    list->tail_pointer->content = item;
}


void pop_top(List list)
{
    Node to_be_freed = list->tail_pointer;
    list->tail_pointer = list->tail_pointer->previous_node;
    free(to_be_freed);
    list->size--;
}


int main()
{
    int N, run, i;
    int possivel;
    int * array;
    List train = create_new_list();
    while(1)
    {
        scanf("%d", &N);
        if (N == 0) {return 0;}
        else {run = 1;}

        while (run)
        {

            int * array = (int*) malloc(N * sizeof(int));

            int teste;
            scanf("%d", &teste);
            if (teste == 0)
            {
                run = 0;
                printf("\n");
            }
            else
            {
                array[0] = teste;
                for (i = 1; i < N; i++)
                    scanf("%d", &array[i]);

                int next_troley = 1;
                int array_idx = 0;
                int possivel = 1;

                while (next_troley <= N || array[array_idx] == train->tail_pointer->content)
                {
                    if (array_idx >= N) {break;}
                    if (array[array_idx] == train->tail_pointer->content)
                    {
                        pop_top(train);
                        array_idx++;
                    }
                    else
                    {
                        push(train, next_troley);
                        next_troley++;
                    }
                }
                if (train->tail_pointer == train->header_node)
                    possivel = 1;
                else
                    possivel = 0;

                if (possivel)
                    printf("Yes\n");
                else
                    printf("No\n");

                while (train->size != 0)
                    pop_top(train);
            }
        }
        free(array);
    }

    return 0;
}
