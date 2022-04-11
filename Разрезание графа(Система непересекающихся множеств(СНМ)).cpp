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

const int INF = 1e9;
vector<int> p, d;

/*int get_anc(int v) {
    if (p[v] == v)
        return v;
    return p[v]=get_anc(p[v]);
}

void unite(int v, int u) {
    v = get_anc(v);
    u = get_anc(u);
    if (u != v) {
        if (d[u] > d[v]) {
            swap(u, v);
        }
        p[u] = v;
        if (d[u] == d[v])
            d[v]++;
    }
}*/
int get_anc(int v) {
    if (p[v] == v)
        return v;
    return p[v] = get_anc(p[v]);
}

void unite(int v, int u) {
    u = get_anc(u);
    v = get_anc(v);
    if (u != v) {
        if (d[v] > d[u])
            swap(v, u);
        p[v] = u;
        if (d[v] == d[u])
            d[u]++;
    }
}

void init(int n) {
    p.resize(n);
    d.resize(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        d[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    init(n);
    for (int i = 0; i < m; i++) {
        int x1, y1;
        cin >> x1 >> y1;
    }
    vector<pair<string, pair<int, int>>> q(k);
    for (int i = 0; i < k; i++) {
        string word;
        int x, y;
        cin >> word >> x >> y;
        q[i] = { word, {x - 1, y - 1} };
    }
    reverse(q.begin(), q.end());
    vector<string> ans;
    for (auto& qu : q) {
        if (qu.first == "ask") {
            if (get_anc(qu.second.first) == get_anc(qu.second.second))
                ans.push_back("YES");
            else {
                ans.push_back("NO");
            }
        }
        else {
            unite(qu.second.first, qu.second.second);
        }
    }
    reverse(ans.begin(), ans.end());
    for (string h : ans)
        cout << h << endl;
    return 0;
}