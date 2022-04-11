#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>

struct num {
    int l;
    int* dig;
};

int cmp(void const* lhs, void const* rhs) {
    struct num const* f = (struct num const*)lhs;
    struct num const* s = (struct num const*)rhs;
    int len = f->l;
    for (int i = 0; i < len; i++) {
        if (f->dig[i] < s->dig[i]) {
            return -1;
        }
        else if (f->dig[i] > s->dig[i]) {
            return 1;
        }
    }
    return 0;

}

int is_zero(struct num* x) {
    for (int i = 0; i < x->l; ++i) {
        if (x->dig[i] != 0) {
            return 0;
        }
    }
    return 1;
}

void get_n(struct num* y, int pos) {
    int new_p = 0;
    for (int i = pos - 1; i >= 0; i--) {
        if (y->dig[i] > 0) {
            new_p = i;
            break;
        }
    }
    y->dig[new_p] -= 1;
    y->dig[pos] += 10;
    for (int i = new_p + 1; i < pos; i++) {
        y->dig[i] += 9;
    }
}

void subtr(struct num* y, struct num* x) {
    while (cmp(y, x) >= 0) {
        for (int i = (y->l) - 1; i >= 0; i--) {
            if (y->dig[i] >= x->dig[i]) {
                y->dig[i] -= x->dig[i];
            }
            else {
                get_n(y, i);
                y->dig[i] -= x->dig[i];
            }
        }
    }
}

struct num* gcd(struct num* x, struct num* y) {
    if (cmp(x, y) == 1) {
        return gcd(y, x);
    }
    if (is_zero(x) == 1) {
        return y;
    }
    subtr(y, x);
    return gcd(y, x);
}


int main() {
    int l, max_sz = -1, was_nzero = 0;
    struct num* arr = (struct num*)calloc(2, sizeof(struct num));
    int* tmp[2];
    for (int i = 0; i < 2; i++) {
        scanf("%d", &l);
        arr[i].l = l;
        tmp[i] = (int*)calloc(l, sizeof(int));
        max_sz = (max_sz > l) ? max_sz : l;
        for (int j = 0; j < l; j++) {
            scanf("%d", &tmp[i][j]);
        }
    }
    arr[0].dig = (int*)calloc(max_sz, sizeof(int));
    arr[1].dig = (int*)calloc(max_sz, sizeof(int));
    for (int g = 0; g < 2; g++) {
        for (int i = 0; i < max_sz; i++) {
            if (i < max_sz - arr[g].l) {
                arr[g].dig[i] = 0;
            }
            else {
                arr[g].dig[i] = *(tmp[g] + i - (max_sz - arr[g].l));
            }
        }
    }
    arr[0].l = arr[1].l = max_sz;
    struct num* ans = gcd(&arr[0], &arr[1]);
    for (int i = 0; i < ans->l; ++i) {
        if (ans->dig[i] == 0 && was_nzero == 0)
            continue;
        if (was_nzero == 0 && ans->dig[i] != 0) {
            was_nzero = 1;
            printf("%d ", ans->l - i);
            printf("%d ", ans->dig[i]);
        }
        else {
            printf("%d ", ans->dig[i]);
        }
    }







    /*for (int i = 0; i < 2; i++) {
        free(arr[i].dig);
    }
    free(arr);*/
    return 0;
}