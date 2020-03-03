/**
 * Sort a Stack
 * 
 * 1. Create a temporary stack.
 * 2. While input stack is NOT empty do this:
 *   - Pop an element from input stack, call it data.
 *   - While temporary stack is NOT empty and top of temporary stack is greater
 *      than data, pop from temporary stack and push it to the input stack.
 *   - Push data in temporary stack.
 * 3. The sorted numbers are in temporary stack.
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
void sort_using_array(node **stack);
void sort(node **stack);

void main() {
  node *stack = NULL;

  int array[] = { 34, 3, 31, 98, 92, 23 };
  for (int i = 0; i < 6; i++)
    push(&stack, array[i]);

  printf("Input:\n");
  print_stack(stack);

  sort(&stack);
  //sort_using_array(&stack);

  printf("\nOutput:\n");
  print_stack(stack);

  free_stack(stack);
}

/* sort a stack using only a temporary stack */
void sort(node **stack) {
  node *temp_stack = NULL;

  while (*stack != NULL) {
    int data = pop(stack);

    while (temp_stack != NULL && top(temp_stack) < data) {
      push(stack, pop(&temp_stack));
    }
    push(&temp_stack, data);
  }

  *stack = temp_stack;
}

/* sort a stack using a temporary stack and an array */
void sort_using_array(node **stack) {
  node *temp_stack = NULL;
  node *current = *stack;

  while (current != NULL) {
    current = current->next;
    int data = pop(stack);

    if (temp_stack != NULL) {
      int temp_data = top(temp_stack);
      int popped_data[10];
      int i = 0;

      while (data > temp_data && temp_data > 0) {
        popped_data[i] = pop(&temp_stack);
        temp_data = top(temp_stack);
        i++;
      }
      push(&temp_stack, data);
      for (int j = i - 1; j >= 0; j--) {
        push(&temp_stack, popped_data[j]);
      }

    } else {
      push(&temp_stack, data);
    }
  }

  *stack = temp_stack;
}

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
