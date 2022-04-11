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

int get_anc(int v) {
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
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(n);
    d.resize(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        d[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int l, k;
        cin >> l >> k;
        if (get_anc(l)!=get_anc(k)) {
            unite(l, k);
            count++;
        }
        if (count == n - 1) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}