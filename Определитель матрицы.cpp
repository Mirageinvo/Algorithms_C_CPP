#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int n, badc = 0;

void find_max(double** matr, int* row, int* col, int ind) {
    double ans = 0.0;
    for (int i = ind; i < n; ++i) {
        for (int j = ind; j < n; ++j) {
            if (fabs(matr[i][j]) >= ans) {
                ans = fabs(matr[i][j]);
                *row = i;
                *col = j;
            }
        }
    }
}

void moverow(double** matr, int row, int ind) {
    double tmp;
    if (row == ind) {
        badc++;
    }
    else {
        for (int i = ind; i < n; ++i) {
            tmp = matr[ind][i];
            matr[ind][i] = matr[row][i];
            matr[row][i] = tmp;
        }
    }
}

void movecol(double** matr, int col, int ind) {
    double tmp;
    if (col == ind) {
        badc++;
    }
    else {
        for (int i = ind; i < n; ++i) {
            tmp = matr[i][ind];
            matr[i][ind] = matr[i][col];
            matr[i][col] = tmp;
        }
    }
}

void pivot(double** matr, int ind, int row, int col) {
    moverow(matr, row, ind);
    movecol(matr, col, ind);
}

void subtr(double** matr, int ind) {
    double mult;
    for (int i = ind + 1; i < n; ++i) {
        mult = matr[i][ind] / matr[ind][ind];
        matr[i][ind] = 0.0;
        for (int j = ind + 1; j < n; ++j) {
            matr[i][j] -= mult * matr[ind][j];
        }
    }
}

int main() {
    double** matr;
    double ans = 1.0;
    scanf("%d", &n);
    matr = (double**)calloc(n, sizeof(double*));
    for (int i = 0; i < n; ++i) {
        matr[i] = (double*)calloc(n, sizeof(double));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lg", &matr[i][j]);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int row = i, col = i;
        find_max(matr, &row, &col, i);
        if (fabs(matr[row][col]) == 0) {
            ans = 0;
            break;
        }
        pivot(matr, i, row, col);
        subtr(matr, i);
    }
    for (int i = 0; i < n; ++i) {
        ans *= matr[i][i];
    }
    if (badc % 2 == 1)
        ans *= -1.0;
    ans = round(ans);
    printf("%d", (int)ans);
    return 0;
}