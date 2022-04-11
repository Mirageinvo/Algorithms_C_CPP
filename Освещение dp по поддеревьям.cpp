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

int n;
vector<int> w, anss;
vector<vector<vector<pair<int, int>>>> anc;
vector<vector<int>> gr, dp;

void dfs(int v, int p = -1) {
    for (int u : gr[v]) {
        if (u == p)
            continue;
        dfs(u, v);
    }
    dp[v][0] = 0;
    dp[v][1] = w[v];
    //добавить себя
    for (int u : gr[v]) {
        if (u == p)
            continue;
        dp[v][0] += dp[u][1];
        anc[v][0].push_back({ u, 1 });
        if (dp[u][0] > dp[u][1]) {
            dp[v][1] += dp[u][1];
            anc[v][1].push_back({ u, 1 });
        }
        else {
            dp[v][1] += dp[u][0];
            anc[v][1].push_back({ u, 0 });
        }
    }
}

void last(pair<int, int> p) {
    if (p.second == 1)
        anss.push_back(p.first + 1);
    for (auto& u : anc[p.first][p.second])
        last(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    w.resize(n);
    anc.resize(n, vector<vector<pair<int, int>>>(2));
    gr.resize(n);
    dp.resize(n, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        gr[u].emplace_back(v);
        gr[v].emplace_back(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    if (n == 1) {
        cout << w[0] << " " << 1 << endl;
        cout << 1;
        return 0;
    }
    dfs(0);
    if (dp[0][0] < dp[0][1]) {
        last({ 0, 0 });
        cout << dp[0][0] << " ";
    }
    else {
        last({ 0, 1 });
        cout << dp[0][1] << " ";
    }
    cout << anss.size() << endl;
    sort(anss.begin(), anss.end());
    for (int v : anss)
        cout << v << " ";
    return 0;
}