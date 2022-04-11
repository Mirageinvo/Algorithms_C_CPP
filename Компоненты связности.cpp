#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void dfs(int start, vector<bool>& visited, vector<vector<int>>& comp, const vector<vector<int>>& g) {
    int n = g.size();
    comp.back().push_back(start);
    visited[start] = true;
    for (auto end : g[start])
    {
        if (!visited[end])
            dfs(end, visited, comp, g);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector<int> > g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> comp;
    vector<bool> visited(n);
    for (int i = 0; i < n; ++i)
        if (!visited[i]){
            comp.resize(comp.size() + 1);
            dfs(i, visited, comp, g);
        }
    cout << comp.size() << endl;
    for (auto& single_comp : comp) {
        cout << single_comp.size() << endl;
        for (auto elem : single_comp)
            cout << elem + 1 << " ";
        cout << endl;
    }
	return 0;
}