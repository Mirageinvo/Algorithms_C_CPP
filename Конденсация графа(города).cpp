#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, p, c = 0;
vector<vector<int>> a;
vector<vector<int>> ra;
vector<vector<int>> vert;
vector<int> comp;
vector<int> tp;
vector<bool> used;

void dfsts(int u) {
	used[u] = true;
	for (ll v : a[u]) {
		if (!used[v])
			dfsts(v);
	}
	tp.emplace_back(u);
}

void dfsc(int u) {
	used[u] = true;
	comp[u] = c;
	for (int v : ra[u]) {
		if (!used[v]) {
			dfsc(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char ch;
	cin >> n >> p;
	ll ans[2001];
	for (int i = 0; i < 2001; i++)
		ans[i] = 0;
	a.resize(n);
	ra.resize(n);
	comp.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> ch;
			if (ch == '+') {
				a[i].emplace_back(j);
				ra[j].emplace_back(i);
			}
			else if (ch == '-') {
				a[j].emplace_back(i);
				ra[i].emplace_back(j);
			}
		}
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfsts(i);
	}
	reverse(tp.begin(), tp.end());
	used.assign(n, false);
	vert.resize(n);
	for (int i : tp) {
		if (!used[i]) {
			dfsc(i);
			c++;
		}
	}
	vert.resize(c);
	for (int i = 0; i < n; i++)
		vert[comp[i]].emplace_back(i);
	ll k = vert[0].size();
	if (vert[0].size() == n) {
		cout << k << endl;
		return 0;
	}
	else{
		for (int i = 1; i < c; i++) {
			if (i == 1 && k==1 && vert[i].size() == 1)
				continue;
			ll inc = 0;
			for (int j = i; j >= 1; j--)
				inc += vert[j].size();
			ans[inc] = k * vert[i].size();
		}
		cout << k << endl;
		for (int i = 1; i <= n-k ; i++) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}