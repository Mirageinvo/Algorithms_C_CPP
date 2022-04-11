#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, m, timer;
vector<vector<int>> a;
vector<int> tin, tout;
vector<bool> used;

void dfs(int u) {
	used[u] = true;
	tin[u] = timer++;
	for (int v : a[u]) {
		if (!used[v])
			dfs(v);
	}
	tout[u] = timer++;
}

inline bool cmp(int u, int v) {
	return tout[u] > tout[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> edges;
	timer = 0;
	cin >> n >> m;
	a.resize(n);
	tin.resize(n);
	tout.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int k, l;
		cin >> k >> l;
		a[k-1].emplace_back(l-1);
		edges.push_back({ k - 1, l - 1 });
	}
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs(i);
	}
	vector<int> topsort(n);
	vector<int> pos(n);
	iota(topsort.begin(), topsort.end(), 0);  //fill topsort with numbers 1, 2, 3, 4, 5, ..., n
	sort(topsort.begin(), topsort.end(), cmp);
	for (int i = 0; i < n; i++)
		pos[topsort[i]] = i;
	for (auto& g : edges) {
		if (pos[g.first] > pos[g.second]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int i : topsort)
		cout << i + 1 << " ";
	return 0;
}