#include <stdbool.h>
#ifndef CONVERTER_H
#define CONVERTER_H

/// This function is a wrapper, converts the infix to a normal form, converts it
/// to a postfix and splits it into tokens
void get_postfix(char infix[], char res[]);

/// This function returns the infix form to normal, for conversion to postfix.
/// It calls the functions convert_function(), delete_spaces() and adding unary
/// operators.
void convert_infix_to_normal_form(char str[], char res[]);

/// This function changes unary operators such as "-" to "~" and "+" to "p"
void add_unary_operators(char str[]);

/// This function removes spaces in the expression
void delete_spaces(char str[], char new_str[]);

/// This function converts function names to the appropriate letters for
/// convenient operation.
/// sin     s
/// cos     c
/// tan     t
/// acos    a
/// asin    i
/// atan    n
/// sqrt    q
/// ln      l
/// log     o
/// mod     m
void convert_functions(char str[]);

/// This function translates from the infix form to the postfix form using
/// Dijkstra's algorithm
void infix_to_postfix(char infix[], char postfix[]);

/// This function splits tokens separated by a space
void devide_tokens(char postfix[], char res[]);
#endif
