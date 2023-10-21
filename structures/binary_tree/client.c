#include <stdio.h>
#include "binary_tree.h"

int main() {
  TBinaryTree *root = NULL;

  // Insert nodes
  insertNode(&root, 15);
  insertNode(&root, 10); 
  insertNode(&root, 20);
  insertNode(&root, 8);
  insertNode(&root, 12);
  insertNode(&root, 17);
  insertNode(&root, 25);
  insertNode(&root, 1);

  // Delete Node
  deleteNode(root, 8);
  deleteNode(root, 20);
  deleteNode(root, 12);

  // Traverse tree
  printf("\nPreorder traversal: ");
  preOrderTraversal(root);

  printf("Inorder traversal: ");
  inOrderTraversal(root);
  
  printf("\nPostorder traversal: ");
  postOrderTraversal(root);
  
  // Search for a node
  int value = 10;
  TBinaryTree* node = search(root, value);
  if(node != NULL) {
    printf("\nFound node with key %d", value);  
  } else {
    printf("\nNode not found");
  }

  // Delete tree  
  freeBinaryTree(root);
  
  return 0;
}