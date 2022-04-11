#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long gcd(long long a, long long b, long long* x, long long* y) {
  long long x1, y1, d;
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  d = gcd(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return d;
}

int main() {
  long long x, y, a, b, d;
  scanf("%lld %lld", &a, &b);
  d = gcd(a, b, &x, &y);
  printf("%lld %lld %lld", x, y, d);
  return 0;
}