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
bool cycle = false;
vector<vector<int>> a;
vector<int> tin, tout;
vector<int> used;

void dfs(int u) {
	used[u] = 1;
	tin[u] = timer++;
	for (int v : a[u]) {
		if (used[v]==0)
			dfs(v);
		else if (used[v]==1) {
			cycle = true;
		}
	}
	used[u] = 2;
	tout[u] = timer++;
}

inline bool cmp(int u, int v) {
	return tout[u] > tout[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
	}
	for (int i = 0; i < n; i++) {
		if (used[i]==0)
			dfs(i);
		if (cycle) {
			cout << "No";
			return 0;
		}
	}
	vector<int> topsort(n);
	iota(topsort.begin(), topsort.end(), 0);  //fill topsort with numbers 1, 2, 3, 4, 5, ..., n
	sort(topsort.begin(), topsort.end(), cmp);
	cout << "Yes" << endl;
	for (int i : topsort)
		cout << i + 1 << " ";
	return 0;
}