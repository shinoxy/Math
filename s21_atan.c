#include "s21_math.h"

long double s21_atan(double x) {
  long double a = 0;
  const long double S21_SQRT3 = 1.7320508075688773100;
  int sta = 0, sp = 0;
  long double x2 = 0;
  if (s21_isnan(x)) {
    a = S21_NAN;
  } else {
    if (x < 0) {
      x *= -1;
      sta |= 1;
    }
    if (x > 1) {
      x = 1 / x;
      sta |= 2;
    }
    while (x > S21_PI / 12) {
      sp++;
      a = x + S21_SQRT3;
      a = 1 / a;
      x *= S21_SQRT3;
      x -= 1;
      x *= a;
    }
    x2 = x * x;
    a = x2 + 1.4087812;
    a = 0.55913709 / a;
    a += 0.60310579;
    a -= 0.05160454 * x2;
    a *= x;
    while (sp > 0) {
      a += S21_PI / 6;
      sp--;
    }
    if (sta & 2) a = S21_PI / 2 - a;
    if (sta & 1) a = -a;
  }
  return a;
}