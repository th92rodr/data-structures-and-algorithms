/**
 * Stack Data Structure
 *
 * Stack is a linear data structure which follows a particular order in which the operations are performed.
 * The order may be LIFO(Last In First Out) or FILO(First In Last Out).
 * 
 * Mainly the following three basic operations are performed in the stack:
 * 
 * - Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
 * - Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
 * - Peek or Top: Returns top element of stack.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void push(node **stack, int data);
int pop(node **stack);
int top(node *stack);
void free_stack(node *stack);
void print_stack(node *stack);

void main() {
  node *stack = NULL;

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  pop(&stack);

  printf(" top: %d \n", top(stack));

  free_stack(stack);
}

/* Inserts an element at the top of the stack */
void push(node **stack, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  new_node->next = *stack;
  *stack = new_node;
}

/* Returns the top element after removing it from the stack */
int pop(node **stack) {
  if (*stack != NULL) {
    node *temp = *stack;
    *stack = temp->next;
    int data = temp->data;
    free(temp);
    return data;
  }
}

/* Returns the top element without removing it from the stack */
int top(node *stack) {
  if (stack != NULL) {
    return stack->data;
  }
  return -1;
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
