#include <stdlib.h>
#include <stdbool.h>


typedef struct binaryTree
{
    int data;
    struct binaryTree *left, *right;
} TBinaryTree;

void initBinaryTree(TBinaryTree *, int);
int insertNode(TBinaryTree **, int);
int deleteNode(TBinaryTree *, int);
TBinaryTree* search(TBinaryTree *, int);
TBinaryTree* searchParent(TBinaryTree *, TBinaryTree *);
TBinaryTree* searchMax(TBinaryTree *);
void preOrderTraversal(TBinaryTree *);
void inOrderTraversal(TBinaryTree *);
void postOrderTraversal(TBinaryTree *);
void freeBinaryTree(TBinaryTree *);