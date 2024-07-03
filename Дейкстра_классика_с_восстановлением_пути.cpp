#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=193&chapterid=6#1

const long int INF = 1e9;

vector<vector<pair<int, int>>> gr;

int main() {
    int n;
    int from, to, tmp;
    cin >> n >> from >> to;
    gr.resize(n + 1);
    vector<bool> used(n + 1, false);
    vector<int> anc(n + 1, -1);
    vector<ll> dists(n + 1, INF);
    dists[from] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> tmp;
            if (i == j || tmp < 0) {
                continue;
            }
            gr[i].push_back({ j, tmp });
        }
    }
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j) {
            if (!used[j] && (v == -1 || dists[j] < dists[v])) {
                v = j;
            }
        }
        if (dists[v] == INF) {
            break;
        }

        used[v] = true;
        for (int j = 0; j < gr[v].size(); ++j) {
            int to_vertex = gr[v][j].first;
            int to_vertex_len = gr[v][j].second;
            if (dists[to_vertex] > dists[v] + to_vertex_len) {
                dists[to_vertex] = dists[v] + to_vertex_len;
                anc[to_vertex] = v;
            }
        }
    }
    
    if (dists[to] == INF) {
        cout << -1 << endl;
    }
    else {
        vector<int> ans;
        int cur = to;
        while (cur != from) {
            ans.push_back(cur);
            cur = anc[cur];
        }
        ans.push_back(cur);
        reverse(ans.begin(), ans.end());
        for (auto& el : ans) {
            cout << el << " ";
        }
    }

    return 0;
}
