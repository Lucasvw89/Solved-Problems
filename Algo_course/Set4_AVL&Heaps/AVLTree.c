#include <stdlib.h>
#include <stdio.h>


int MAX(int a, int b)
{
    return (a > b) ? a : b;
}


struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
    int rank;
};

typedef struct node BSTNode;


BSTNode* create_bstnode(int key)
{
    BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 0;
    n->rank = 1;
    return n;
}


struct bst{
    BSTNode* root;
    int nodecount;
};

typedef struct bst BST;


BST* create_bst()
{
    BST* bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}


int h(BSTNode* rt)
{
    if (rt == NULL) {return -1;}
    return rt->height;
}


BSTNode* rightRotate(BSTNode* rt)
{
    BSTNode* l = rt->left;
    BSTNode* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = MAX(h(rt->left), h(rt->right)) + 1;
    l->height = MAX(h(l->left), h(l->right)) + 1;
    rt->rank = rt->rank - l->rank;
    return l;
}


BSTNode* leftRotate(BSTNode* rt)
{
    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = MAX(h(rt->left), h(rt->right)) + 1;
    r->height = MAX(h(r->left), h(r->right)) + 1;
    r->rank += rt->rank;
    return r;
}


int getBalance(BSTNode* rt)
{
    if (rt == NULL) {return 0;}
    return h(rt->left) - h(rt->right);
}


BSTNode* inserthelp(BSTNode* rt, int key)
{
    if (rt == NULL)
    {
        return create_bstnode(key);
    }
    if (rt->key > key)
    {
        rt->rank += 1;
        rt->left = inserthelp(rt->left, key);
    }
    else
    {
        rt->right = inserthelp(rt->right, key);
    }

    rt->height = 1 + MAX(h(rt->left), h(rt->right));

    int balance = getBalance(rt);

    if (balance < -1 && key >= rt->right->key) {return leftRotate(rt);}

    if (balance > 1 && key < rt->left->key) {return rightRotate(rt);}

    if (balance > 1 && key >= rt->left->key)
    {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }

    if (balance < -1 && key < rt->right->key)
    {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}


void insert(BST* bst, int key)
{
    bst->root = inserthelp(bst->root, key);
    bst->nodecount++;
}


int get_idx(BSTNode* rt, int elem)
{
    if (rt != NULL)
    {
        if (elem < rt->key)
        {
            return get_idx(rt->left, elem);
        }
        else if (elem == rt->key)
        {
            return rt->rank;
        }
        else
        {
            return rt->rank + get_idx(rt->right, elem);
        }
    }
    return 0;
}


int find_elem(BSTNode* rt, int elem)
{
    if (elem == rt->key) {return 1;}
    if (elem < rt->key)
    {
        if (rt->left == NULL)
        {
            return -1;
        }
        return find_elem(rt->left, elem);
    }
    else
    {
        if (rt->right == NULL)
        {
            return -1;
        }
        return find_elem(rt->right, elem);
    }
}


int main()
{
    BST* my_bst = create_bst();
    int Q;

    int op;
    int elem;

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &op);
        scanf("%d", &elem);

        if (op == 1)
        {
            insert(my_bst, elem);
        }
        else
        {
            if (find_elem(my_bst->root, elem) == -1)
            {
                printf("Data tidak ada\n");
            }
            else
            {
                printf("%d\n", get_idx(my_bst->root, elem));
            }
        }
    }
    return 0;
}
