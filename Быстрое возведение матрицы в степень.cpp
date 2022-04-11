//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <fenv.h>

double** matrmult(double** matrf, double** matrs, int n) {
    if (matrf != matrs) {
        double sum;
        double** tmp = (double**)calloc(n, sizeof(double*));
        for (int i = 0; i < n; ++i) {
            tmp[i] = (double*)calloc(n, sizeof(double));
            for (int j = 0; j < n; ++j) {
                tmp[i][j] = matrs[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum = 0;
                for (int h = 0; h < n; ++h) {
                    sum += tmp[i][h] * matrf[h][j];
                }
                matrs[i][j] = sum;
            }
        }
        for (int i = 0; i < n; ++i) {
            free(tmp[i]);
        }
        free(tmp);
        return matrs;
    }
    else {
        double sum;
        double** tmp = (double**)calloc(n, sizeof(double*));
        for (int i = 0; i < n; ++i) {
            tmp[i] = (double*)calloc(n, sizeof(double));
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum = 0;
                for (int h = 0; h < n; ++h) {
                    sum += matrf[i][h] * matrf[h][j];
                }
                tmp[i][j] = sum;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrs[i][j] = tmp[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            free(tmp[i]);
        }
        free(tmp);
        return matrs;
    }
}

double** powe(int curpow, int n, double** matrst, double** matr) {
    if (curpow == 1) {
        return matr;
    }
    if (curpow % 2 == 1) {
        return matrmult(matrst, powe(curpow - 1, n, matrst, matr), n);
    }
    else {
        double** get = powe(curpow / 2, n, matrst, matr);
        return matrmult(get, get, n);
    }
}

int cmp(const void* a, const void* b) {
    return *(double*)a > *(double*)b ? -1 : 1;
}

int main() {
    int p, n;
    double ans = 0;
    double** matr, **matrst;
    double* arr;
    scanf("%d%d", &p, &n);
    matr = (double**)calloc(n, sizeof(double*));
    matrst = (double**)calloc(n, sizeof(double*));
    arr = (double*)calloc(n * n, sizeof(double));
    for (int i = 0; i < n; ++i) {
        matr[i] = (double*)calloc(n, sizeof(double));
        matrst[i] = (double*)calloc(n, sizeof(double));
        for (int j = 0; j < n; ++j) {
            scanf("%lg", &matr[i][j]);
            matrst[i][j] = matr[i][j];
        }
    }
    matr = powe(p, n, matrst, matr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[n * i + j] = matr[i][j];
        }
    }
    qsort(arr, n * n, sizeof(double), cmp);
    for (int i = 0; i < n * n; ++i) {
        ans += arr[i];
    }
    for (int i = 0; i < n; ++i) {
        free(matr[i]);
        free(matrst[i]);
    }
    free(matr);
    free(matrst);
    free(arr);
    printf("%.5f", ans);
    return 0;
}