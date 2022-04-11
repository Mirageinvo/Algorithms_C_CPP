//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <fenv.h>

double getpow(double x, int p) {
    double ans = 1.0;
    for (int i = 0; i < p; ++i) {
        ans *= x;
    }
    return ans;
}

double getval(double* coeffs, int degree, double x) {
    double ans = 0.0;
    for (int i = 0; i <= degree; ++i) {
        ans += coeffs[i] * getpow(x, i);
    }
    return ans;
}

double polyroot(double* coeffs, int degree) {
    double m, l = -10.0, r = 10.0;
    while (getval(coeffs, degree, l) >= 0) {
        l *= 10.0;
    }
    while (getval(coeffs, degree, r) <= 0) {
        r *= 10.0;
    }
    m = (l + r) / 2.0;
    while (fabs(getval(coeffs, degree, m)) > 1e-9) {
        if (getval(coeffs, degree, m) < 0) {
            l = m;
        }
        else {
            r = m;
        }
        m = (l + r) / 2.0;
    }
    return m;
}
/*
int main() {
    int n;
    double* coeffs;
    scanf("%d", &n);
    coeffs = (double*)calloc(n, sizeof(double));
    for (int i = 0; i < n; ++i) {
        scanf("%lg", &coeffs[i]);
    }
    printf("%.5lf", polyroot(coeffs, n - 1));
    return 0;
}*/