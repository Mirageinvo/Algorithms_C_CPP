#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <fenv.h>

int check(int b) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
        if ((b & (1 << i)) != 0) {
            ans++;
        }
    }
    return ans == 1 ? 1 : 0;
}

int main() {
    float a, b, res;
    unsigned* num;
    int exp = 0, mant = 0;
    scanf("%f%f", &a, &b);
    num = (unsigned*)&res;
    if (check(b) == 1) {
        res = a / b;
        for (int i = 0; i < 23; ++i) {
            if ((*num & (1 << i)) != 0) {
                mant += (1 << i);
            }
        }
        for (int i = 23; i < 31; ++i) {
            if ((*num & (1 << i)) != 0) {
                exp += (1 << (i - 23));
            }
        }
        printf("0x%x 0x%x", exp, mant);
    }
    else {
        fesetround(FE_DOWNWARD);
        res = a / b;
        for (int i = 0; i < 23; ++i) {
            if ((*num & (1 << i)) != 0) {
                mant += (1 << i);
            }
        }
        for (int i = 23; i < 31; ++i) {
            if ((*num & (1 << i)) != 0) {
                exp += (1 << (i - 23));
            }
        }
        printf("0x%x 0x%x ", exp, mant);


        fesetround(FE_UPWARD);
        exp = 0;
        mant = 0;
        if (res < 0) {
            fesetround(FE_DOWNWARD);
            mant = 1;
        }
        res = a / b;
        for (int i = 0; i < 23; ++i) {
            if ((*num & (1 << i)) != 0) {
                mant += (1 << i);
            }
        }
        for (int i = 23; i < 31; ++i) {
            if ((*num & (1 << i)) != 0) {
                exp += (1 << (i - 23));
            }
        }
        printf("0x%x 0x%x", exp, mant);
    }
    return 0;
}