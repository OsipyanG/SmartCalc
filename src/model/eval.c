#include "headers/eval.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "headers/stack.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "headers/helpers.h"

long double eval_postfix(char *exp, long double x, bool has_x) {
  long double operand;
  char *token = NULL;
  stack_t stack = {0};
  token = strtok(exp, " ");
  while (token != NULL) {
    //    display(&stack);
    if (is_number(token) || token[0] == 'x') {
      if (token[0] == 'x') {
        push(&stack, x);
      } else {
        operand = strtold(token, NULL);
        push(&stack, operand);
      }
    } else if (is_opeator(token[0])) {
      calculate_operator(token[0], &stack);
    } else if (is_function(token[0])) {
      calculate_function(token[0], &stack, has_x);
    }
    token = strtok(NULL, " ");
  }

  operand = pop(&stack);
  free_stack(&stack);
  return operand;
}

void calculate_operator(char op, stack_t *stack) {
  long double first_number;
  long double second_number;
  long double result;

  if (op == '~') {
    first_number = pop(stack);
    result = -first_number;

  } else if (op == 'p') {
    result = pop(stack);
  } else {
    first_number = pop(stack);
    second_number = pop(stack);

    switch (op) {
      case '+':
        result = first_number + second_number;
        break;
      case '-':
        result = second_number - first_number;
        break;
      case '*':
        result = first_number * second_number;
        break;
      case '/':
        if (first_number == 0) {
          result = NAN;
        } else {
          result = second_number / first_number;
        }
        break;
      case 'm':
        result = fmodl(second_number, first_number);
        break;
      case '^':
        result = powl(second_number, first_number);
        break;
      default:
        result = 0;
    }
  }
  push(stack, result);
}
void calculate_function(char func, stack_t *stack, bool has_x) {
  long double number;
  long double result;
  number = pop(stack);

  switch (func) {
    case 's':
      if (!has_x) number = number * M_PI / 180;
      result = sinl(number);
      break;
    case 'c':
      if (!has_x) number = number * M_PI / 180;
      result = cosl(number);
      break;
    case 't':
      if (!has_x) number = number * M_PI / 180;
      result = tanl(number);
      break;
    case 'a':
      result = acosl(number);
      result = result * 180 / M_PI;
      break;
    case 'i':
      result = asinl(number);
      result = result * 180 / M_PI;
      break;
    case 'n':
      result = atanl(number);
      result = result * 180 / M_PI;
      break;
    case 'q':
      result = sqrtl(number);
      break;
    case 'l':
      result = logl(number);
      break;
    case 'o':
      result = log10l(number);
      break;
    default:
      result = 0;
  }
  push(stack, result);
}
