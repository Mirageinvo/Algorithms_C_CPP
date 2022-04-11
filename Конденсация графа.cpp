#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int comp = 0;
vector<vector<int>> a, ra, newe;
vector<int> cg, tps;
vector<bool> used;

void dfs1(int u) {
	used[u] = true;
	for (int v : a[u])
		if (!used[v])
			dfs1(v);
	tps.emplace_back(u);
}

void dfsc(int u) {
	used[u] = true;
	cg[u] = comp;
	for (int v : ra[u]) {
		if (!used[v])
			dfsc(v);
		else if (cg[v] != cg[u]) {
			newe[cg[v]].emplace_back(cg[u]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	a.resize(n);
	ra.resize(n);
	cg.resize(n);
	tps.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int l, g;
		cin >> l >> g;
		a[l - 1].emplace_back(g - 1);
		ra[g - 1].emplace_back(l - 1);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	reverse(tps.begin(), tps.end());
	used.assign(n, false);
	for (int i : tps) {
		if (!used[i]) {
			newe.push_back(vector<int>{});
			dfsc(i);
			comp++;
		}
	}
	cout << comp << endl;
	for (int i = 0; i < n; i++)
		cout << cg[i] + 1 << " ";
	return 0;
}