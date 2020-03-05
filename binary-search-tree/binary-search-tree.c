#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} node;

void insertion(node **tree, int key);
void delete (node **tree, int key);
bool search(node *tree, int key);
void inorder(node *tree);
void free_tree(node *tree);

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
  inorder(tree);

  delete (&tree, 15);
  printf("\n\n After deletion:\n");
  inorder(tree);
  printf("\n");

  free_tree(tree);
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

void delete (node **tree, int key) {
  if (*tree != NULL) {
    node *current = *tree;
    node *last;
    bool to_left;

    while (current != NULL) {
      // key is lesser than current - go left
      if (key < current->key) {
        last = current;
        current = current->left;
        to_left = true;

        // key is greater than current - go right
      } else if (key > current->key) {
        last = current;
        current = current->right;
        to_left = false;

        // key is equal
      } else {
        // current node has no child
        if (current->left == NULL && current->right == NULL) {
          if (to_left)
            last->left = NULL;
          else
            last->right = NULL;
          free(current);

          // current node has only left child
        } else if (current->left != NULL && current->right == NULL) {
          if (to_left)
            last->left = current->left;
          else
            last->right = current->left;
          free(current);

          // current node has only right child
        } else if (current->left == NULL && current->right != NULL) {
          if (to_left)
            last->left = current->right;
          else
            last->right = current->right;
          free(current);

          // current node has both children
        } else {
          // find the minimum value in the current node right subtree
          node *minor = current->right;
          while (minor && minor->left != NULL)
            minor = minor->left;
          int min_key = minor->key;

          // delete the minor node found
          delete (tree, minor->key);

          // replace current with minor node key
          current->key = min_key;
        }

        break;
      }
    }
  }
}

bool search(node *tree, int key) {
  if (tree != NULL) {
    node *temp = tree;

    while (temp != NULL) {
      if (key == temp->key)
        return true;
      else if (key > temp->key)
        temp = temp->right;
      else
        temp = temp->left;
    }
  }
  return false;
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
