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
const int INF = 1e9;

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
    vector<pair<int, pair<int, int>>> a;
    p.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    int ans1 = 0, ans2 = INF, count = 0;
    for (int i = 0; i < m; i++) {
        int w, x, y;
        cin >> x >> y >> w;
        a.push_back({ w, {x - 1, y - 1} });
    }
    sort(a.begin(), a.end());
    vector<int> in;
    int h = 0;
    for (auto& edge : a) {
        if (get_par(edge.second.first) != get_par(edge.second.second)) {
            unite(edge.second.first, edge.second.second);
            count++;
            ans1 += edge.first;
            in.emplace_back(h);
        }
        if (count == n - 1) {
            break;
        }
        h++;
    }
    for (int i = 0; i < n - 1; i++) {
        int cur_ans = 0;
        count = 0;
        for (int g = 0; g < n; g++) {
            p[g] = g;
            d[g] = 0;
        }
        for (int j = 0; j < m; j++) {
            if (in[i] != j && get_par(a[j].second.first) != get_par(a[j].second.second)) {
                unite(a[j].second.first, a[j].second.second);
                count++;
                cur_ans += a[j].first;
            }
            if (count == n - 1) {
                ans2 = min(cur_ans, ans2);
                count = 0;
                break;
            }
        }
        
    }
    cout << ans1 << " " << ans2;
    return 0;
}