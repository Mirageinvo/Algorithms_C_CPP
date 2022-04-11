#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <fenv.h>

int n, cnt = 1, ind = 1;

struct tree {
    struct tree* left;
    struct tree* right;
    int val, left_min, right_max;
};

void mktree(struct tree* cur, int* arr) {
    if (arr[ind] > cur->val && (cur->right_max == -1 || cur->right_max > arr[ind])) {
        if (cur->right == NULL) {
            cur->right = (struct tree*)malloc(sizeof(struct tree));
            cur->right->left = NULL;
            cur->right->right = NULL;
            cur->right->right_max = cur->right_max;
            cur->right->left_min = cur->val;
            cur->right->val = arr[ind++];
        }
        else {
            mktree(cur->right, arr);
        }
    }
    else if (arr[ind]<cur->val && (cur->left_min == -1 || cur->left_min < arr[ind])) {
        if (cur->left == NULL) {
            cur->left = (struct tree*)malloc(sizeof(struct tree));
            cur->left->left = NULL;
            cur->left->right = NULL;
            cur->left->right_max = cur->val;
            cur->left->left_min = cur->left_min;
            cur->left->val = arr[ind++];
        }
        else {
            mktree(cur->left, arr);
        }
    }
}

void getans(struct tree* cur, int* ans, int* ansval) {
    if (cnt == n)
        return;
    if (cur->left != NULL) {
        ans[ind++] = 1;
        ansval[cnt++] = cur->left->val;
        getans(cur->left, ans, ansval);
    }
    else {
        ans[ind++] = 0;
    }
    if (cur->right != NULL) {
        ans[ind++] = 1;
        ansval[cnt++] = cur->right->val;
        getans(cur->right, ans, ansval);
    }
    else {
        ans[ind++] = 0;
    }
}

int main() {
    int* arr, *ans, *ansval;
    struct tree head;
    scanf("%d", &n);
    arr = (int*)calloc(n, sizeof(int));
    ansval = (int*)calloc(n, sizeof(int));
    ans = (int*)calloc(n * 2, sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    head.left = NULL;
    head.right = NULL;
    head.val = arr[0];
    head.left_min = -1;
    head.right_max = -1;
    while (ind != n) {
        mktree(&head, arr);
    }
    ind = 1;
    ans[0] = 1;
    ansval[0] = head.val;
    getans(&head, ans, ansval);
    for (int i = ind; i < n * 2; ++i) {
        ans[i] = 0;
    }
    printf("%d ", n);
    for (int i = 0; i < n * 2; ++i) {
        printf("%d ", ans[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ansval[i]);
    }
    return 0;
}