#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node;

typedef struct queue {
  struct node *head;
  struct node *tail;
} queue;

void enqueue(queue **q, char *data);
char *dequeue(queue **q);
void free_queue(queue *q);
void print_queue(queue *q);

void main() {
  queue *q = malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;

  int numbers = 10;

  enqueue(&q, "1");

  for (int i = 0; i < numbers; i++) {
    char *data = dequeue(&q);
    printf(" %s \n", data);

    char *val1 = malloc(strlen(data) + strlen("0") + 1);
    strcpy(val1, data);
    strcat(val1, "0");

    char *val2 = malloc(strlen(data) + strlen("1") + 1);
    strcpy(val2, data);
    strcat(val2, "1");

    enqueue(&q, val1);
    enqueue(&q, val2);
  }

  free_queue(q);
}

void enqueue(queue **q, char *data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if ((*q)->head == NULL) {
    (*q)->tail = new_node;
    (*q)->head = new_node;
  } else {
    (*q)->tail->next = new_node;
    (*q)->tail = new_node;
  }
}

char *dequeue(queue **q) {
  if ((*q)->head != NULL) {
    node *temp = (*q)->head;
    (*q)->head = temp->next;
    char *number = temp->data;
    free(temp);
    return number;
  }
  return NULL;
}

void print_queue(queue *q) {
  printf("=====================================\n");
  node *temp = q->head;
  while (temp != NULL) {
    printf(" data: %s \n", temp->data);
    temp = temp->next;
  }
  printf("=====================================\n");
}

void free_queue(queue *q) {
  node *temp = q->head;
  node *next;
  while (temp != NULL) {
    next = temp->next;
    free(temp);
    temp = next;
  }
  free(q);
}
