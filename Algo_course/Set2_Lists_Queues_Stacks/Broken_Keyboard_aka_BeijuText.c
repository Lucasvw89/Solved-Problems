#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
    char content;
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


Node create_independent_node()
{
    Node new_node = (Node)malloc(sizeof(struct node));
    return new_node;
}


void cursor_next(List list)
{
    if (list->cursor->next_node != NULL) {list->cursor = list->cursor->next_node;}
}


void cursor_to_head(List list)
{
    list->cursor = list->header_node;
}


void cursor_to_tail(List list)
{
    list->cursor = list->tail_pointer;
}


void insert(List list, int item)
{
    Node new_node = create_independent_node();

    new_node->previous_node = list->cursor;
    new_node->next_node = list->cursor->next_node;
    list->cursor->next_node = new_node;

    if (new_node->next_node != NULL) {
        new_node->next_node->previous_node = new_node;
    }

    if (new_node->next_node == NULL) {list->tail_pointer = new_node;}

    new_node->content = item;
    list->size++;
}


void display(List list)
{
    Node current = list->header_node;
    int i = 0;
    for (i; i < list->size; i++)
    {
        current = current->next_node;
        printf("%c", current->content);
    }
    printf("\n");
}


int main()
{
    char text[100001];
    List new_text = create_new_list();
    long int size;
    long int i = 0;

    while ((scanf("%s", &text)) != EOF)
    {
        size = strlen(text);

        for(i; i < size; i++)
        {
            if (text[i] == '[')
            {
                cursor_to_head(new_text);
            }
            else if (text[i] == ']')
            {
                cursor_to_tail(new_text);
            }
            else
            {
                insert(new_text, text[i]);
                cursor_next(new_text);
            }
        }
        i = 0;

        display(new_text);

        free(new_text);
        new_text = create_new_list();
    }

    return 0;
}
