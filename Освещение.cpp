/*#include <iostream>
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


int n;
vector<vector<int>> gr;
vector<int> cost, ans, to;
vector<vector<ll>> dp;

void dfs(int v, int p = -1) {
    for (int u : gr[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    dp[v][0] = 0;
    dp[v][1] = cost[v];
    ll sum = 0;
    for (int u : gr[v]) {
        if (u != p) {
            dp[v][0] += dp[u][1];
            sum += min(dp[u][0], dp[u][1]);
        }
    }
    int pos=-1;
    for (int u : gr[v]) {
        if (u != p) {
            pos = u;
            break;
        }
    }
    if (pos != -1) {
        dp[v][1] += dp[pos][0] + sum - min(dp[pos][0], dp[pos][1]);
        for (int u : gr[v]) {
            if (u != p)
                dp[v][1] = min(dp[v][1], cost[v] + dp[u][0] + sum - min(dp[u][0], dp[u][1]));
        }
    }
}

void ldfs(int v, int type, int p = -1) {
    if (type == 0) {
        for (int u : gr[v]) {
            if (u != p)
                ldfs(u, 1, v);
        }
    }
    else if (type == 1){
        ans.push_back(v);
        for (int u : gr[v]) {
            if (u != p) {
                if (dp[u][0] < dp[u][1]) {
                    ldfs(u, 0, v);
                }
                else {
                    ldfs(u, 1, v);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    gr.resize(n);
    cost.resize(n);
    to.resize(n);
    dp.resize(n, vector<ll>(2));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    if (n == 1) {
        cout << cost[0] << " " << 1 << endl << 1;
        return 0;
    }
    dfs(0);
    if (dp[0][0] < dp[0][1]) {
        ldfs(0, 0);
    }
    else {
        ldfs(0, 1);
    }
    sort(ans.begin(), ans.end());
    cout << min(dp[0][0], dp[0][1]) << " " << ans.size() << endl;
    for (int u : ans)
        cout << u + 1 << " ";
    return 0;
}*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<long long> f0, f1;
vector<vector<int>> g;
vector<int> cost;
vector<int> ans;
long long total_cost = 0;

void dfs(int u, int parent)
{
    f0[u] = 0;
    f1[u] = cost[u];
    for (auto v : g[u]) {
        if (v != parent) {
            dfs(v, u);
            f0[u] += f1[v];
            f1[u] += min(f1[v], f0[v]);
        }
    }
}

void restore(int u, int parent, bool used)
{
    if (used) {
        ans.push_back(u);
        total_cost += cost[u];
    }
    for (auto v : g[u]) {
        if (v != parent) {
            if (used && f0[v] < f1[v])
                restore(v, u, false);
            else
                restore(v, u, true);
        }
    }
}

int main()
{
    cin >> n;
    g.resize(n + 1);
    f0.resize(n + 1);
    f1.resize(n + 1);
    cost.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        cin >> cost[i];
    dfs(1, 0);
    if ((f0[1] < f1[1]) && n > 1)
        restore(1, 0, false);
    else
        restore(1, 0, true);
    cout << total_cost << " " << ans.size() << endl;
    for (auto u : ans)
        cout << u << " ";
    cout << endl;
}