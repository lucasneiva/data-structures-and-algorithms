#include "binary_tree.h"
#include <stdio.h>

int isRightChild(TTreeNode *node) {
    if (node->parent->right == node)
        return true;
    else
        return false;
}

void initBinaryTree(TBinaryTree *tree) {
    tree->count = 0;
    tree->root = NULL;
}


int insertNode(TBinaryTree *tree, int data) {
    TTreeNode *newNode, *aux;
    newNode = malloc(sizeof(TTreeNode));

    if (newNode == NULL)
        return false;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (tree->root == NULL)
    {
        tree->root = newNode;
        return true;
    }
    
    aux = tree->root;  

    while (true) {
        if (newNode->data > aux->data) {
            if (aux->right == NULL) {
                aux->right = newNode;
                newNode->parent = aux;
                break;
            }
            else
                aux = aux->right;
            
        }
        else {
            if (aux->left == NULL) {
                aux->left = newNode;
                newNode->parent = aux;
                break;
            }
            else
                aux = aux->left;
        }
    }

    return true;
}

int deleteNode(TBinaryTree *tree, int value) {
    TTreeNode *toDelete, *parent, *aux;


    toDelete = search(tree, value);

    if(toDelete == NULL)
        return false;
    
    parent = toDelete->parent;

    if (toDelete->left == NULL && toDelete->right == NULL)
    {
        if (isRightChild(toDelete))
            parent->right = NULL;
        else
            parent->left = NULL;

    }
    else if(toDelete->left != NULL && toDelete->right != NULL)
    {
        aux = toDelete->left;

        while (aux->right != NULL)
            aux = aux->right;

        if (aux != toDelete)
            aux->parent->right = NULL;
        else
            aux->parent->left = NULL;

        if (isRightChild(toDelete))
            parent->right = aux;
        else
            parent->left = aux;
        
        aux->parent = parent;
    }
    else
    {
        if (toDelete->left != NULL)
        {
            if (parent->left == toDelete)
                parent->left = toDelete->left;
            else
                parent->right = toDelete->right;
                     
        }
        else
        {
            if (parent->right == toDelete)
                parent->right = toDelete->right;
            else
                parent->left = toDelete->left;
                
        }
    }
    
    free(toDelete);
}

TTreeNode* search(TBinaryTree *tree, int value) {
    TTreeNode *aux;

    aux = tree->root;

    while (aux != NULL)
    {
        if (aux->data == value)
            return aux;
        else
            if (value > aux->data)
                aux = aux->right;
            else
                aux = aux->left;
    }
    
    return NULL;
}

void preOrderTraversal(TTreeNode *root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data);

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}

void inOrderTraversal(TTreeNode *root) {
    if (root == NULL)
        return;
    
    inOrderTraversal(root->left);

    printf("%d ", root->data);

    inOrderTraversal(root->right);
}

void postOrderTraversal(TTreeNode *root) {
    if (root == NULL)
        return;
    
    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    printf("%d ", root->data);
}

void freeBinaryTree(TTreeNode *root) {
    if (root == NULL)
        return;
    
    freeBinaryTree(root->left);

    freeBinaryTree(root->right);

    free(root);
}