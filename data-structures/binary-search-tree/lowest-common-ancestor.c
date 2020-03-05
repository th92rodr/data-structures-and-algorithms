#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} node;

void insertion(node **tree, int key);
void inorder(node *tree);
void free_tree(node *tree);

void lowest_common_ancestor(node *tree, int key_a, int key_b);

void main() {
  node *tree = NULL;

  insertion(&tree, 5);
  insertion(&tree, 2);
  insertion(&tree, 3);
  insertion(&tree, 1);
  insertion(&tree, 4);
  insertion(&tree, 7);
  insertion(&tree, 6);
  insertion(&tree, 8);

  /**************
           5
         /   \
        /     \
       2       7
      / \     / \
     1   3   6   8
          \
           4
     **************/

  lowest_common_ancestor(tree, 1, 4);

  free_tree(tree);
}

void lowest_common_ancestor(node *tree, int key_a, int key_b) {
  while (tree != NULL) {
    if (tree->key > key_a && tree->key > key_b)
      tree = tree->left;

    else if (tree->key < key_a && tree->key < key_b)
      tree = tree->right;

    else {
      printf("Lowest Common Ancestor: %d\n", tree->key);
      break;
    }
  }
}

void insertion(node **tree, int key) {
  node *new_node = malloc(sizeof(node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;

  if (*tree == NULL) {
    *tree = new_node;

  } else {
    node *temp = *tree;

    while (temp != NULL) {
      if (key > temp->key) {
        if (temp->right == NULL) {
          temp->right = new_node;
          break;
        } else {
          temp = temp->right;
        }

      } else {
        if (temp->left == NULL) {
          temp->left = new_node;
          break;
        } else {
          temp = temp->left;
        }
      }
    }
  }
}

void inorder(node *tree) {
  if (tree != NULL) {
    inorder(tree->left);
    printf(" %d -", tree->key);
    inorder(tree->right);
  }
}

void free_tree(node *tree) {
  if (tree != NULL) {
    free_tree(tree->right);
    free_tree(tree->left);
    free(tree);
  }
}
