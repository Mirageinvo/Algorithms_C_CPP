#include <iostream>
#include <vector>
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

const ld pi = 3.14159265358979323846;

vector<vector<int>> gr;
vector<bool> used;
vector<int> d;

int count(int v) {
    if (used[v])
        return d[v];
    else {
        used[v] = true;
        for (int u : gr[v]) {
            d[v] += count(u);
        }
        return d[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    s--;
    f--;
    gr.resize(n);
    used.resize(n);
    d.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        gr[u - 1].push_back(v - 1);
    }
    d[s] = 1;
    used[s] = true;
    cout << count(f);
    return 0;
}