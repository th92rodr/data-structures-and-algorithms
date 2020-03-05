#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int data;
  bool visited;
  struct node *next;
} node;

void insert_at_end(node **list, int data);
void free_list(node *list);

bool detect_loop(node *list);
void add_loop_on_purpose(node **list, int data);

void main() {
  node *list = NULL;

  for (int i = 1; i < 10; i++)
    insert_at_end(&list, i);
  add_loop_on_purpose(&list, 10);

  if (detect_loop(list))
    printf("There is a loop\n");
  else {
    printf("There isn't a loop\n");
    free_list(list);
  }
}

bool detect_loop(node *list) {
  node *current = list;
  while (current != NULL) {
    if (current->visited)
      return true;

    current->visited = true;
    current = current->next;
  }
  return false;
}

void add_loop_on_purpose(node **list, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->visited = false;
  new_node->next = *list;

  node *temp = *list;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
}

void insert_at_end(node **list, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->visited = false;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    node *current = *list;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void free_list(node *list) {
  while (list != NULL) {
    node *temp = list->next;
    free(list);
    list = temp;
  }
}
