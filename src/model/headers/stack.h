#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
  long double data;
  struct Node *link;
} Node;

typedef struct {
  size_t len;
  Node *top;
} stack_t;

int push(stack_t *stack, long double data);
long double pop(stack_t *stack);

bool is_empty(stack_t *stack);
void free_stack(stack_t *stack);

#endif
