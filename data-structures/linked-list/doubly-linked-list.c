#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int data;
  struct node *next;
  struct node *previous;
} node;

void insert_at_front(node **list, int data);
void insert_at_end(node **list, int data);
void insert_before_node(node **list, int data, int given_node);
void insert_after_node(node **list, int data, int given_node);
void delete_node(node **list, int data);
void delete_at_front(node **list);
int search(node *list, int data);
void print_list(node *list);
void free_list(node *list);

void main() {
  node *list = NULL;

  insert_at_front(&list, 20);
  insert_at_front(&list, 10);
  insert_at_end(&list, 40);
  print_list(list);

  delete_node(&list, 20);
  print_list(list);

  insert_after_node(&list, 50, 40);
  print_list(list);

  insert_after_node(&list, 20, 10);
  print_list(list);

  insert_before_node(&list, 5, 10);
  print_list(list);

  insert_before_node(&list, 45, 50);
  print_list(list);

  delete_at_front(&list);
  print_list(list);

  printf(" search %d \n", search(list, 50));

  free_list(list);
}

void insert_at_front(node **list, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->previous = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    node *temp = *list;
    new_node->next = temp;
    temp->previous = new_node;
    *list = new_node;
  }
}

void insert_at_end(node **list, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->previous = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    node *temp = *list;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->previous = temp;
  }
}

void insert_before_node(node **list, int data, int given_node) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->previous = NULL;

  if (*list != NULL) {
    node *temp = *list;
    bool is_first = true;

    while (temp != NULL) {
      if (temp->data == given_node) {
        if (is_first) {
          temp->previous = new_node;
          new_node->next = temp;
          *list = new_node;

        } else {
          new_node->next = temp;
          new_node->previous = temp->previous;
          temp->previous->next = new_node;
          temp->previous = new_node;
        }
        break;

      } else {
        temp = temp->next;
        is_first = false;
      }
    }
  }
}

void insert_after_node(node **list, int data, int given_node) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->previous = NULL;

  if (*list != NULL) {
    node *temp = *list;

    while (temp != NULL) {
      if (temp->data == given_node) {
        if (temp->next != NULL) {
          new_node->next = temp->next;
          temp->next->previous = new_node;
        }
        temp->next = new_node;
        new_node->previous = temp;
        break;

      } else {
        temp = temp->next;
      }
    }
  }
}

void delete_node(node **list, int data) {
  if (*list != NULL) {
    node *temp = *list;
    node *last;
    bool is_first = true;

    while (temp != NULL) {
      if (temp->data == data) {
        if (is_first) {
          *list = temp->next;
          temp->next->previous = NULL;
        } else {
          last->next = temp->next;
          temp->next->previous = last;
        }
        free(temp);
        break;

      } else {
        last = temp;
        temp = temp->next;
        is_first = false;
      }
    }
  }
}

void delete_at_front(node **list) {
  if (*list != NULL) {
    node *temp = *list;
    *list = temp->next;
    temp->next->previous = NULL;
    free(temp);
  }
}

int search(node *list, int data) {
  if (list != NULL) {
    node *temp = list;
    while (temp != NULL) {
      if (data == temp->data)
        return temp->data;
      temp = temp->next;
    }
  }
  return -1;
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
