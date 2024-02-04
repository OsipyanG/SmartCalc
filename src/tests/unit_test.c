#include "module_test.h"

void run_tests(void);

void run_tests() {
  int count_of_tests = 3;
  Suite *suite = NULL;
  SRunner *sRunner = NULL;
  Suite *suite_array[] = {suite_converter_test(), suite_evaluate_test(),
                          suite_is_valid()};

  for (int i = 0; i < count_of_tests; i++) {
    suite = suite_array[i];
    sRunner = srunner_create(suite);
    srunner_set_fork_status(sRunner, CK_NOFORK);

    srunner_run_all(sRunner, CK_NORMAL);
    srunner_free(sRunner);

    suite = NULL;
    sRunner = NULL;
  }
}

int main() { run_tests(); }
