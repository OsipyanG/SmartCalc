#include "module_test.h"

START_TEST(test_1) {
  char infix[] = "(sin(30) + cos(45)) * 10 / (ln(2) ^ sqrt(16))";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST

START_TEST(test_2) {
  char infix[] = "5 * (3 + 7) - sqrt(25) ^ 2 + ln(1) / cos(60)";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST
//
START_TEST(test_3) {
  char infix[] = "sin(45) * (cos(30) - 10) + ln(2) / sqrt(16) ^ 3";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST

START_TEST(test_4) {
  char infix[] = "(sin(45) + cos(30)) * atan(1) - ln(2) / (sqrt(16) ^ 3)";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST

START_TEST(test_5) {
  char infix[] = "-(-5.5 + 3.2) * 2.1 - 10.5 mod 4";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST

START_TEST(test_6) {
  char infix[] = "8 .4 * (-sin(30)) + 25 mod 7 - (-sqrt(16))";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST

START_TEST(test_7) {
  char infix[] = "-sqrt(25.5) / (+ln(2.3)) - (-cos(60)) * 3.7";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST

START_TEST(test_8) {
  char infix[] = "-sqrt)-1( + -2";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST

START_TEST(test_9) {
  char infix[] = "sinUSA()";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST
START_TEST(test_10) {
  char infix[] = "sin()";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST
START_TEST(test_11) {
  char infix[] = "sin(sqrt(34))";
  ck_assert_int_eq(is_valid(infix), SUCCESS);
}
END_TEST
START_TEST(test_12) {
  char infix[] = "sin(32) /(sin()^2";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST
START_TEST(test_13) {
  char infix[] = "-sqrt(0)+";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST
START_TEST(test_14) {
  char infix[] = "2mod";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST

START_TEST(test_15) {
  char infix[] = "(2+3+)";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST

START_TEST(test_16) {
  char infix[] = "2+3+ *5";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST

START_TEST(test_17) {
  char infix[] = "sinfaslkdjf()";
  ck_assert_int_eq(is_valid(infix), EXPRESSION_ERROR);
}
END_TEST

Suite *suite_is_valid() {
  Suite *s = suite_create("suite_is_valid");
  TCase *tc = tcase_create("case_module");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  tcase_add_test(tc, test_11);
  tcase_add_test(tc, test_12);
  tcase_add_test(tc, test_13);
  tcase_add_test(tc, test_14);
  tcase_add_test(tc, test_15);
  tcase_add_test(tc, test_16);
  tcase_add_test(tc, test_17);

  suite_add_tcase(s, tc);
  return s;
}
