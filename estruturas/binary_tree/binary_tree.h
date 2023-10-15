#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left, *right;
} TTreeNode;

typedef struct binaryTree
{
    TTreeNode *root;
    size_t count;
} TBinaryTree;

