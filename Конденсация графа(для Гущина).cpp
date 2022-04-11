#include <iostream>
#include <vector>

using namespace std;

int comp_num = 0;
vector<vector<int>> g, tg, condgr;
vector<int> tps, comp;
vector<bool> used;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    tps.emplace_back(v);
}

void dfs2(int v) {
    used[v] = true;
    comp[v] = comp_num;
    for (int u : tg[v]) {
        if (!used[u])
            dfs2(u);
        else if (comp[u] != comp[v]) {
            condgr[comp[v]].emplace_back(comp[u]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    tg.resize(n);
    tps.resize(n);
    comp.resize(n);
    used.resize(n);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        g[l - 1].emplace_back(r - 1);
        tg[r - 1].emplace_back(l - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i])
            dfs1(i);
    }
    reverse(tps.begin(), tps.end());
    used.assign(n, false);
    for (int v : tps) {
        if (!used[v]) {
            condgr.push_back(vector<int>{});
            dfs2(v);
            comp_num++;
        }
    }
    cout << endl << "Number of components: " << comp_num << endl;
    for (int i = 0; i < n; i++)
        cout << "Vertex " << i + 1 << " is in component number: " << comp[i] + 1 << endl;
    return 0;
}