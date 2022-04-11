#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long long ull;

int main() {
    int n, m;
    bool mdchanges = true;
    bool good_start = true;
    scanf("%d%d", &n, &m);
    int** matr = (int**)calloc(n, sizeof(int*));
    int* row_sum = (int*)calloc(n, sizeof(int));
    int* col_sum = (int*)calloc(m, sizeof(int));
    bool* row_is_invr = (bool*)calloc(n, sizeof(bool));
    bool* col_is_invr = (bool*)calloc(m, sizeof(bool));
    for (int i = 0; i < n; ++i) {
        row_is_invr[i] = false;
        matr[i] = (int*)calloc(m, sizeof(int));
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matr[i][j]);
            row_sum[i] += matr[i][j];
            col_sum[j] += matr[i][j];
            col_is_invr[j] = false;
        }
        if (row_sum < 0) {
            good_start = false;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (col_sum[i] < 0) {
            good_start = false;
        }
    }
    if (good_start) {
        return 0;
    }

    for (int it = 0; it < n; ++it) {
        if (!mdchanges) {
            break;
        }
        else {
            mdchanges = false;
        }

        for (int i = 0; i < n; ++i) {
            if (row_sum[i] < 0) {
                for (int j = 0; j < m; ++j) {
                    matr[i][j] *= -1;
                    col_sum[j] += matr[i][j] * 2;
                }
                row_sum[i] *= -1;
                row_is_invr[i] ^= true;
                mdchanges = true;
            }
        }

        for (int j = 0; j < m; ++j) {
            if (col_sum[j] < 0) {
                for (int i = 0; i < n; ++i) {
                    matr[i][j] *= -1;
                    row_sum[i] += matr[i][j] * 2;
                }
                col_sum[j] *= -1;
                col_is_invr[j] ^= true;
                mdchanges = true;
            }
        }
    }

    if (mdchanges) {
        for (int i = 0; i < n; ++i) {
            if (row_sum[i] < 0) {
                printf("Impossible");
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (row_is_invr[i]) {
            printf("l %d\n", i);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (col_is_invr[i]) {
            printf("c %d\n", i);
        }
    }
    return 0;
}