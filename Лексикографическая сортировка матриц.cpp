#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> find_mn(int** v, int n, int m) {
    pair<int, int> ans = { 0, 0 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] < v[ans.first][ans.second]) {
                ans.first = i;
                ans.second = j;
            }
        }
    }
    return ans;
}

void move_sm(int** v, pair<int, int> pr, int n) {
    swap(v[0], v[pr.first]);
    for (int i = 0; i < n; ++i) {
        swap(v[i][0], v[i][pr.second]);
    }
}

int** smart_bubble_col(int** v, int n, int m) {
    bool sorted = false;
    int m2 = m;

    int** nw = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        nw[i] = (int*)calloc(m, sizeof(int));
    }

    int* tmp = (int*)calloc(m, sizeof(int));
    for (int i = 1; i <= m - 1; ++i)
        tmp[i] = i;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < m2 - 1; ++i) {
            if (v[0][tmp[i]] > v[0][tmp[i + 1]]) {
                sorted = false;
                swap(tmp[i], tmp[i + 1]);
            }
        }
        m2--;
    }
    for (int i = 0; i < n; ++i) {
        nw[i][0] = v[i][0];
    }
    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            nw[i][j] = v[i][tmp[j]];
        }
    }
    return nw;
}

void smart_bubble_row(int** nw, int n) {
    bool sorted = false;
    int n2 = n;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n2 - 1; ++i) {
            if (nw[i][0] > nw[i + 1][0]) {
                sorted = false;
                swap(nw[i], nw[i + 1]);
            }
        }
        n2--;
    }
}

int main() {
    int n, m;
    int** nw;
    cin >> n >> m;
    int** v = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        v[i] = (int*)calloc(m, sizeof(int));
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    move_sm(v, find_mn(v, n, m), n);
    nw = smart_bubble_col(v, n, m);
    smart_bubble_row(nw, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", nw[i][j]);
        }
        printf("\n");
    }
    return 0;
}