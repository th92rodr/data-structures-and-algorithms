#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char data;
  struct node *next;
} node;

void push(node **stack, char data);
char pop(node **stack);
void free_stack(node *stack);
void print_stack(node *stack);

void main() {
  node *stack = NULL;
  char data;

  /*
    // Get expression from an user input
    char expression[256];
    printf("Input: ");
    fgets(expression, 256, stdin);
    printf("input %s -- len %d \n\n", expression, strlen(expression));
    */

  char exp[] = "[()]{}{[()()]()}";
  //char exp[] = "[(])";
  //char exp[] = "[()]{}{[()()]()}(";
  printf(" Expression: %s \n", exp);

  for (int i = 0; i < strlen(exp); i++) {
    char input = exp[i];

    if (!isdigit(input)) {
      switch (input) {
        case '(':
        case '[':
        case '{':
          push(&stack, input);
          break;

        case ')':
        case ']':
        case '}':
          data = pop(&stack);
          if (input == ')' && data != '(' || input == ']' && data != '[' || input == '}' && data != '{') {
            printf("Expression is not Balanced!\n");
            free_stack(stack);
            exit(0);
          }
          break;

        default:
          printf("Invalid character!\n");
          free_stack(stack);
          exit(0);
          break;
      }
    }
  }

  if (stack == NULL)
    printf("Expression is Balanced!\n");
  else
    printf("Expression is not Balanced!\n");

  free_stack(stack);
}

void push(node **stack, char data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = *stack;
  *stack = new_node;
}

char pop(node **stack) {
  if (*stack != NULL) {
    node *temp = *stack;
    *stack = temp->next;
    char data = temp->data;
    free(temp);
    return data;
  } else {
    printf("Stack Underflow \n");
    exit(0);
  }
}

void print_stack(node *stack) {
  printf("=====================================\n");
  node *temp = stack;
  while (temp != NULL) {
    printf(" data: %c \n", temp->data);
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
