#include "binary_tree.h"
#include <stdio.h>
#include <math.h>


int isRightChild(TBinaryTree *parent, TBinaryTree* child)
{
    if (parent->right == child)
        return true;
    else
        return false;
}

int isLeaf(TBinaryTree *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

void printBinaryTree(TBinaryTree *root, int n)
{
    if (root == NULL) return;
    
    for (size_t i = 0; i < n; i++) printf("\t");
    
    printf("%d\n", root->data);

    printBinaryTree(root->left, n+1);
    printBinaryTree(root->right, n+1);
}

void removeLink(TBinaryTree *parent, TBinaryTree *child)
{
    if (isRightChild(parent, child))
        parent->right = NULL;
    else
        parent->left = NULL;    
}

int hasBothChildren(TBinaryTree *node) {
    if (node->left != NULL && node->right != NULL)
        return true;
    else
        return false;
    
}

void initBinaryTree(TBinaryTree *tree, int data) 
{
    tree->left = NULL;
    tree->right = NULL;
    tree->data = data;
}


int insertNode(TBinaryTree **tree, int data) 
{
    if (*tree == NULL)
    {
        *tree = (TBinaryTree *) malloc(sizeof(TBinaryTree));

        if (*tree == NULL)
            return false;
        
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->data = data;

        return true;    
    }

    if (data <= (*tree)->data)
        return insertNode(&(*tree)->left, data);
    else
        return insertNode(&(*tree)->right, data);    
}

int deleteNode(TBinaryTree *tree, int value) 
{
    TBinaryTree *deleteNode, *deleteNodeParent, *maxNodeParent, *maxNode, *deleteNodeChild;

    deleteNode = search(tree, value);
    deleteNodeParent = searchParent(tree, deleteNode);
 
    if (deleteNode == NULL)
        return false;
     
    if (isLeaf(deleteNode))
    {
        if (isRightChild(deleteNodeParent, deleteNode))
            deleteNodeParent->right = NULL;
        else
            deleteNodeParent->left = NULL;

        free(deleteNode);
    }
    else if (hasBothChildren(deleteNode))
    {
        maxNode = searchMax(deleteNode);
        maxNodeParent = searchParent(tree, maxNode);

        maxNode->left = deleteNode->left;
        removeLink(maxNodeParent, maxNode);

        free(deleteNode);
        
        if (isRightChild(deleteNodeParent, deleteNode))
            deleteNodeParent->right = maxNode;
        else
            deleteNodeParent->left = maxNode;
    }
    else
    {
        if (deleteNode->right != NULL)
            deleteNodeChild = deleteNode->right;
        else
            deleteNodeChild = deleteNode->left;
        
        if (isRightChild(deleteNodeParent, deleteNode))
            deleteNodeParent->right = deleteNodeChild;
        else
            deleteNodeParent->left = deleteNodeChild;
        
        free(deleteNode);
    }
        
    
    return 0;
}


TBinaryTree* search(TBinaryTree *tree, int value)
{
    if (tree == NULL)
        return NULL;
    
    if (tree->data == value)
        return tree;
    
    if (value <= tree->data)
        return search(tree->left, value);
    else
        return search(tree->right, value);    
}

TBinaryTree* searchParent(TBinaryTree *tree, TBinaryTree *child)
{
    if (tree == NULL)
        return NULL;
    
    if (tree->left == child)
        return tree;

    if(tree->right == child)
        return tree;

    if (child->data <= tree->data)
        return searchParent(tree->left, child);
    else
        return searchParent(tree->right, child);
}

TBinaryTree* searchMax(TBinaryTree *tree)
{
    if (tree->right == NULL)
        return tree;
    else
        return searchMax(tree->right);
}

void preOrderTraversal(TBinaryTree *tree)
{
    if (tree == NULL)
        return;
    
    printf("%d ", tree->data);

    preOrderTraversal(tree->left);

    preOrderTraversal(tree->right);
}

void inOrderTraversal(TBinaryTree *tree)
{
    if (tree == NULL)
        return;
    
    inOrderTraversal(tree->left);

    printf("%d ", tree->data);

    inOrderTraversal(tree->right);
}

void postOrderTraversal(TBinaryTree *tree) 
{
    if (tree == NULL)
        return;
    
    postOrderTraversal(tree->left);

    postOrderTraversal(tree->right);

    printf("%d ", tree->data);
}

void freeBinaryTree(TBinaryTree *tree)
{
    if (tree == NULL)
        return;
    
    freeBinaryTree(tree->left);

    freeBinaryTree(tree->right);

    free(tree);
}

int findSize(TBinaryTree *tree)
{
    if(tree == NULL)
        return 0;

    return 1 + findSize(tree->left) + findSize(tree->right);
}

int findHeight(TBinaryTree *root)
{
    if (root == NULL)
        return 0;
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int findLevel(TBinaryTree *root, int value)
{
    if (root == NULL || root->data == value)
        return 0;
    
    if (value <= root->data)
        return 1 + findLevel(root->left, value);
    else
        return 1 + findLevel(root->right, value);
}