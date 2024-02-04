#include "controller.h"

#include <math.h>
#include <string.h>

int is_valid(char *exp) {
  bool err;
  char exp_copy[255] = {};

  err = is_valid_braces(exp);
  if (err == false) {
    return EXPRESSION_ERROR;
  }
  convert_infix_to_normal_form(exp, exp_copy);
  err = has_valid_chars(exp_copy);
  if (err == false) {
    return EXPRESSION_ERROR;
  }
  err = has_valid_func(exp_copy);
  if (err == false) {
    return EXPRESSION_ERROR;
  }

  err = has_valid_operators(exp_copy);
  if (err == false) {
    return EXPRESSION_ERROR;
  }

  err = has_valid_numbers(exp_copy);
  if (err == false) {
    return EXPRESSION_ERROR;
  }

  return SUCCESS;
}
bool is_valid_braces(char *exp) {
  int help_value = 0;
  size_t len = strlen(exp);

  for (size_t i = 0; i < len; ++i) {
    if (help_value < 0) {
      return false;
    }
    if (exp[i] == '(') {
      help_value++;
    } else if (exp[i] == ')') {
      help_value--;
    }
  }
  if (help_value > 0) {
    return false;
  }
  return true;
}

bool has_valid_chars(char *exp) {
  bool valid;
  size_t len = strlen(exp);

  for (size_t i = 0; i < len; ++i) {
    valid = is_token(exp[i]);
    if (valid == false) {
      return false;
    }
  }
  return true;
}

bool has_valid_func(char *exp) {
  size_t len = strlen(exp);

  for (size_t i = 0; i < len; ++i) {
    if (is_function(exp[i]) && exp[i + 1] != '(') {
      return false;
    } else if (is_function(exp[i]) && exp[i + 1] == '(' && exp[i + 2] == ')') {
      return false;
    }
  }
  return true;
}

bool has_valid_operators(char *exp) {
  size_t len = strlen(exp);
  if (is_opeator(exp[len - 1])) {
    return false;
  }

  for (size_t i = 0; i < len; ++i) {
    if (is_opeator(exp[i]) && (exp[i + 1] == ')' || is_opeator(exp[i + 1]))) {
      return false;
    }
  }
  return true;
}

bool has_valid_numbers(char *exp) {
  size_t len = strlen(exp);

  for (size_t i = 0; i < len; ++i) {
    if (exp[i] == '.' && (!is_digit(exp[i - 1]) || (!is_digit(exp[i + 1])))) {
      return false;
    }
  }

  return true;
}

long double get_result(char *exp, double x, bool has_x) {
  long double res = NAN;
  if (is_valid(exp) == SUCCESS) {
    char postfix[BUFFER * 2] = {0};
    char exp_copy[BUFFER] = {0};

    strcpy(exp_copy, exp);
    get_postfix(exp_copy, postfix);
    res = eval_postfix(postfix, x, has_x);
  }
  return res;
}
