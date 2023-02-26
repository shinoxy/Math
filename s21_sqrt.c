#include "s21_math.h"

long double s21_sqrt(double x) {
  long double x0 = 0;
  if (x == 0) {
    x0 = 0;
  } else if (x < 0 || s21_isnan(x)) {
    x0 = S21_NAN;
  } else if (x == S21_INF) {
    x0 = S21_INF;
  } else {
    long double x1 = 0;
    x0 = x / 2;
    do {
      x1 = x0;
      x0 = (x0 + x / x0) / 2;
    } while (x0 != x1);
  }
  return x0;
}