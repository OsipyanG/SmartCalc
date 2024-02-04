#include "headers/stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "headers/helpers.h"

int push(stack_t *stack, long double data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    return MALLOC_ERROR;
  }
  new_node->data = data;
  new_node->link = stack->top;
  stack->top = new_node;
  stack->len++;
  return SUCCESS;
}

long double pop(stack_t *stack) {
  Node *temp;
  long double result = 0;
  if (!is_empty(stack)) {
    result = stack->top->data;
    temp = stack->top;
    stack->top = stack->top->link;
    stack->len -= 1;
    free(temp);
  }
  return result;
}

bool is_empty(stack_t *stack) { return stack->len == 0; }

void free_stack(stack_t *stack) {
  while (!is_empty(stack)) {
    pop(stack);
  }
}
