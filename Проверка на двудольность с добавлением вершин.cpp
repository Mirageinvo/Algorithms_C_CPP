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

vector<vector<int>> gr;
vector<int> c;
vector<bool> used;
bool bad = false;

void dfs(int v, int col) {
    if (bad)
        return;
    used[v] = true;
    c[v] = col;
    for (int u : gr[v]) {
        if (!used[u])
            dfs(u, 3 - col);
        else if (c[u] == col)
            bad = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    c.resize(n);
    used.resize(n);
    vector<int> ans;
    vector<int> vert;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        gr[v - 1].push_back(u - 1);
        gr[u - 1].push_back(v - 1);
        vert.push_back(u - 1);
        vert.push_back(v - 1);
        if (bad)
            ans.emplace_back(0);
        else {
            for (int j : vert) {
                if (!used[j])
                    dfs(j, 1);
            }
            if (bad)
                ans.emplace_back(0);
            else {
                ans.emplace_back(1);
            }
            used.assign(n, false);
        }
    }
    for (int h : ans)
        cout << h;
    return 0;
}