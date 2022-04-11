//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    struct node* next;
    int num, dp;
};

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int move_and_take(struct node* bgn, int i) {
    while (bgn->num != i) {
        bgn = bgn->next;
    }
    return bgn->dp;
}

int move_and_take2(struct node** bgn, int i) {
    while ((*bgn)->num != i) {
        *bgn = (*bgn)->next;
    }
    return (*bgn)->dp;
}

int main() {
    int sum = 0, tmp = 0, n = 0;
    int* arr;
    struct node* t;
    struct node* f = (struct node*)malloc(sizeof(struct node));
    struct node* bgn = (struct node*)malloc(sizeof(struct node));
    scanf("%d %d", &sum, &n);
    arr = (int*)calloc(n, sizeof(int));
    bgn = f;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    f->dp = 1e9;
    for (int i = 1; i < arr[0]; ++i) {
        f->num = i;
        f->next = (struct node*)malloc(sizeof(struct node));
        f->next->dp = 1e9;
        f = f->next;
    }
    for (int i = arr[0]; i <= arr[n - 1]; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[j] > i)
                break;
            if (arr[j] == i) {
                f->dp = 1;
                break;
            }
            f->dp = min(f->dp, move_and_take(bgn, i - arr[j]) + 1);
        }
        f->num = i;
        if (i != arr[n - 1]) {
            f->next = (struct node*)malloc(sizeof(struct node));
            f->next->dp = 1e9;
            f = f->next;
        }
    }
    f->next = bgn;
    f = f->next;

    for (int i = arr[n - 1] + 1; i <= sum; ++i) {
        if (i != arr[n - 1] + 1)
            f = f->next;
        tmp = 1e9;
        t = bgn;
        for (int j = n-1; j >=0; --j) {
            tmp = min(tmp, (move_and_take2(&t, i - arr[j]) + 1));
        }
        f->dp = tmp;
        f->num = i;
        bgn = bgn->next;
    }
    printf("%d", f->dp);
    return 0;
}