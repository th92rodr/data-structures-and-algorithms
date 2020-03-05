/**
 * Evaluation of Postfix Expression
 * 
 * The Postfix notation is used to represent algebraic expressions.
 * The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix.
 * 
 * Following is algorithm for evaluation postfix expressions.
 * - Create a stack to store operands (or values).
 * - Scan the given expression and do following for every scanned element.
 *   - If the element is a number, push it into the stack
 *   - If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
 * - When the expression is ended, the number in the stack is the final answer
 * 
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void push(node **stack, int data);
int pop(node **stack);
void free_stack(node *stack);
void print_stack(node *stack);

void main() {
  node *stack = NULL;

  /*
    // Get expression from an user input
    char expression[256];
    printf("Input: ");
    fgets(expression, 256, stdin);
    printf("input %s -- len %d \n\n", expression, strlen(expression));
    */

  //char exp[] = "231*+9-";
  char exp[] = "92+2/5*7+";
  printf(" Expression: %s \n", exp);

  for (int i = 0; i < strlen(exp); i++) {
    char input = exp[i];
    printf(" input: %c \n", input);

    if (isdigit(input)) {
      printf(" is digit \n");
      push(&stack, atoi(&input));

    } else {
      printf(" isn't digit \n");
      int value1 = pop(&stack);
      int value2 = pop(&stack);

      switch (input) {
        case '+':
          push(&stack, (value2 + value1));
          break;
        case '-':
          push(&stack, (value2 - value1));
          break;
        case '*':
          push(&stack, (value2 * value1));
          break;
        case '/':
          push(&stack, (value2 / value1));
          break;
        default:
          break;
      }
    }
    print_stack(stack);
  }

  int result = pop(&stack);
  printf(" Result: %d \n", result);

  free_stack(stack);
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
  return 0;
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
