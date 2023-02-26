#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_math.h"

START_TEST(s21_abs_test) {
  ck_assert_int_eq(abs(2147483647), s21_abs(2147483647));
  ck_assert_int_eq(abs(-2147483647 - 1), s21_abs(-2147483647 - 1));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(-0), s21_abs(-0));
  ck_assert_int_eq(abs(+0), s21_abs(+0));
  ck_assert_int_eq(s21_abs((int)S21_NAN), abs((int)S21_NAN));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_ldouble_eq_tol(acos(1), s21_acos(1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(-1.0), s21_acos(-1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(0), s21_acos(0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(0.5), s21_acos(0.5), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(-0.5), s21_acos(-0.5), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(-0.25), s21_acos(-0.25), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(-0.01), s21_acos(-0.01), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_acos(11));
  ck_assert_ldouble_eq_tol(acos(-0.99), s21_acos(-0.99), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(0.7071067811865475),
                           s21_acos(0.7071067811865475), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(acos(-0.7071067811865475),
                           s21_acos(-0.7071067811865475), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_acos(11));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(acos(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(acos(S21_NAN));
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_ldouble_eq_tol(asin(1), s21_asin(1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(-1.0), s21_asin(-1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(0.8), s21_asin(0.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(-0.99), s21_asin(-0.99), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(0), s21_asin(0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(0.5), s21_asin(0.5), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(-0.5), s21_asin(-0.5), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(-0.25), s21_asin(-0.25), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(-0.01), s21_asin(-0.01), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(asin(1 / sqrt(2)), s21_asin(1 / sqrt(2)),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_asin(-1 / sqrt(2)), s21_asin(-1 / sqrt(2)),
                           S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_asin(11));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(asin(S21_NAN));
}
END_TEST

START_TEST(s21_atan_test) {
  ck_assert_ldouble_eq_tol(atan(1), s21_atan(1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-1.0), s21_atan(-1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(1.0005), s21_atan(1.0005), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-1.0005), s21_atan(-1.0005), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(1.05), s21_atan(1.05), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-1.05), s21_atan(-1.05), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(1.1), s21_atan(1.1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-1.1), s21_atan(-1.1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(0), s21_atan(0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-0), s21_atan(-0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(0.5), s21_atan(0.5), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-0.5), s21_atan(-0.5), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-0.25), s21_atan(-0.25), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-0.01), s21_atan(-0.01), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-0.99), s21_atan(-0.99), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-10), s21_atan(-10), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-15), s21_atan(-15), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-25), s21_atan(-25), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), s21_atan(-INFINITY), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(S21_DBL_MAX), atan(S21_DBL_MAX),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_DBL_MAX), atan(-S21_DBL_MAX),
                           S21_EPS_TEST);
  double testcases[] = {-1e20,       -7.4143526437e3,
                        -3144.51e-4, 0.,
                        1e-10,       1e-4,
                        4.2356e-2,   0.43,
                        0.5,         0.999999,
                        1.,          1.0000001,
                        1.001,       1.008888,
                        1.01,        1.1,
                        1.5,         100.,
                        9.123123e6,  1e4,
                        1e10};
  size_t n = sizeof(testcases) / sizeof(testcases[0]);
  for (size_t i = 0; i < n; ++i) {
    ck_assert_ldouble_eq_tol(s21_atan(testcases[i]), atan(testcases[i]),
                             S21_EPS_TEST);
  }
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atan(S21_NAN));
}
END_TEST

START_TEST(s21_ceil_test) {
  ck_assert_ldouble_eq_tol(ceil(0.0), s21_ceil(0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(+0.0), s21_ceil(+0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(-0.0), s21_ceil(-0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(0), s21_ceil(0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(+0), s21_ceil(+0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(-0), s21_ceil(-0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(1.8), s21_ceil(1.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(0.8), s21_ceil(0.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(-1.0), s21_ceil(-1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(-1.8), s21_ceil(-1.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(-0.8), s21_ceil(-0.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(-21.21), s21_ceil(-21.21), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(ceil(S21_DBL_MAX), s21_ceil(S21_DBL_MAX),
                           S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  char buff[100];
  char buff1[100];
  sprintf(buff, "%Lf", s21_ceil(INFINITY));
  sprintf(buff1, "%lf", ceil(INFINITY));
  ck_assert_str_eq(buff, buff1);
  sprintf(buff, "%Lf", s21_ceil(-INFINITY));
  sprintf(buff1, "%lf", ceil(-INFINITY));
  ck_assert_str_eq(buff, buff1);
}
END_TEST

START_TEST(s21_cos_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -0.0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = +0.0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = +0.0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = 12325435.5464654;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -12325435.5464654;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = 12325435462.5464654;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -12325435462.5464654;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = 1e+10;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -1e+10;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = 0.0001;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -0.0001;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = 1.01;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -1.01;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = S21_PI;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = S21_PI / 2;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -S21_PI;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = S21_PI * 2;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  x = -S21_PI * 2;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_eq_tol(cos(DBL_MIN), s21_cos(DBL_MIN), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(cos(DBL_MAX), s21_cos(DBL_MAX), S21_EPS_TEST);
}
END_TEST

START_TEST(s21_exp_test) {
  ck_assert_ldouble_eq_tol(exp(1), s21_exp(1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(-0), s21_exp(-0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(0.0), s21_exp(0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(-0.0), s21_exp(-0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(000000), s21_exp(000000), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(0.1), s21_exp(0.1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(25), s21_exp(25), 1);
  ck_assert_ldouble_eq_tol(exp(-1), s21_exp(-1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(-800), s21_exp(-800), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(-10000), s21_exp(-10000), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(32), s21_exp(32), 1);
  ck_assert_ldouble_eq_tol(exp(-0.1), s21_exp(-0.1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(exp(-37), s21_exp(-37), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
}
END_TEST

START_TEST(s21_fabs_test) {
  double a = S21_INF;
  ck_assert_ldouble_infinite(s21_fabs(a));
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
  ck_assert_ldouble_infinite(s21_fabs(a));
  ck_assert_ldouble_eq_tol(fabs(-10000.9), s21_fabs(-10000.9), S21_EPS_TEST);
  ck_assert_ldouble_eq(s21_fabs(-21.000345), fabs(-21.000345));
  ck_assert_ldouble_eq(s21_fabs(2147483600.4857), fabs(2147483600.4857));
  ck_assert_ldouble_eq_tol(fabs(10000.9), s21_fabs(10000.9), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(fabs(0.0), s21_fabs(0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(fabs(-0.0), s21_fabs(-0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_ldouble_eq_tol(floor(1.0), s21_floor(1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(floor(0.0), s21_floor(0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(floor(1.8), s21_floor(1.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(floor(0.8), s21_floor(0.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(floor(-1.0), s21_floor(-1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(floor(-1.8), s21_floor(-1.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(floor(-0.8), s21_floor(-0.8), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(floor(-21.21), s21_floor(-21.21), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_eq_tol(floor(S21_DBL_MAX), s21_floor(S21_DBL_MAX),
                           S21_EPS_TEST);
  char buff[100];
  char buff1[100];
  sprintf(buff, "%Lf", s21_floor(INFINITY));
  sprintf(buff1, "%lf", floor(INFINITY));
  ck_assert_str_eq(buff, buff1);
  sprintf(buff, "%Lf", s21_floor(-INFINITY));
  sprintf(buff1, "%lf", floor(-INFINITY));
  ck_assert_str_eq(buff, buff1);
}
END_TEST

START_TEST(s21_fmod_test) {
  ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
  ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
  ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));
  ck_assert_ldouble_eq(s21_fmod(3, 21.21), fmod(3, 21.21));
  ck_assert_ldouble_eq(s21_fmod(3, -21.21), fmod(3, -21.21));
  ck_assert_ldouble_eq(s21_fmod(-9, -100500), fmod(-9, -100500));
  ck_assert_ldouble_eq(s21_fmod(-9, -9), fmod(-9, -9));
  ck_assert_ldouble_eq(s21_fmod(1e+10, 9), fmod(1e+10, 9));
  ck_assert_ldouble_eq(s21_fmod(1e+15, 9), fmod(1e+15, 9));
  ck_assert_ldouble_eq(s21_fmod(9821.123, INFINITY), fmod(9821.123, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(2.45, 0));
  ck_assert_ldouble_nan(fmod(2.45, 0));
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(fmod(0, 0));
  ck_assert_ldouble_eq(s21_fmod(+0, 9), fmod(+0, 9));
  ck_assert_ldouble_eq(s21_fmod(-0, 9), fmod(-0, 9));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, 0));
  ck_assert_ldouble_nan(fmod(INFINITY, 0));
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(0.1), s21_log(0.1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(0.00001), s21_log(0.00001), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(S21_EPS_TEST), s21_log(S21_EPS_TEST),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(0.4), s21_log(0.4), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(100), s21_log(100), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(100000), s21_log(100000), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(1e100), s21_log(1e100), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(log(0.001), s21_log(0.001), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(-0));
  ck_assert_ldouble_infinite(s21_log(+0.0));
  ck_assert_ldouble_infinite(s21_log(-0.0));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  char buff[100];
  char buff1[100];
  sprintf(buff, "%Lf", s21_log(0));
  sprintf(buff1, "%lf", log(0));
  ck_assert_str_eq(buff, buff1);
}
END_TEST

START_TEST(s21_pow_test) {
  double base = 4, exp = 0.5;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_TEST);
  base = 0.0;
  exp = 100.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_TEST);
  base = 0.0;
  exp = 0.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_TEST);
  base = -1;
  exp = 10.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_TEST);
  base = -1;
  exp = 10.1;
  ck_assert_ldouble_nan(s21_pow(base, exp));
  base = -1;
  exp = 10.2;
  ck_assert_ldouble_nan(s21_pow(base, exp));
  base = -1;
  exp = 1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-2);
  base = -16.161435;
  exp = 9.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-2);

  ck_assert_ldouble_eq_tol(pow(S21_INF, -S21_INF), s21_pow(S21_INF, -S21_INF),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(S21_INF, -122), s21_pow(S21_INF, -122),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(S21_INF, -1), s21_pow(S21_INF, -1),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq(pow(S21_INF, S21_INF), s21_pow(S21_INF, S21_INF));
  ck_assert_ldouble_eq(pow(S21_INF, 122), s21_pow(S21_INF, 122));
  ck_assert_ldouble_eq(pow(S21_INF, 1), s21_pow(S21_INF, 1));
  ck_assert_ldouble_eq_tol(pow(S21_INF, -0), s21_pow(S21_INF, -0),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(S21_INF, 0), s21_pow(S21_INF, 0), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_INF, -S21_NAN));
  ck_assert_ldouble_nan(pow(S21_INF, S21_NAN));
  ck_assert_ldouble_nan(pow(S21_INF, -S21_NAN));

  ck_assert_ldouble_eq_tol(pow(-S21_INF, -S21_INF), s21_pow(-S21_INF, -S21_INF),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-S21_INF, -122), s21_pow(-S21_INF, -122),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-S21_INF, -1), s21_pow(-S21_INF, -1),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq(pow(-S21_INF, S21_INF), s21_pow(-S21_INF, S21_INF));
  ck_assert_ldouble_eq(pow(-S21_INF, 122), s21_pow(-S21_INF, 122));
  ck_assert_ldouble_eq(pow(-S21_INF, 1), s21_pow(-S21_INF, 1));
  ck_assert_ldouble_eq_tol(pow(-S21_INF, -0), s21_pow(-S21_INF, -0),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-S21_INF, 0), s21_pow(-S21_INF, 0),
                           S21_EPS_TEST);
  ck_assert_ldouble_nan(pow(-S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-S21_INF, S21_NAN));
  ck_assert_ldouble_nan(pow(-S21_INF, -S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-S21_INF, -S21_NAN));

  ck_assert_ldouble_nan(pow(S21_NAN, -122));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -122));
  ck_assert_ldouble_nan(pow(S21_NAN, -1));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -1));
  ck_assert_ldouble_nan(pow(S21_NAN, 122));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 122));
  ck_assert_ldouble_nan(pow(S21_NAN, 1));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 1));
  ck_assert_ldouble_eq_tol(pow(S21_NAN, -0), s21_pow(S21_NAN, -0),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(S21_NAN, 0), s21_pow(S21_NAN, 0), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_NAN));
  ck_assert_ldouble_nan(pow(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(pow(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(pow(S21_NAN, -S21_INF));

  ck_assert_ldouble_nan(pow(-S21_NAN, -122));
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -122));
  ck_assert_ldouble_nan(pow(-S21_NAN, -1));
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -1));
  ck_assert_ldouble_nan(pow(-S21_NAN, 122));
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, 122));
  ck_assert_ldouble_nan(pow(-S21_NAN, 1));
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, 1));
  ck_assert_ldouble_eq_tol(pow(-S21_NAN, -0), s21_pow(-S21_NAN, -0),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-S21_NAN, 0), s21_pow(-S21_NAN, 0),
                           S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(pow(-S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -S21_NAN));
  ck_assert_ldouble_nan(pow(-S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, S21_INF));
  ck_assert_ldouble_nan(pow(-S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(pow(-S21_NAN, -S21_INF));

  ck_assert_ldouble_eq_tol(pow(1, -S21_INF), s21_pow(1, -S21_INF),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(1, -122), s21_pow(1, -122), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(1, -1), s21_pow(1, -1), S21_EPS_TEST);
  ck_assert_ldouble_eq(pow(1, S21_INF), s21_pow(1, S21_INF));
  ck_assert_ldouble_eq(pow(1, 122), s21_pow(1, 122));
  ck_assert_ldouble_eq(pow(1, 1), s21_pow(1, 1));
  ck_assert_ldouble_eq_tol(pow(1, -0), s21_pow(1, -0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(1, 0), s21_pow(1, 0), S21_EPS_TEST);
  ck_assert_ldouble_eq(pow(1, S21_NAN), s21_pow(1, S21_NAN));
  ck_assert_ldouble_eq(pow(1, -S21_NAN), s21_pow(1, -S21_NAN));

  ck_assert_ldouble_eq_tol(pow(-1, -S21_INF), s21_pow(-1, -S21_INF),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-1, -122), s21_pow(-1, -122), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-1, -1), s21_pow(-1, -1), S21_EPS_TEST);
  ck_assert_ldouble_eq(pow(-1, S21_INF), s21_pow(-1, S21_INF));
  ck_assert_ldouble_eq(pow(-1, 122), s21_pow(-1, 122));
  ck_assert_ldouble_eq(pow(-1, 1), s21_pow(-1, 1));
  ck_assert_ldouble_eq_tol(pow(-1, -0), s21_pow(-1, -0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-1, 0), s21_pow(-1, 0), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(-1, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-1, -S21_NAN));
  ck_assert_ldouble_nan(pow(-1, S21_NAN));
  ck_assert_ldouble_nan(pow(-1, -S21_NAN));

  ck_assert_ldouble_eq(pow(0, -S21_INF), s21_pow(0, -S21_INF));
  ck_assert_ldouble_eq(pow(0, -122), s21_pow(0, -122));
  ck_assert_ldouble_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_ldouble_eq(pow(0, S21_INF), s21_pow(0, S21_INF));
  ck_assert_ldouble_eq(pow(0, 122), s21_pow(0, 122));
  ck_assert_ldouble_eq(pow(0, 1), s21_pow(0, 1));
  ck_assert_ldouble_eq_tol(pow(0, -0), s21_pow(0, -0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(0, 0), s21_pow(0, 0), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(0, -S21_NAN));
  ck_assert_ldouble_nan(pow(0, S21_NAN));
  ck_assert_ldouble_nan(pow(0, -S21_NAN));

  ck_assert_ldouble_eq(pow(-0, -S21_INF), s21_pow(-0, -S21_INF));
  ck_assert_ldouble_eq(pow(-0, -122), s21_pow(-0, -122));
  ck_assert_ldouble_eq(pow(-0, -1), s21_pow(-0, -1));
  ck_assert_ldouble_eq(pow(-0, S21_INF), s21_pow(-0, S21_INF));
  ck_assert_ldouble_eq(pow(-0, 122), s21_pow(-0, 122));
  ck_assert_ldouble_eq(pow(-0, 1), s21_pow(-0, 1));
  ck_assert_ldouble_eq_tol(pow(-0, -0), s21_pow(-0, -0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(-0, 0), s21_pow(-0, 0), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_pow(-0, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-0, -S21_NAN));
  ck_assert_ldouble_nan(pow(-0, S21_NAN));
  ck_assert_ldouble_nan(pow(-0, -S21_NAN));

  ck_assert_ldouble_eq_tol(pow(0.4, INFINITY), s21_pow(0.4, INFINITY),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(pow(0.4, INFINITY), s21_pow(0.4, INFINITY),
                           S21_EPS_TEST);
  base = 0.5591951;
  exp = -S21_INF;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  base = 1.5591951;
  exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  base = 1.5591951;
  exp = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  base = -S21_INF;
  exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  base = S21_INF;
  exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
}
END_TEST

START_TEST(s21_sin_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = 2.15;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = 12325435.5464654;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -12325435.5464654;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = 12325435462.5464654;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -12325435462.5464654;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = 1e+10;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -1e+10;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = 0.0001;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -0.0001;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = 1.01;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -1.01;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = S21_PI;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = S21_PI / 2;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -S21_PI;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = S21_PI * 2;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  x = -S21_PI * 2;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_eq_tol(sin(DBL_MIN), s21_sin(DBL_MIN), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sin(DBL_MAX), s21_sin(DBL_MAX), S21_EPS_TEST);
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(sqrt(0.000000001), s21_sqrt(0.000000001),
                           S21_EPS_TEST);
  ck_assert_ldouble_nan(sqrt(-0.000000001));
  ck_assert_ldouble_nan(s21_sqrt(-0.000000001));
  ck_assert_ldouble_eq_tol(sqrt(0.07), s21_sqrt(0.07), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(4.0), s21_sqrt(4.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(1024.0), s21_sqrt(1024.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(121), s21_sqrt(121), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(81), s21_sqrt(81), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(0.000000), s21_sqrt(0.000000), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(-0.000000), s21_sqrt(-0.000000), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(-0), s21_sqrt(-0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(3.), s21_sqrt(3.), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(5.), s21_sqrt(5.), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(7.), s21_sqrt(7.), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(11.), s21_sqrt(11.), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(13.), s21_sqrt(13.), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(17.), s21_sqrt(17.), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(799015403.), s21_sqrt(799015403.),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(945804449.), s21_sqrt(945804449.),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(51795199.), s21_sqrt(51795199.), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(834477235658681.), s21_sqrt(834477235658681.),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(92751910095643.), s21_sqrt(92751910095643.),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(sqrt(1716204879506222369317.),
                           s21_sqrt(1716204879506222369317.), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_sqrt(-25.0));
  ck_assert_ldouble_nan(s21_sqrt(-0.0000001));
  ck_assert_ldouble_nan(sqrt(-S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-S21_NAN));
  ck_assert_ldouble_nan(sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(sqrt(-S21_DBL_MAX));
  ck_assert_ldouble_nan(s21_sqrt(-S21_DBL_MAX));
  ck_assert_ldouble_nan(sqrt(-1e4));
  ck_assert_ldouble_nan(s21_sqrt(-1e4));
  ck_assert_ldouble_nan(sqrt(-1.));
  ck_assert_ldouble_nan(s21_sqrt(-1.));
  ck_assert_ldouble_nan(sqrt(-0.1));
  ck_assert_ldouble_nan(s21_sqrt(-0.1));
  ck_assert_ldouble_infinite(sqrt(S21_INF));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_nan(sqrt(-S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
  ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_sqrt(-0.5));
  ck_assert_ldouble_nan(sqrt(-0.5));
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_sqrt(5.123456789123), sqrt(5.123456789123),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.00000004564897), sqrt(0.00000004564897),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_sqrt(170000000000000.1), sqrt(170000000000000.1),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(s21_tan_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = 12325435.5464654;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -12325435.5464654;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = 12325435462.5464654;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -12325435462.5464654;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = 1e+9;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -1e+9;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = 0.0001;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -0.0001;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = 1.01;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -1.01;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = S21_PI;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = S21_PI / 2;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = S21_PI / 2 + 0.0001;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -S21_PI / 2 + 0.0001;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -S21_PI;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = S21_PI * 2;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -S21_PI * 2;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = S21_PI / 6;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  x = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS_TEST);
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tan(NAN));
  ck_assert_ldouble_nan(tan(INFINITY));
  ck_assert_ldouble_nan(tan(-INFINITY));
  ck_assert_ldouble_eq_tol(tan(DBL_MIN), s21_tan(DBL_MIN), S21_EPS_TEST);
}
END_TEST

Suite *math_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_math");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_abs_test);
  tcase_add_test(tc_core, s21_acos_test);
  tcase_add_test(tc_core, s21_asin_test);
  tcase_add_test(tc_core, s21_atan_test);
  tcase_add_test(tc_core, s21_ceil_test);
  tcase_add_test(tc_core, s21_cos_test);
  tcase_add_test(tc_core, s21_exp_test);
  tcase_add_test(tc_core, s21_fabs_test);
  tcase_add_test(tc_core, s21_floor_test);
  tcase_add_test(tc_core, s21_fmod_test);
  tcase_add_test(tc_core, s21_log_test);
  tcase_add_test(tc_core, s21_pow_test);
  tcase_add_test(tc_core, s21_sin_test);
  tcase_add_test(tc_core, s21_sqrt_test);
  tcase_add_test(tc_core, s21_tan_test);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  Suite *tests[] = {math_suite(), NULL};
  int no_failed = 0;
  for (int i = 0; tests[i]; ++i) {
    SRunner *runner;
    runner = srunner_create(tests[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  if (no_failed == 0) {
    printf("TEST OK\n");
  }

  return 0;
}
