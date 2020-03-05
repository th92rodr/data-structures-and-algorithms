#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int data;
  struct node *next;
} node;

void insert_at_front(node **list, int number);
void insert_at_end(node **list, int number);
int delete_at_front(node **list);
void print_list(node *list);
void free_list(node *list);

void push(node **stack, int data);
int pop(node **stack);
void free_stack(node *stack);
void print_stack(node *stack);

void reverse_list(node **list);

void main() {
  node *list = NULL;

  for (int i = 10; i <= 100; i += 10)
    insert_at_end(&list, i);

  printf("Input:\n");
  print_list(list);

  reverse_list(&list);

  printf("\nOutput:\n");
  print_list(list);

  free_list(list);
}

void reverse_list(node **list) {
  node *stack = NULL;

  while (*list != NULL)
    push(&stack, delete_at_front(list));

  while (stack != NULL)
    insert_at_end(list, pop(&stack));

  free_stack(stack);
}

/* LINKED LIST FUNCTIONS */

void insert_at_front(node **list, int number) {
  node *new_node = malloc(sizeof(node));
  new_node->data = number;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    new_node->next = *list;
    *list = new_node;
  }
}

void insert_at_end(node **list, int number) {
  node *new_node = malloc(sizeof(node));
  new_node->data = number;
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

int delete_at_front(node **list) {
  if (*list != NULL) {
    node *temp = *list;
    *list = temp->next;
    int data = temp->data;
    free(temp);
    return data;
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

/* STACK FUNCTIONS */

void push(node **stack, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = *stack;
  *stack = new_node;
}

int pop(node **stack) {
  if (*stack != NULL) {
    node *temp = *stack;
    *stack = temp->next;
    int data = temp->data;
    free(temp);
    return data;
  }
}

void print_stack(node *stack) {
  printf("=====================================\n");
  node *temp = stack;
  while (temp != NULL) {
    printf(" data: %d \n", temp->data);
    temp = temp->next;
  }
  printf("=====================================\n");
}

void free_stack(node *stack) {
  while (stack != NULL) {
    node *temp = stack->next;
    free(stack);
    stack = temp;
  }
}
