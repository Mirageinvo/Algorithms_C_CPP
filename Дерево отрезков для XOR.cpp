#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int* tr;
int* arr;

void build_tr(int v, int l, int r) {
    if (r - l == 1) {
        tr[v] = arr[l];
        return;
    }
    int m = (r - l) / 2 + l;
    build_tr(v * 2, l, m);
    build_tr(v * 2 + 1, m, r);
    tr[v] = (tr[v * 2] ^ tr[v * 2 + 1]);
}


int xr(int v, int l, int r, int askl, int askr) {
    if (l >= askr || r <= askl) {
        return 0;
    }
    if (l >= askl && r <= askr) {
        return tr[v];
    }
    int m = l + (r - l) / 2;
    return (xr(v * 2, l, m, askl, askr) ^ xr(v * 2 + 1, m, r, askl, askr));
}

void update(int v, int l, int r, int pos, int val) {
    if (r - l == 1) {
        tr[v] = val;
        return;
    }
    int m = l + (r - l) / 2;
    if (pos < m) {
        update(v * 2, l, m, pos, val);
    }
    else {
        update(v * 2 + 1, m, r, pos, val);
    }
    tr[v] = (tr[v * 2] ^ tr[v * 2 + 1]);
}

int main() {
    scanf("%d%d", &n, &m);
    int* inq = (int*)calloc(3, sizeof(int));
    tr = (int*)calloc(n * 4, sizeof(int));
    arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    build_tr(1, 0, n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &inq[0], &inq[1], &inq[2]);
        if (inq[0] == 1) {
            printf("%d\n", xr(1, 0, n, inq[1], inq[2] + 1));
        }
        else {
            update(1, 0, n, inq[1], inq[2]);
        }
    }
    return 0;
}