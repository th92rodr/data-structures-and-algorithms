/**
 * Hash Table Implementation
 * gcc version 7.4.0
 **/

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#define HASH_SIZE 20

typedef struct node {
  int data;
  struct node *next;
} node;

void init_hash(node *hash[]);
int hash_function(int data);
void insertion(node *hash[], int data);
void deletion(node *hash[], int data);
int search(node *hash[], int data);
void print_hash(node *hash[]);
void free_hash(node *hash[]);

void main() {
  node *hash[HASH_SIZE];
  init_hash(hash);

  insertion(hash, 1);
  insertion(hash, 2);
  insertion(hash, 3);
  insertion(hash, 4);
  insertion(hash, 5);
  insertion(hash, 1);
  insertion(hash, 4);
  print_hash(hash);

  deletion(hash, 2);
  print_hash(hash);

  printf(" search %d \n", search(hash, 3));

  free_hash(hash);
}

void init_hash(node *hash[]) {
  for (int i = 0; i < HASH_SIZE; i++)
    hash[i] = NULL;
}

int hash_function(int data) {
  return data;
}

void insertion(node *hash[], int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (hash[hash_function(data)] == NULL) {
    hash[hash_function(data)] = new_node;
  } else {
    node *current = hash[hash_function(data)];
    while (current->next != NULL)
      current = current->next;
    current->next = new_node;
  }
}

void deletion(node *hash[], int data) {
  if (hash[hash_function(data)] != NULL) {
    node *current = hash[hash_function(data)];
    node *last;
    bool is_first = true;

    while (current != NULL) {
      if (data == current->data) {
        if (is_first)
          hash[hash_function(data)] = current->next;
        else
          last->next = current->next;

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

int search(node *hash[], int data) {
  if (hash[hash_function(data)] != NULL) {
    node *current = hash[hash_function(data)];
    while (current != NULL) {
      if (data == current->data)
        return current->data;
      current = current->next;
    }
  }
  return -1;
}

void print_hash(node *hash[]) {
  printf("=====================================\n");
  for (int i = 0; i < HASH_SIZE; i++) {
    printf("|");
    node *current = hash[i];
    while (current != NULL) {
      printf(" %d ->", current->data);
      current = current->next;
    }
    printf(" NULL\n");
  }
  printf("=====================================\n");
}

void free_hash(node *hash[]) {
  for (int i = 0; i < HASH_SIZE; i++) {
    while (hash[i] != NULL) {
      node *temp = hash[i]->next;
      free(hash[i]);
      hash[i] = temp;
    }
  }
}
