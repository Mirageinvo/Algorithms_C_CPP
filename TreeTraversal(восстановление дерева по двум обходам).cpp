#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int indx = 0;

int abs(int x) {
    return (x > 0) ? x : -x;
}

struct node {
    struct node* left, * right;
    int val;
    int ind;
};

int getind(int* in, int val, int n) {
    for (int i = 0; i < n; ++i) {
        if (in[i] == val) {
            return i;
        }
    }
    return -1;
}

int is_between(int* in, int prevind, int curind, int val, int n) {
    for (int i = 0; i < n; ++i) {
        if (in[i] == val) {
            if ((i - prevind) * (i - curind) < 0) {
                return 1;
            }
            return 0;
        }
    }
    return -1;
}

int check(int* pre, int* in, int curind, int crind, int n) {
    int tmp;
    for (int i = 0; i < indx; ++i) {
        tmp = getind(in, pre[i], n);
        if (tmp > curind && tmp < crind) {
            return 0;
        }
    }
    return 1;
}

void mktree(struct node* cur, int* in, int* pre, int n, int prevind) {
    if (prevind != -1) {
        if (cur->ind < prevind) {
            if (cur->ind > 0 && indx < n - 1 && getind(in, pre[indx + 1], n) < getind(in, cur->val, n)) { // находится ли левее? нужна проверка
                cur->left = (struct node*)malloc(sizeof(struct node));
                cur->left->right = NULL;
                cur->left->left = NULL;
                cur->left->val = pre[indx + 1];
                cur->left->ind = getind(in, pre[indx + 1], n);
                /*if (pre[indx + 1] == 2) {
                    printf("%d %d %d", prevind, cur->ind, cur->left->ind);
                }*/
                indx++;
                mktree(cur->left, in, pre, n, cur->ind);
            }
            if (indx < n - 1 && is_between(in, prevind, cur->ind, pre[indx + 1], n) == 1) {
                cur->right = (struct node*)malloc(sizeof(struct node));
                cur->right->right = NULL;
                cur->right->left = NULL;
                cur->right->val = pre[indx + 1];
                cur->right->ind = getind(in, pre[indx + 1], n);
                indx++;
                mktree(cur->right, in, pre, n, cur->ind);
            }
        }
        if (cur->ind > prevind) {
            if (indx < n - 1 && is_between(in, prevind, cur->ind, pre[indx + 1], n) == 1) {
                cur->left = (struct node*)malloc(sizeof(struct node));
                cur->left->right = NULL;
                cur->left->left = NULL;
                cur->left->val = pre[indx + 1];
                cur->left->ind = getind(in, pre[indx + 1], n);
                indx++;
                mktree(cur->left, in, pre, n, cur->ind);
            }
            if (cur->ind < n - 1 && indx < n - 1 && getind(in, pre[indx + 1], n) > getind(in, cur->val, n) && check(pre, in, cur->ind, getind(in, pre[indx + 1], n), n) == 1) {
                cur->right = (struct node*)malloc(sizeof(struct node));
                cur->right->right = NULL;
                cur->right->left = NULL;
                cur->right->val = pre[indx + 1];
                cur->right->ind = getind(in, pre[indx + 1], n);
                indx++;
                mktree(cur->right, in, pre, n, cur->ind);
            }
        }
    }
    else {
        if (indx < n - 1 && getind(in, cur->val, n) > 0) {
            cur->left = (struct node*)malloc(sizeof(struct node));
            cur->left->right = NULL;
            cur->left->left = NULL;
            cur->left->val = pre[indx + 1];
            cur->left->ind = getind(in, pre[indx + 1], n);
            indx++;
            mktree(cur->left, in, pre, n, cur->ind);
        }
        if (indx < n - 1 && getind(in, cur->val, n) < n - 1) {
            cur->right = (struct node*)malloc(sizeof(struct node));
            cur->right->right = NULL;
            cur->right->left = NULL;
            cur->right->val = pre[indx + 1];
            cur->right->ind = getind(in, pre[indx + 1], n);
            indx++;
            mktree(cur->right, in, pre, n, cur->ind);
        }
    }
    return;
}

void getans(struct node* cur, int* ans, int n, int count) {
    if (count == n)
        return;
    ans[indx++] = 1;
    count++;
    if (cur->left != NULL) {
        getans(cur->left, ans, n, count);
    }
    else {
        ans[indx++] = 0;
    }
    if (cur->right != NULL) {
        getans(cur->right, ans, n, count);
    }
    else {
        ans[indx++] = 0;
    }
    return;
}

int main() {
    int n, count = 0;
    int* pre, * in, * ans;
    struct node* cur;
    struct node head;
    scanf("%d", &n);
    pre = (int*)calloc(n, sizeof(int));
    in = (int*)calloc(n, sizeof(int));
    ans = (int*)calloc(n * 2, sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    //head = { NULL, NULL, pre[0], getind(in, pre[0], n) };
    head.left = NULL;
    head.right = NULL;
    head.val = pre[0];
    head.ind = getind(in, pre[0], n);
    cur = &head;
    mktree(cur, in, pre, n, -1);
    indx = 0;
    getans(&head, ans, n, count);
    for (int i = indx; i < n * 2; ++i) {
        ans[i] = 0;
    }
    printf("%d ", n);
    for (int i = 0; i < n * 2; ++i) {
        printf("%d ", ans[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", pre[i]);
    }
    return 0;
}