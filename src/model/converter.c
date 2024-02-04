#include "headers/converter.h"

#include "headers/helpers.h"

void reset_part_array(char exp[]);

void get_postfix(char infix[], char res[]) {
  char temp[BUFFER * 2] = {0};
  convert_infix_to_normal_form(infix, res);
  infix_to_postfix(infix, res);
  strcpy(temp, res);
  memset(res, 0, BUFFER * 2);
  reset_part_array(temp);
  devide_tokens(temp, res);
}

int get_priority(char c) {
  if (c == '+' || c == '-')
    return 1;
  else if (c == '/' || c == '*' || c == 'm')
    return 2;
  else if (c == '~' || c == 'p')
    return 3;
  else if (c == '^')
    return 4;
  else if (strchr("sctainqlo", c))
    return 5;
  return -1;
}

char get_associativity(char c) {
  if (c == '^') return 'R';
  return 'L';
}

void infix_to_postfix(char infix[], char postfix[]) {
  int resultIndex = 0;
  unsigned len = strlen(infix);
  char stack[BUFFER * 2] = {0};
  int stackIndex = -1;
  for (size_t i = 0; i < len; i++) {
    char c = infix[i];
    if (c == 'x' || (is_digit(c)) || c == '.') {
      postfix[resultIndex++] = c;
    } else if (c == '(') {
      stack[++stackIndex] = c;
    } else if (c == ')') {
      while (stackIndex >= 0 && stack[stackIndex] != '(') {
        if (postfix[resultIndex - 1] != ' ') postfix[resultIndex++] = ' ';
        postfix[resultIndex++] = stack[stackIndex--];
        postfix[resultIndex++] = ' ';
      }
      stackIndex--;
    } else {
      while (stackIndex >= 0 &&
             (get_priority(infix[i]) < get_priority(stack[stackIndex]) ||
              (get_priority(infix[i]) == get_priority(stack[stackIndex]) &&
               get_associativity(infix[i]) == 'L'))) {
        postfix[resultIndex++] = ' ';
        postfix[resultIndex++] = stack[stackIndex--];
        postfix[resultIndex++] = ' ';
      }
      stack[++stackIndex] = c;
      postfix[resultIndex++] = ' ';
    }
  }
  while (stackIndex >= 0) {
    postfix[resultIndex++] = ' ';
    postfix[resultIndex++] = stack[stackIndex--];
    postfix[resultIndex++] = ' ';
  }
  postfix[resultIndex] = '\0';
}

void convert_infix_to_normal_form(char str[], char res[]) {
  convert_functions(str);
  delete_spaces(str, res);
  add_unary_operators(res);
  strcpy(str, res);
  delete_spaces(str, res);
}

void add_unary_operators(char str[]) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    if ((i == 0 && str[i] == '-') ||
        (str[i] == '-' && (is_opeator(str[i - 1]) || str[i - 1] == '('))) {
      str[i] = '~';
      continue;
    } else if ((i == 0 && str[i] == '+') ||
               (str[i] == '+' &&
                (is_opeator(str[i - 1]) || str[i - 1] == '('))) {
      str[i] = 'p';
      continue;
    }
  }
}

void delete_spaces(char str[], char new_str[]) {
  size_t len = strlen(str);
  size_t new_i = 0;
  for (size_t i = 0; i < len; i++) {
    if (str[i] != ' ') {
      new_str[new_i++] = str[i];
    }
  }
}

void convert_functions(char str[]) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    if (str[i] == 's') {
      if (strncmp(&(str[i]), "sin", 3) == 0) {
        memcpy(&str[i], "s  ", 3);
      } else if (strncmp(&(str[i]), "sqrt", 4) == 0) {
        memcpy(&str[i], "q   ", 4);
      }
    } else if (str[i] == 'a') {
      if (strncmp(&(str[i]), "acos", 4) == 0) {
        memcpy(&str[i], "a   ", 4);
      } else if (strncmp(&(str[i]), "asin", 4) == 0) {
        memcpy(&str[i], "i   ", 4);
      } else if (strncmp(&(str[i]), "atan", 4) == 0) {
        memcpy(&str[i], "n   ", 4);
      }
    } else if (str[i] == 'c') {
      if (strncmp(&(str[i]), "cos", 3) == 0) {
        memcpy(&str[i], "c  ", 3);
      }
    } else if (str[i] == 'l') {
      if (strncmp(&(str[i]), "log", 3) == 0) {
        memcpy(&str[i], "o  ", 3);
      }
      if (strncmp(&(str[i]), "ln", 2) == 0) {
        memcpy(&str[i], "l ", 2);
      }
    } else if (str[i] == 'm') {
      if (strncmp(&(str[i]), "mod", 3) == 0) {
        memcpy(&str[i], "m  ", 3);
      }
    } else if (str[i] == 't') {
      if (strncmp(&(str[i]), "tan", 3) == 0) {
        memcpy(&str[i], "t  ", 3);
      }
    }
  }
}

void devide_tokens(char postfix[], char res[]) {
  int res_index = 0;
  for (size_t i = 0; i < strlen(postfix); ++i) {
    if (postfix[i] != ' ') {
      res[res_index++] = postfix[i];
    } else if (res_index != 0 && i != strlen(postfix) - 1 &&
               postfix[i] == ' ' && res[res_index - 1] != ' ') {
      res[res_index++] = ' ';
    }
  }
  if (res[res_index - 1] == ' ') res[res_index - 1] = '\0';
}

void reset_part_array(char exp[]) {
  size_t len = strlen(exp);

  for (size_t i = len; i < BUFFER * 2; i++) {
    exp[i] = 0;
  }
}
