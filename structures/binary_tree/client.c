#include <stdio.h>
#include "binary_tree.h"

int main() {
    TBinaryTree tree;

    initBinaryTree(&tree);

    
    insertNode(&tree, 4);
    insertNode(&tree, 6);
    insertNode(&tree, 0);
    insertNode(&tree, 9);
    insertNode(&tree, 8);
    insertNode(&tree, 7);
    insertNode(&tree, 5);
    insertNode(&tree, 2);
    insertNode(&tree, 3);
    insertNode(&tree, 1);
    
    
    printf("Pre order traversal: ");
    preOrderTraversal(tree.root);
    printf("\n");
    
    printf("In order traversal: ");
    inOrderTraversal(tree.root);
    printf("\n");

    printf("Post order traversal: ");
    postOrderTraversal(tree.root);
    printf("\n");

    freeBinaryTree(tree.root);
}