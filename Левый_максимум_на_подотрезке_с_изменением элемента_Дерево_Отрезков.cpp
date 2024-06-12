#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cstdio>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long int INF = 1e9;

void build_seg_tree(vector<int>& seg_tree, const vector<int>& elements, int l, int r, int ind) {
    if (r - l == 1) {
        seg_tree[ind] = l;
        return;
    }
    int m = l + ((r - l) / 2);
    build_seg_tree(seg_tree, elements, l, m, ind * 2 + 1);
    build_seg_tree(seg_tree, elements, m, r, ind * 2 + 2);
    seg_tree[ind] = (elements[seg_tree[ind * 2 + 1]] >= elements[seg_tree[ind * 2 + 2]]) ? seg_tree[ind * 2 + 1]
                                                                                         : seg_tree[ind * 2 + 2];
}

int get_ind(const vector<int>& seg_tree, const vector<int>& elements, int curind, int curl, int curr, int begin, int end) {
    if (curl >= begin && curr <= end) {
        return seg_tree[curind];
    }
    if (curl >= end || curr <= begin) {
        return elements.size() - 1; // index of the smallest element (we put it intentionally to the end)
    }
    int m = curl + ((curr - curl) / 2);
    int lind = get_ind(seg_tree, elements, curind * 2 + 1, curl, m, begin, end);
    int rind = get_ind(seg_tree, elements, curind * 2 + 2, m, curr, begin, end);
    if (elements[lind] >= elements[rind]) {
        return lind;
    }
    return rind;
}

void update(vector<int>& seg_tree, const vector<int>& elements, int ind, int curl, int curr, int val_ind) {
    if (curr - curl == 1) {
        seg_tree[ind] = curl;
        return;
    }
    int m = curl + ((curr - curl) / 2);
    if (val_ind < m) {
        update(seg_tree, elements, ind * 2 + 1, curl, m, val_ind);
    }
    else {
        update(seg_tree, elements, ind * 2 + 2, m, curr, val_ind);
    }
    seg_tree[ind] = (elements[seg_tree[ind * 2 + 1]] >= elements[seg_tree[ind * 2 + 2]]) ? seg_tree[ind * 2 + 1]
                                                                                         : seg_tree[ind * 2 + 2];
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> seg_tree(n * 4);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = -INF;
    build_seg_tree(seg_tree, a, 0, n, 0);
    cin >> m;
    int left, right, id, new_val;
    char type;
    for (int i = 0; i < m; ++i) {
        cin >> type;
        if (type == 's') {
            cin >> left >> right;
            cout << get_ind(seg_tree, a, 0, 0, n, left - 1, right) + 1 << " ";
        }
        else {
            cin >> id >> new_val;
            id--;
            a[id] = new_val;
            update(seg_tree, a, 0, 0, n, id);
        }
    }
    return 0;
}
