#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct Edge {
	int num, to;
	bool is_bridge;
	Edge* back;
	//Edge(){}
	Edge(int to, int num) : to(to), num(num), is_bridge(false){}
};

int comp = 0;
vector<vector<Edge*>> gr;
vector<vector<int>> c;
vector<bool> used;
vector<int> d, dp;

void dfs(int u, Edge* p=nullptr) {
	used[u] = true;
	if (p == nullptr)
		d[u] = 0;
	else {
		d[u] = d[p->back->to] + 1;
	}
	dp[u] = d[u];
	for (auto& e : gr[u]) {
		if (!used[e->to]) {
			dfs(e->to, e);
			dp[u] = min(dp[u], dp[e->to]);
		}
		else if (p && e != p->back) {
			dp[u] = min(dp[u], d[e->to]);
		}
	}
	if (d[u] == dp[u]) {
		if (p) {
			p->is_bridge = true;
			p->back->is_bridge = true;
		}
	}
}

void dfsc(int u) {
	used[u] = true;
	c[comp].emplace_back(u);
	for (auto& e : gr[u]) {
		if (e->is_bridge)
			continue;
		if (!used[e->to]){
			dfsc(e->to);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, l, k;
	cin >> n >> m;
	gr.resize(n);
	used.resize(n);
	d.resize(n);
	dp.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> l >> k;
		Edge* a = new Edge(l - 1, i);
		Edge* b = new Edge(k - 1, i);
		a->back = b;
		b->back = a;
		gr[k - 1].emplace_back(a);
		gr[l - 1].emplace_back(b);
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);
	used.assign(n, false);
	for (int i=0; i<n; i++)
		if (!used[i]) {
			c.push_back(vector<int>{});
			dfsc(i);
			sort(c[comp].begin(), c[comp].end());
			comp++;
		}
	cout << comp << endl;
	for (int i = 0; i < comp; i++) {
		for (int h : c[i])
			cout << h + 1 << " ";
		cout << endl;
	}
	return 0;
}