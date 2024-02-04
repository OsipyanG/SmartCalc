#ifndef CONTROLLER_H
#define CONTROLLER_H

// #define NAN (long double)(0.0 / 0.0)

#include "../model/headers/converter.h"
#include "../model/headers/eval.h"
#include "../model/headers/helpers.h"

/// TODO add Doc
int is_valid(char *exp);
long double get_result(char *exp, double x, bool has_x);
bool is_valid_braces(char *exp);
bool has_valid_chars(char *exp);
bool has_valid_func(char *exp);
bool has_valid_operators(char *exp);
bool has_valid_numbers(char *exp);

#endif
