#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <fenv.h>

struct node_t {
    struct node_t* left;
    struct node_t* right;
    int data;
};

struct node_t* to_dlist(struct node_t* cur) {
    struct node_t* l = NULL, * r = NULL, * tmp = NULL;
    if (cur->left == NULL && cur->right == NULL) {
        return cur;
    }
    if (cur->left != NULL) {
        l = to_dlist(cur->left);
    }
    if (cur->right != NULL) {
        r = to_dlist(cur->right);
    }
    if (l != NULL && r != NULL) {
        tmp = l;
        while (tmp->right != NULL) {
            tmp = tmp->right;
        }
        tmp->right = cur;
        cur->left = tmp;
        r->left = cur;
        cur->right = r;
        return l;
    }
    if (r != NULL) {
        r->left = cur;
        cur->right = r;
        return cur;
    }
    if (l != NULL) {
        tmp = l;
        while (tmp->right != NULL) {
            tmp = tmp->right;
        }
        tmp->right = cur;
        cur->left = tmp;
        return l;
    }
    return NULL;
}

int main() {
    struct node_t head = { NULL, NULL, 1 };
    struct node_t* cur = &head;
    cur->left = (struct node_t*)malloc(sizeof(struct node_t));
    cur->right = (struct node_t*)malloc(sizeof(struct node_t));
    cur->right->data = 3;
    cur->right->left = NULL;
    cur->right->right = NULL;
    cur->left->data = 2;
    cur->left->left = NULL;
    cur->left->right = (struct node_t*)malloc(sizeof(struct node_t));
    cur->left->right->data = 4;
    cur->left->right->left = NULL;
    cur->left->right->right = NULL;
    cur = to_dlist(&head);
    while (cur->right != NULL) {
        cur = cur->right;
    }
    while (cur->left != NULL) {
        printf("%d ", cur->data);
        cur = cur->left;
    }
    printf("%d", cur->data);
    return 0;
}