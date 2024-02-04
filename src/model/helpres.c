#include "headers/helpers.h"

bool is_number(char *str) {
  for (size_t i = 0; i < strlen(str); ++i) {
    if (!(is_digit(str[i]))) {
      if (str[i] == '.') continue;
      return false;
    }
  }
  return true;
}

bool is_digit(char c) { return c >= '0' && c <= '9'; }

bool is_opeator(char c) { return strchr("+-*/~^mp", c); }

bool is_function(char c) { return strchr("sctainqlo", c); }

bool is_token(char c) { return strchr("0123456789.+-*/~^mpsctainqlom()x", c); }
