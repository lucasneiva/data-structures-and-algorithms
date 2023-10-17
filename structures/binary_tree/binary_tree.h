#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left, *right, *parent;
} TTreeNode;

typedef struct binaryTree
{
    TTreeNode *root;
    size_t count;
} TBinaryTree;

void initBinaryTree(TBinaryTree *);
int insertNode(TBinaryTree *, int);
int deleteNode(TBinaryTree *, int);
TTreeNode* search(TBinaryTree *, int);
void preOrderTraversal(TTreeNode *);
void inOrderTraversal(TTreeNode *);
void postOrderTraversal(TTreeNode *);
void freeBinaryTree(TTreeNode *);