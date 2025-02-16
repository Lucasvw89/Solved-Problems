#include <stdio.h>
#include <stdlib.h>


struct node{
    int key;
    struct node* left;
    struct node* right;
};

typedef struct node BSTNode;


BSTNode* create_bstnode(int key)
{
    BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
    n->key = key;
    n->left = n->right = NULL;
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


BSTNode* inserthelp(BSTNode* rt, int key)
{
    if (rt == NULL)
    {
        return create_bstnode(key);
    }
    if (rt->key > key)
    {
        rt->left = inserthelp(rt->left, key);
    }
    else
    {
        rt->right = inserthelp(rt->right, key);
    }
    return rt;
}


void insert(BST* bst, int key)
{
    bst->root = inserthelp(bst->root, key);
    bst->nodecount++;
}


void preorderhelp(BSTNode* rt)
{
    if (rt != NULL)
    {
        printf("%d ", rt->key);
        preorderhelp(rt->left);
        preorderhelp(rt->right);
    }
}


void inorderhelp(BSTNode* rt)
{
    if (rt != NULL)
    {
        inorderhelp(rt->left);
        printf("%d ", rt->key);
        inorderhelp(rt->right);
    }
}


void posorderhelp(BSTNode* rt)
{
    if (rt != NULL)
    {
        posorderhelp(rt->left);
        posorderhelp(rt->right);
        printf("%d ", rt->key);
    }
}


void preorder(BST* bst)
{
    preorderhelp(bst->root);
}


void inorder(BST* bst)
{
    inorderhelp(bst->root);
}


void posorder(BST* bst)
{
    posorderhelp(bst->root);
}


int main()
{
    int count, input;
    scanf("%d", &count);

    BST* tree = create_bst();

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &input);
        insert(tree, input);
    }

    printf("Pre order : ");
    preorder(tree);
    printf("\n");

    printf("In order  : ");
    inorder(tree);
    printf("\n");

    printf("Post order: ");
    posorder(tree);

    return 0;
}
