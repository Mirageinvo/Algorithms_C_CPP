#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll timer = 0;
vector<ll> ans;
vector<ll> c;
vector<bool> used(false);
vector<vector<ll>> d;

void dfs(ll u) {
	used[u] = true;
	timer += c[u];
	for (ll v : d[u]) {
		if (!used[v]) {
			dfs(v);
		}
	}
	ans.emplace_back(u + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k, det;
	cin >> n;
	c.resize(n);
	d.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> det;
			d[i].emplace_back(det - 1);
		}
	}
	dfs(0);
	cout << timer << " " << ans.size() << endl;
	for (ll& h : ans)
		cout << h << " ";
	return 0;
}