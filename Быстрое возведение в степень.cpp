#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int pow(int num, int curpow) {
    if (curpow == 1) {
        return num;
    }
    if (curpow % 2 == 1) {
        return num * pow(num, curpow - 1);
    }
    else {
        int tmp = pow(num, curpow / 2);
        return tmp * tmp;
    }
}

int main() {
    int n, num, ans;
    scanf("%d%d", &num, &n);
    ans = pow(num, n);
    printf("%d\n", ans);
    return 0;
}