#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct queue {
  int size;
  struct node *head;
  struct node *tail;
} queue;

void enqueue(queue **q, int data);
int dequeue(queue **q);
void free_queue(queue *q);
void print_queue(queue *q);

void push(node **stack, int data);
int pop(node **stack);
void free_stack(node *stack);
void print_stack(node *stack);

void reverse_first_k_elements(queue **q, int k);

void main() {
  queue *q = malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 10;

  for (int i = 10; i <= 100; i += 10)
    enqueue(&q, i);

  printf("Input:\n");
  print_queue(q);

  reverse_first_k_elements(&q, 7);

  printf("\nOutput:\n");
  print_queue(q);

  free_queue(q);
}

void reverse_first_k_elements(queue **q, int k) {
  node *stack = NULL;

  // throw the first k elements in the stack
  for (int i = 0; i < k; i++)
    push(&stack, dequeue(q));

  // replace the elements in the queue, but in the reverse order
  for (int i = 0; i < k; i++)
    enqueue(q, pop(&stack));

  // take the rest of the elements from the front of the queue and place them in the back
  for (int i = 0; i < ((*q)->size - k); i++)
    enqueue(q, dequeue(q));

  free_stack(stack);
}

/* QUEUE FUNCTIONS */

void enqueue(queue **q, int data) {
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

int dequeue(queue **q) {
  if ((*q)->head != NULL) {
    node *temp = (*q)->head;
    (*q)->head = temp->next;
    int data = temp->data;
    free(temp);
    return data;
  }
}

void print_queue(queue *q) {
  node *temp = q->head;
  while (temp != NULL) {
    printf(" data: %d \n", temp->data);
    temp = temp->next;
  }
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
