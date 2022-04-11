#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

vector<int> p, d;

int get_par(int v) {
    if (p[v] == v)
        return v;
    return p[v] = get_par(p[v]);
}

void unite(int v, int u) {
    u = get_par(u);
    v = get_par(v);
    if (u != v) {
        if (d[u] > d[v])
            swap(u, v);
        p[u] = v;
        if (d[u] == d[v])
            d[v]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(n);
    d.resize(n);
    vector<pair<int, pair<int, int>>> a;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        d[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        a.push_back({ w, {x - 1, y - 1} });
        a.push_back({ w, {y - 1, x - 1} });
    }
    sort(a.begin(), a.end());
    int count = 0;
    ll ans = 0;
    for (auto& edge : a) {
        if (get_par(edge.second.first) != get_par(edge.second.second)) {
            unite(edge.second.first, edge.second.second);
            ans += edge.first;
            count++;
        }
        if (count == n - 1)
            break;
    }
    cout << ans;
    return 0;
}