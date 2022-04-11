#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count(int x, int y) {
    int ans = 1;
    while (x >= y) {
        x /= y;
        ans++;
    }
    return ans;
}

int main() {
    int* arr;
    int x, y, tmp, ans = 0;
    scanf("%d%d", &x, &y);
    if (y == 10) {
        printf("%d", x);
        return 0;
    }
    tmp = count(x, y);
    arr = (int*)calloc(tmp, sizeof(int));
    for (int i = 0; i < tmp; ++i) {
        arr[tmp - i - 1] = x % y;
        x /= y;
    }
    for (int i = tmp - 1; i >= 0; --i) {
        ans += arr[tmp - 1 - i] * pow(10, i);
    }
    printf("%d", ans);
    return 0;
}