#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

typedef struct node {
  int n;
  struct node *next;
} node;

void insert_at_front(node **list, int number);
void insert_at_end(node **list, int number);
void insert_before_node(node **list, int number, int given_node);
void insert_after_node(node **list, int number, int given_node);
void delete_node(node **list, int number);
void delete_at_front(node **list);
int search(node *list, int number);
void add_node_order(node **list, int number);
void print_list(node *list);
void free_list(node *list);
int menu();
int get_number();

void main() {
  node *list = NULL;

  /*
    int op;
    do {
        op = menu();

        switch (op) {
        case 0:
            break;
        case 1:
            print_list(list);
            break;
        case 2:
            add_node_begin(&list, get_number());
            break;
        case 3:
            add_node_end(&list, get_number());
            break;
        case 4:
            add_node_order(&list, get_number());
            break;
        case 5:
            delete_node(&list, get_number());
            break;
        default:
            printf("\nInvalid option\n");
            break;
        }

    } while(op);
    */

  insert_at_front(&list, 20);
  insert_at_front(&list, 10);
  insert_at_end(&list, 30);
  insert_at_end(&list, 40);
  print_list(list);

  delete_node(&list, 20);
  delete_node(&list, 40);
  print_list(list);

  insert_after_node(&list, 40, 30);
  print_list(list);

  insert_after_node(&list, 20, 10);
  print_list(list);

  insert_before_node(&list, 5, 10);
  print_list(list);

  insert_before_node(&list, 25, 30);
  print_list(list);

  delete_at_front(&list);
  print_list(list);

  printf(" search %d \n", search(list, 25));

  free_list(list);
}

int menu() {
  int op;
  printf("\nSelect operation:\n");
  printf("0. Exit\n");
  printf("1. Show list\n");
  printf("2. Add node in the beginning\n");
  printf("3. Add node in the end\n");
  printf("4. Add node in order\n");
  printf("5. Remove node\n");
  printf("Option: ");
  scanf(" %d", &op);
  return op;
}

int get_number() {
  int number;
  printf("Number: ");
  scanf(" %d", &number);
  return number;
}

/* Inserts given element at the start of the linked list */
void insert_at_front(node **list, int number) {
  node *new_node = malloc(sizeof(node));
  new_node->n = number;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    new_node->next = *list;
    *list = new_node;
  }
}

/* Inserts given element at the end of the linked list */
void insert_at_end(node **list, int number) {
  node *new_node = malloc(sizeof(node));
  new_node->n = number;
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

/* Inserts given element before given node that is already in the linked list */
void insert_before_node(node **list, int number, int given_node) {
  node *new_node = malloc(sizeof(node));
  new_node->n = number;
  new_node->next = NULL;

  if (*list != NULL) {
    node *temp = *list;
    node *last;
    bool is_first = true;

    while (temp != NULL) {
      if (temp->n == given_node) {
        if (is_first) {
          new_node->next = temp;
          *list = new_node;

        } else {
          new_node->next = temp;
          last->next = new_node;
        }
        break;

      } else {
        last = temp;
        temp = temp->next;
        is_first = false;
      }
    }
  }
}

/* Inserts given element after given node that is already in the linked list */
void insert_after_node(node **list, int number, int given_node) {
  node *new_node = malloc(sizeof(node));
  new_node->n = number;
  new_node->next = NULL;

  if (*list != NULL) {
    node *temp = *list;

    while (temp != NULL) {
      if (temp->n == given_node) {
        if (temp->next != NULL) {
          new_node->next = temp->next;
        }
        temp->next = new_node;
        break;

      } else {
        temp = temp->next;
      }
    }
  }
}

void add_node_order(node **list, int number) {
  node *new_node = malloc(sizeof(node));
  new_node->n = number;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    node *temp = *list;
    node *last;
    bool is_first = true;

    while (temp != NULL) {
      if (new_node->n < temp->n) {
        if (is_first) {
          // add to the begin
          new_node->next = *list;
          *list = new_node;
        } else {
          last->next = new_node;
          new_node->next = temp;
        }
        break;

      } else {
        if (temp->next == NULL) {
          // add to the end
          temp->next = new_node;
          break;

        } else {
          last = temp;
          temp = temp->next;
        }
        is_first = false;
      }
    }
  }
}

/* Deletes given element from the linked list */
void delete_node(node **list, int number) {
  if (*list != NULL) {
    node *temp = *list;
    node *last;
    bool is_first = true;

    while (temp != NULL) {
      if (temp->n == number) {
        if (is_first) {
          *list = temp->next;
        } else {
          last->next = temp->next;
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

/* Deletes first element of the linked list */
void delete_at_front(node **list) {
  if (*list != NULL) {
    node *temp = *list;
    *list = temp->next;
    free(temp);
  }
}

/* Returns the given element from the linked list */
int search(node *list, int number) {
  if (list != NULL) {
    node *temp = list;
    while (temp != NULL) {
      if (number == temp->n)
        return temp->n;
      temp = temp->next;
    }
  }
  return -1;
}

void print_list(node *list) {
  printf("=====================================\n");
  node *temp = list;
  while (temp != NULL) {
    printf("number: %d \n", temp->n);
    temp = temp->next;
  }
  /*
    for (node *temp = list; temp != NULL; temp = temp->next) {
        printf("number: %d \n", temp->n);
    }
    */
  printf("=====================================\n");
}

void free_list(node *list) {
  while (list != NULL) {
    node *temp = list->next;
    free(list);
    list = temp;
  }
}
