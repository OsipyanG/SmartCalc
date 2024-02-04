#ifndef TESTS_MODULE_H
#define TESTS_MODULE_H

#include <check.h>

#include "../controller/controller.h"
#include "../model/headers/converter.h"
#include "../model/headers/eval.h"
#include "../model/headers/helpers.h"
#include "string.h"

Suite *suite_converter_test();
Suite *suite_evaluate_test();
Suite *suite_is_valid();

#endif
