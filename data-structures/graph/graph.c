/********************
 *  _________      ____      ____
 * |root node| -> |node| -> |node| -> NULL
 *  _________      ____      ____
 * |root node| -> |node| -> |node| -> NULL
 * 
 ********************/

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct root_node {
  int data;
  struct node *root;
  struct root_node *next;
} root_node;

void add_edge(root_node **graph, int source, int dest);
void insert_root_node(root_node **graph);
void insert_node(node **root_node, int data);
void delete_root_node(root_node **graph, int data);
void delete_all_nodes_from_root(node **root_node);
void delete_edge(root_node **graph, int source, int dest);
void delete_node(node **root_node, int data);
void print_graph(root_node *graph);
void free_graph(root_node *graph);

void main() {
  root_node *graph = NULL;

  add_edge(&graph, 1, 2);
  add_edge(&graph, 2, 4);
  add_edge(&graph, 1, 5);
  add_edge(&graph, 2, 5);
  add_edge(&graph, 3, 1);
  add_edge(&graph, 4, 3);
  add_edge(&graph, 4, 1);
  print_graph(graph);

  delete_root_node(&graph, 2);
  print_graph(graph);

  delete_edge(&graph, 1, 2);
  delete_edge(&graph, 4, 1);
  print_graph(graph);

  free_graph(graph);
}

void add_edge(root_node **graph, int source, int dest) {
  printf(" src %d | dest %d \n", source, dest);

  if (*graph == NULL) {
    root_node *new_root_node = malloc(sizeof(root_node));
    new_root_node->data = source;
    new_root_node->root = NULL;
    new_root_node->next = NULL;

    *graph = new_root_node;
    insert_node(&new_root_node->root, dest);

  } else {
    root_node *current = *graph;
    root_node *last;
    bool node_exists = false;

    while (current != NULL) {
      printf(" %d | ", current->data);
      if (current->data == source) {
        printf(" --- already exists\n");
        node_exists = true;
        insert_node(&current->root, dest);
        break;
      }
      last = current;
      current = current->next;
    }
    if (!node_exists) {
      printf(" --- don't exists\n");
      root_node *new_root_node = malloc(sizeof(root_node));
      new_root_node->data = source;
      new_root_node->root = NULL;
      new_root_node->next = NULL;

      last->next = new_root_node;
      insert_node(&new_root_node->root, dest);
    }
  }
}

void insert_node(node **root_node, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (*root_node == NULL) {
    *root_node = new_node;
  } else {
    node *current = *root_node;
    while (current->next != NULL)
      current = current->next;

    current->next = new_node;
  }
}

void delete_root_node(root_node **graph, int data) {
  if (*graph != NULL) {
    root_node *current = *graph;
    root_node *last;
    bool is_first = true;

    while (current != NULL) {
      if (current->data == data) {
        if (is_first) {
          *graph = current->next;
        } else {
          last->next = current->next;
        }
        delete_all_nodes_from_root(&current->root);
        free(current);
        break;

      } else {
        last = current;
        current = current->next;
        is_first = false;
      }
    }
  }
}

void delete_all_nodes_from_root(node **root_node) {
  node *current = *root_node;
  node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}

void delete_edge(root_node **graph, int source, int dest) {
  root_node *current = *graph;
  while (current != NULL) {
    if (source == current->data) {
      delete_node(&current->root, dest);
      break;
    }
    current = current->next;
  }
}

void delete_node(node **root_node, int data) {
  if (*root_node != NULL) {
    node *current = *root_node;
    node *last;
    bool is_first = true;

    while (current != NULL) {
      if (current->data == data) {
        if (is_first) {
          *root_node = current->next;
        } else {
          last->next = current->next;
        }
        free(current);
        break;

      } else {
        last = current;
        current = current->next;
        is_first = false;
      }
    }
  }
}

void print_graph(root_node *graph) {
  printf("=====================================\n");
  root_node *current_root = graph;
  while (current_root != NULL) {
    printf("| %d | ->", current_root->data);
    node *current_node = current_root->root;
    while (current_node != NULL) {
      printf(" %d ->", current_node->data);
      current_node = current_node->next;
    }
    current_root = current_root->next;
    printf(" NULL\n");
  }
  printf("=====================================\n");
}

void free_graph(root_node *graph) {
  root_node *current_root = graph;
  root_node *next_root;
  while (current_root != NULL) {
    node *current_node = current_root->root;
    node *next_node;
    while (current_node != NULL) {
      next_node = current_node->next;
      free(current_node);
      current_node = next_node;
    }

    next_root = current_root->next;
    free(current_root);
    current_root = next_root;
  }
}
