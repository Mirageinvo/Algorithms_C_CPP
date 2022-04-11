#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<vector<int>> gr;
vector<int> d, dp;
vector<int> ans;
vector<bool> used;

void dfs(int u, int p=-1) {
	used[u] = true;
	int power = 0;
	bool is_cutpoint = false;
	if (p == -1)
		d[u] = 0;
	else {
		d[u] = d[p] + 1;
	}
	dp[u] = d[u];
	for (int v : gr[u]) {
		if (!used[v]) {
			dfs(v, u);
			if (p!=-1 && dp[v] >= d[u])
				is_cutpoint = true;
			dp[u] = min(dp[u], dp[v]);
			power++;
		}
		else if (v!=p){
			dp[u] = min(dp[u], d[v]);
		}
	}
	if (p == -1 && power >= 2) {
		is_cutpoint = true;
	}
	if (is_cutpoint)
		ans.emplace_back(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	gr.resize(n);
	d.resize(n);
	dp.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int l, k;
		cin >> l >> k;
		gr[l - 1].emplace_back(k - 1);
		gr[k - 1].emplace_back(l - 1);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs(i);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i : ans)
		cout << i + 1 << endl;
	return 0;
}