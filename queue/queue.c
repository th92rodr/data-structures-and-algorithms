/**
 * Queue Data Structure
 * 
 * Queue is a linear structure which follows a particular order in which the operations are performed.
 * The order is First In First Out (FIFO).  A good example of queue is any queue of consumers for a resource where the consumer that came first is served first.
 * The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.
 * 
 * Operations on Queue
 * Mainly the following four basic operations are performed on queue:
 * 
 * - Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition.
 * - Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition.
 * - Front: Get the front item from queue.
 * - Rear: Get the last item from queue.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct queue {
  struct node *head;
  struct node *tail;
} queue;

void enqueue(queue **q, int data);
void dequeue(queue **q);
int front(queue *q);
int rear(queue *q);
void free_queue(queue *q);
void print_queue(queue *q);

void main() {
  queue *q = malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);

  dequeue(&q);

  printf(" head: %d | tail: %d \n", front(q), rear(q));

  free_queue(q);
}

/* Inserts element to the end of the queue */
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

/* Removes an element from the start of the queue */
void dequeue(queue **q) {
  if ((*q)->head != NULL) {
    node *temp = (*q)->head;
    (*q)->head = temp->next;
    free(temp);
  }
}

int front(queue *q) {
  if (q->head != NULL) {
    return q->head->data;
  }
  return -1;
}

int rear(queue *q) {
  if (q->tail != NULL) {
    return q->tail->data;
  }
  return -1;
}

void print_queue(queue *q) {
  printf("=====================================\n");
  node *temp = q->head;
  while (temp != NULL) {
    printf(" data: %d \n", temp->data);
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
