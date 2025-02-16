#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cont{
    char string[16];
    int deleted;
};

typedef struct cont Content;


Content* create_new_content(char string[])
{
    Content* new_cont = (Content*)malloc(sizeof(Content));
    for (int i = 0; i < 16; i++)
    {
        new_cont->string[i] = 0;
    }
    strcpy(new_cont->string, string);

    new_cont->deleted = 0;

    return new_cont;
}


struct dict{
    Content* array[101];
    int count;
};

typedef struct dict Dictionary;


Dictionary* create_new_dict()
{
    Dictionary* new_dict = (Dictionary*)malloc(sizeof(Dictionary));
    for (int i = 0; i < 101; i++)
    {
        new_dict->array[i] = NULL;
    }
    new_dict->count = 0;

    return new_dict;
}


int h(char key[])
{
    int result = 0;

    for (int i = 0; i < strlen(key); i++)
    {
        result += (i+1)*key[i];
    }

    result = 19*result;
    return result;
}


int Hash(char key[])
{
    return h(key) % 101;
}


int find_element(Dictionary* dict, char key[])
{
    int idx = Hash(key);
    int new_idx;
    for (int i = 0; i < 20; i++)
    {
        new_idx = (idx + i*i + 23*i) % 101;
        if (dict->array[new_idx] != NULL && strcmp(dict->array[new_idx]->string, key) == 0 && dict->array[new_idx]->deleted == 0) {return new_idx;}
        if (dict->array[new_idx] == NULL) {return -1;}
    }
    return -1;
}


void insert(Dictionary* dict, char key[])
{
    if (find_element(dict, key) != -1) {return;}
    int idx = Hash(key);
    int new_idx;

    for (int i = 0; i < 20; i++)
    {
        new_idx = (idx + i*i + 23*i) % 101;

        if (dict->array[new_idx] == NULL || (dict->array[new_idx] != NULL && dict->array[new_idx]->deleted == 1))
        {
            dict->array[new_idx] = create_new_content(key);
            dict->count++;
            return;
        }
    }
    return;
}


void delete(Dictionary* dict, char key[])
{
    int idx = find_element(dict, key);

    if (idx == -1) {return;}

    dict->array[idx]->deleted = 1;
    dict->count--;
}


void Display(Dictionary* dict)
{
    printf("%d\n", dict->count);
    for (int i = 0; i < 101; i++)
    {
        if (dict->array[i] != NULL && dict->array[i]->deleted != 1)
        {
            printf("%d:%s\n", i, dict->array[i]->string);
        }
    }
}


int main()
{
    char input[20];
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        Dictionary* my_dict = create_new_dict();

        for (int j = 0; j < n; j++)
        {
            scanf("%s", input);
            char * token = strtok(input, ":");

            if (strcmp(token, "ADD") == 0)
            {
                token = strtok(NULL, ":");
                insert(my_dict, token);
            }
            else
            {
                token = strtok(NULL, ":");
                delete(my_dict, token);
            }
        }

        Display(my_dict);

        free(my_dict);

    }

    return 0;
}

