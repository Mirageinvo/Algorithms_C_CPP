#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <deque>
#include <tuple>
#include <set>
#include <cctype>
#include <stack>
#include <cstdio>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int INF = 1e9;

int n, k;
vector<int> d;
vector<vector<pair<int, int>>> gr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    d.resize(n * (k + 1));
    gr.resize(n * (k + 1));
    d.assign(n * (k + 1), INF);
    d[n * k] = 0;
    vector<int> add(n, 0);
    vector<bool> used(n);
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            used[l] = true;
            used[r] = true;
            gr[l + add[l]].push_back({ r + add[r], 0 });
            gr[r + add[r]].push_back({ l + add[l], 0 });
            gr[l + add[l]].push_back({ n * k + l, 0 });
            gr[n * k + l].push_back({ l + add[l], 1 });
            gr[r + add[r]].push_back({ n * k + r, 0 });
            gr[n * k + r].push_back({ r + add[r], 1 });
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                add[i] += n;
                used[i] = false;
            }
        }
    }
    deque<int> q;
    q.push_back(n * k);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (pair<int, int> u : gr[v]) {
            if (d[u.first] > d[v] + u.second) {
                d[u.first] = d[v] + u.second;
                if (u.second == 0) {
                    q.push_front(u.first);
                }
                else {
                    q.push_back(u.first);
                }
            }
        }
    }
    int best = INF;
    for (int i = n - 1; i < n * (k + 1); i += n) {
        best = min(best, d[i]);
    }
    if (best == INF)
        cout << -1;
    else {
        cout << best;
    }
    return 0;
}