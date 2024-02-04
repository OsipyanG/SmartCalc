#include "module_test.h"

START_TEST(test_1) {
  char infix[] = "(sin(30) + cos(45)) * 10 / (ln(2) ^ sqrt(16))";
  char res[] = "30 s 45 c + 10 * 2 l 16 q ^ /";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

START_TEST(test_2) {
  char infix[] = "5 * (3 + 7) - sqrt(25) ^ 2 + ln(1) / cos(60)";
  char res[] = "5 3 7 + * 25 q 2 ^ - 1 l 60 c / +";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

START_TEST(test_3) {
  char infix[] = "sin(45) * (cos(30) - 10) + ln(2) / sqrt(16) ^ 3";
  char res[] = "45 s 30 c 10 - * 2 l 16 q 3 ^ / +";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

START_TEST(test_4) {
  char infix[] = "(sin(45) + cos(30)) * atan(1) - ln(2) / (sqrt(16) ^ 3)";
  char res[] = "45 s 30 c + 1 n * 2 l 16 q 3 ^ / -";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

START_TEST(test_5) {
  char infix[] = "-(-5.5 + 3.2) * 2.1 - 10.5 mod 4";
  char res[] = "5.5 ~ 3.2 + ~ 2.1 * 10.5 4 m -";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

START_TEST(test_6) {
  char infix[] = "8 .4 * -sin(30) + 25 mod 7 - (-sqrt(16))";
  char res[] = "8.4 30 s ~ * 25 7 m + 16 q ~ -";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

START_TEST(test_7) {
  char infix[] = "-sqrt(25.5) / +ln(2.3) - (-cos(60)) * 3.7";
  char res[] = "25.5 q ~ 2.3 l p / 60 c ~ 3.7 * -";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

START_TEST(test_8) {
  char infix[] = "-sqrt(-1) + -2";
  char res[] = "1 ~ q ~ 2 ~ +";
  char postfix[BUFFER * 2] = {0};
  get_postfix(infix, postfix);
  ck_assert_str_eq(res, postfix);
}
END_TEST

Suite *suite_converter_test() {
  Suite *s = suite_create("converter model");
  TCase *tc = tcase_create("case_module");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);

  suite_add_tcase(s, tc);
  return s;
}
