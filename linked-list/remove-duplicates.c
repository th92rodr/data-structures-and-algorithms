#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#define HASH_SIZE 20

typedef struct node {
  int data;
  struct node *next;
} node;

void insert_at_end(node **list, int data);
void delete_node(node **list, int data);
void print_list(node *list);
void free_list(node *list);

void insertion(int hash[], int key, int value);
int search(int hash[], int key);
void print_hash(int hash[]);

void remove_duplicates(node **list);

void main() {
  node *list = NULL;

  int array[] = { 10, 12, 11, 11, 12, 11, 10 };

  for (int i = 0; i < 7; i++)
    insert_at_end(&list, array[i]);

  printf("Linked list before removing duplicates:");
  print_list(list);

  remove_duplicates(&list);

  printf("\nLinked list after removing duplicates:");
  print_list(list);

  free_list(list);
}

void remove_duplicates(node **list) {
  int hash[HASH_SIZE];
  for (int i = 0; i < HASH_SIZE; i++)
    hash[i] = 0;

  node *current = *list;
  while (current != NULL) {
    if (search(hash, current->data))
      delete_node(list, current->data);
    else
      insertion(hash, current->data, 1);

    current = current->next;
  }
}

/* LINKED LIST FUNCTIONS */

void insert_at_end(node **list, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    node *current = *list;
    while (current->next != NULL)
      current = current->next;

    current->next = new_node;
  }
}

void delete_node(node **list, int data) {
  if (*list != NULL) {
    node *current = *list;
    node *last;
    bool is_first = true;

    while (current != NULL) {
      if (current->data == data) {
        if (is_first) {
          *list = current->next;
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

void print_list(node *list) {
  printf("\n");
  node *temp = list;
  while (temp != NULL) {
    printf(" %d ->", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void free_list(node *list) {
  while (list != NULL) {
    node *temp = list->next;
    free(list);
    list = temp;
  }
}

/* HASH FUNCTIONS */

void insertion(int hash[], int key, int value) {
  hash[key] = value;
}

int search(int hash[], int key) {
  return hash[key];
}

void print_hash(int hash[]) {
  printf("=====================================\n");
  for (int i = 0; i < HASH_SIZE; i++) {
    printf("| %d \n", hash[i]);
  }
  printf("=====================================\n");
}
