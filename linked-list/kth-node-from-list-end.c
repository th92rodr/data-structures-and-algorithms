#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int data;
  struct node *next;
} node;

void insert_at_end(node **list, int data);
void print_list(node *list);
void free_list(node *list);

int kth_node_from_list_end(node *list, int k);

void main() {
  node *list = NULL;

  for (int i = 0; i < 10; i++)
    insert_at_end(&list, i + 1);
  print_list(list);

  printf(" Node %d \n", kth_node_from_list_end(list, 5));

  free_list(list);
}

int kth_node_from_list_end(node *list, int k) {
  if (list != NULL) {
    node *current = list;
    node *back = list;
    int index = 0;

    while (current != NULL) {
      index++;
      if (index > k)
        back = back->next;

      current = current->next;
    }
    return back->data;
  }
}

void insert_at_end(node **list, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    node *temp = *list;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

void print_list(node *list) {
  printf("=====================================\n");
  node *temp = list;
  while (temp != NULL) {
    printf("number: %d \n", temp->data);
    temp = temp->next;
  }
  printf("=====================================\n");
}

void free_list(node *list) {
  while (list != NULL) {
    node *temp = list->next;
    free(list);
    list = temp;
  }
}
