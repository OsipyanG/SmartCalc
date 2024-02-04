#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>
#include <string.h>

#define BUFFER 255

enum Errors {
  SUCCESS,
  EXPRESSION_ERROR,
  MALLOC_ERROR,
};

/// Get This function returns the operator's priority
int get_priority(char c);

/// This function returns the associativity of the operator
char get_associativity(char c);

/// This function checks if the character is a digit
bool is_digit(char c);

/// This function checks if the string is a number
bool is_number(char* str);

/// This function checks whether the character is one of the operators
bool is_opeator(char c);

/// This function checks if the symbol is one of the functions
bool is_function(char c);

///  This function checks if the symbol is one of the tokens
bool is_token(char c);

#endif
