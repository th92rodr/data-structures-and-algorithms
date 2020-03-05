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

int findHeight(node *tree);

void main() {
  node *tree = NULL;

  insertion(&tree, 12);
  insertion(&tree, 5);
  insertion(&tree, 15);
  insertion(&tree, 3);
  insertion(&tree, 7);
  insertion(&tree, 9);
  insertion(&tree, 8);
  insertion(&tree, 11);
  insertion(&tree, 1);
  insertion(&tree, 13);
  insertion(&tree, 17);
  insertion(&tree, 19);
  insertion(&tree, 14);
  insertion(&tree, 18);
  insertion(&tree, 20);

  printf(" Tree height: %d\n", findHeight(tree));

  free_tree(tree);
}

int findHeight(node *tree) {
  if (tree == NULL) {
    return 0;
  } else {
    int left = findHeight(tree->left);
    int right = findHeight(tree->right);

    if (left > right)
      return left + 1;
    else
      return right + 1;
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
