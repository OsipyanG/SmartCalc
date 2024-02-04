#include "module_test.h"

#define EPS 1e-6

START_TEST(test_1) {
  char infix[] = "(sin(30) + cos(45)) * 10 / (ln(2) ^ sqrt(16))";
  char postfix[BUFFER * 2] = {0};
  long double res = 52.293034664;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_2) {
  char infix[] = "5 * (3 + 7) - sqrt(25) ^ 2 + ln(1) / cos(60)";
  char postfix[BUFFER * 2] = {0};
  long double res = 25;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_3) {
  char infix[] = "sin(45) * (cos(30) - 10) + ln(2) / sqrt(16) ^ 3";
  char postfix[BUFFER * 2] = {0};
  long double res = -6.447864951;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_4) {
  char infix[] = "(sin(45) + cos(30)) * atan(1) - ln(2) / (sqrt(16) ^ 3)";
  char postfix[BUFFER * 2] = {0};
  long double res = 70.780117899;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_5) {
  char infix[] = "-(-5.5 + 3.2) * 2.1 - 10 mod 4";
  char postfix[BUFFER * 2] = {0};
  long double res = 2.83;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_6) {
  char infix[] = "8.4 * -sin(30) + 25 mod 7 - (-sqrt(16))";
  char postfix[BUFFER * 2] = {0};
  long double res = 3.8;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_7) {
  char infix[] = "-sqrt(25.5) / +ln(2.3) - (-cos(60)) * 3.7";
  char postfix[BUFFER * 2] = {0};
  long double res = -4.212789241;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_8) {
  char infix[] = "acos(0.5) + ln(4)";
  char postfix[BUFFER * 2] = {0};
  long double res = 61.386294361;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(test_9) {
  char infix[] = "tan(5) + asin(0.5) + log(5)";
  char postfix[BUFFER * 2] = {0};
  long double res = 30.786458668;
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_eq_tol(res, test_res, EPS);
}
END_TEST

START_TEST(fail_test_1) {
  char infix[] = "(-sqrt(25.5 / 0) / +ln(2.3) - (-cos(60)) * 3.7)";
  char postfix[BUFFER * 2] = {0};
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_nan(test_res);
}
END_TEST

START_TEST(failt_test_2) {
  char infix[] = "(-sqrt(-1) / +ln(2.3) - (-cos(60)) * 3.7)";
  char postfix[BUFFER * 2] = {0};
  long double test_res;
  get_postfix(infix, postfix);
  test_res = eval_postfix(postfix, 0, false);
  ck_assert_ldouble_nan(test_res);
}
END_TEST
Suite *suite_evaluate_test() {
  Suite *s = suite_create("calculator_module");
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

  tcase_add_test(tc, fail_test_1);
  tcase_add_test(tc, failt_test_2);

  suite_add_tcase(s, tc);
  return s;
}
