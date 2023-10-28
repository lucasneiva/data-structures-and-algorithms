#include <stdio.h>
#include "binary_tree.h"

int main()
{
  TBinaryTree *root = NULL;
  
  // Insert nodes
  insertNode(&root, 30);
  insertNode(&root, 20); 
  insertNode(&root, 40);
  insertNode(&root, 25);
  insertNode(&root, 35);
  insertNode(&root, 45);

  // Delete Node
  // deleteNode(root, 8);
  // deleteNode(root, 20);
  // deleteNode(root, 12);
  /*
  // Find size
  printf("\nSize: %d", findSize(root));

  // Find height
  printf("\nHeight: %d", findHeight(root));

  
  // Find level
  int data = 1;
  printf("\nLevel of %d: %d", data, findLevel(root, data));
  */

  // Traverse tree
  //printf("\nPreorder traversal: ");
  preOrderTraversal(root);
  printf("\n");
  inOrderTraversal(root);
  printf("\n");
  postOrderTraversal(root);
  printf("\n");

  /*
  printf("\nInorder traversal: ");
  inOrderTraversal(root);

  printf("\nPostorder traversal: ");
  postOrderTraversal(root);

  // Search for a node
  int value = 10;
  TBinaryTree* node = search(root, value);
  if(node != NULL) {
    printf("\nFound node with key %d\n\n", value);  
  } else {
    printf("\nNode not found\n\n");
  }

  printf("\n\n");
  printBinaryTree(root, 0);
  */
  // Delete tree  
  freeBinaryTree(root);

  return 0;
}