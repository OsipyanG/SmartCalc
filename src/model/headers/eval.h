#ifndef EVAL_H
#define EVAL_H

#include "stack.h"

/// This function considers a postfix expression. It goes through the tokens,
/// puts the numbers on the stack, in the case of operators and functions, it
/// calls calculate_operator() and calculate_function()
long double eval_postfix(char *exp, long double x, bool has_x);

/// This function receives an operator and a stack as input, takes the necessary
/// operands from the stack and performs an operation with them
void calculate_operator(char op, stack_t *stack);

/// This function receives a function and a stack as input, takes the necessary
/// operand from the stack and performs a function with them
void calculate_function(char func, stack_t *stack, bool has_x);

#endif
