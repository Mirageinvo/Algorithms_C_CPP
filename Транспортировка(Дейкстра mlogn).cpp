#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
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
int n, m;
vector<int> d;
vector<vector<int>> gr;
vector<vector<pair<int, int>>> a;

bool check(int mid) {
    d.assign(n, INF);
    d[0] = 0;
    set<pair<int, int>> s;
    s.insert({ 0, 0 });
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for (int u : gr[v]) {
            if (a[v][u].first >= mid && d[u] > d[v] + a[v][u].second) {
                s.erase({ d[u], u });
                d[u] = d[v] + a[v][u].second;
                s.insert({ d[u], u });
            }
        }
    }
    if (d[n - 1] <= 1440)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    d.resize(n);
    gr.resize(n);
    a.resize(n, vector<pair<int, int>>(n));
    for (int i = 0; i < m; i++) {
        int l, k, t, w;
        cin >> l >> k;
        gr[l - 1].push_back(k - 1);
        gr[k - 1].push_back(l - 1);
        cin >> t >> w;
        w -= 3000000;
        w /= 100;
        a[l - 1][k - 1] = { w, t };
        a[k - 1][l - 1] = { w, t };
    }
    int l = 0;
    int r = 1e7;
    while (r - l != 1) {
        int mid = l + (r - l) / 2;
        if (check(mid))
            l = mid;
        else {
            r = mid;
        }
    }
    cout << l;
    return 0;
}