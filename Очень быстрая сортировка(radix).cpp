#include <stdio.h>

typedef unsigned long long ull;

int main() {
    size_t divided[4][256];
    static unsigned arr1[60000000];
    static unsigned arr2[60000000];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 256; ++j) {
            divided[i][j] = 0;
        }
    }
    size_t n, k, m, l, ans = 0;
    scanf("%lu%lu%lu%lu", &n, &k, &m, &l);

    ++divided[0][k & 0xFFU];
    ++divided[1][(k >> 8) & 0xFFU];
    ++divided[2][(k >> 16) & 0xFFU];
    ++divided[3][k >> 24];
    arr1[0] = k;

    for (size_t i = 0; i < n - 1; ++i) {
        arr1[i + 1] = (unsigned int)((arr1[i] * (size_t)m) & 0xFFFFFFFFU) % l;
        ++divided[0][arr1[i + 1] & 0xFFU];
        ++divided[1][(arr1[i + 1] >> 8) & 0xFFU];
        ++divided[2][(arr1[i + 1] >> 16) & 0xFFU];
        ++divided[3][arr1[i + 1] >> 24];
    }
    for (size_t i = 1; i < 256; ++i) {
        divided[0][i] += divided[0][i - 1];
        divided[1][i] += divided[1][i - 1];
        divided[2][i] += divided[2][i - 1];
        divided[3][i] += divided[3][i - 1];
    }
    for (size_t j = n - 1; j > 0; --j) {
        arr2[--divided[0][arr1[j] & 0xFFU]] = arr1[j];
    }
    arr2[--divided[0][arr1[0] & 0xFFU]] = arr1[0];

    for (size_t j = n - 1; j > 0; --j) {
        arr1[--divided[1][(arr2[j] >> 8) & 0xFFU]] = arr2[j];
    }
    arr1[--divided[1][(arr2[0] >> 8) & 0xFFU]] = arr2[0];

    for (size_t j = n - 1; j > 0; --j) {
        arr2[--divided[2][(arr1[j] >> 16) & 0xFFU]] = arr1[j];
    }
    arr2[--divided[2][(arr1[0] >> 16) & 0xFFU]] = arr1[0];

    for (size_t j = n - 1; j > 0; --j) {
        ans += arr2[j] * ((divided[3][arr2[j] >> 24]--) & 1);
    }
    if (((divided[3][arr2[0] >> 24]--) & 1)) {
        ans += arr2[0];
    }

    ans %= l;
    printf("%lu", ans);
    return 0;
}