#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <ctime>

//solution for:
//https://acm.timus.ru/problem.aspx?space=1&num=1471

//thanks to:
//https://e-maxx.ru/algo/lca

using namespace std;
typedef long long ll;

const int INF = 1000000000;

vector<vector<pair<int, int>>> gr;
vector<bool> used;
vector<int> height, first, order, dist, seg_tree;

void dfs(int u, int h) {
    used[u] = true;
    height[u] = h;
    order.push_back(u);
    if (first[u] == -1) {
        first[u] = order.size() - 1;
    }
    for (size_t i = 0; i < gr[u].size(); ++i) {
        if (!used[gr[u][i].first]) {
            dfs(gr[u][i].first, h + 1);
            order.push_back(u);
        }
    }
}

void build_seg_tree(int cur, int l, int r) {
    if (r - l == 1) {
        seg_tree[cur] = order[l];
        return;
    }
    int m = ((r - l) >> 1) + l;
    build_seg_tree(cur * 2 + 1, l, m);
    build_seg_tree(cur * 2 + 2, m, r);
    int res1 = seg_tree[cur * 2 + 1];
    int res2 = seg_tree[cur * 2 + 2];
    if (height[res1] < height[res2]) {
        seg_tree[cur] = res1;
    }
    else {
        seg_tree[cur] = res2;
    }
}

int get_min(int cur, int cl, int cr, int l, int r) {
    if (l >= cl && r <= cr) {
        return seg_tree[cur];
    }
    if (cr <= l || cl >= r) {
        return gr.size();
    }
    int m = ((r - l) >> 1) + l;
    int res1 = get_min(cur * 2 + 1, cl, cr, l, m);
    int res2 = get_min(cur * 2 + 2, cl, cr, m, r);
    if (height[res1] < height[res2]) {
        return res1;
    }
    return res2;
}

int get_lca(int v1, int v2) {
    if (v1 == v2) {
        return v1;
    }
    int left = first[v1], right = first[v2];
    if (left > right) {
        swap(left, right);
    }
    return get_min(0, left, right, 0, order.size());
}

void get_dist(int cur, int sum) {
    used[cur] = true;
    dist[cur] = sum;
    for (size_t i = 0; i < gr[cur].size(); ++i) {
        if (!used[gr[cur][i].first]) {
            get_dist(gr[cur][i].first, sum + gr[cur][i].second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    size_t n;
    int a, b, c, lca, tmp;
    cin >> n;
    gr.resize(n);
    dist.resize(n);
    height.resize(n + 1, INF);
    first.resize(n, -1);
    used.resize(n, false);
    for (size_t i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        gr[a].push_back({ b, c });
        gr[b].push_back({ a, c });
    }

    dfs(0, 1);
    seg_tree.resize(order.size() * 4);
    build_seg_tree(0, 0, order.size());
    used.assign(used.size(), false);
    get_dist(0, 0);

    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> a >> b;
        lca = get_lca(a, b);
        cout << dist[a] + dist[b] - (dist[lca] * 2) << endl;
    }
    return 0;
}