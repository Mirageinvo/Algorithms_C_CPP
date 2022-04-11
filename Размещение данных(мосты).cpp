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
	int to, num;
	bool is_bridge;
	Edge* back;
	Edge(int to, int num) : to(to), num(num), is_bridge(false) {}
};

vector<vector<Edge*>> gr;
vector<vector<int>> newgr;
vector<bool> used;
vector<int> d, dp, compsize, vertcomp, compways;
int comp = 0, br = 0;
 
void dfs(int u, Edge* p = nullptr) {
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
		else if (p && e->back != p) {
			dp[u] = min(dp[u], d[e->to]);
		}
	}
	if (dp[u] == d[u])
		if (p) {
			p->is_bridge = true;
			p->back->is_bridge = true;
			br++;
		}
}

void dfsc(int u, Edge* p = nullptr) {
	used[u] = true;
	compsize[comp]++;
	vertcomp[u] = comp;
	for (auto& e : gr[u]) {
		if (!used[e->to]) {
			if (!e->is_bridge) {
				dfsc(e->to, e);
			}
		}
		else if (e->is_bridge) {
			compways[comp]++;
			compways[vertcomp[e->to]]++;
			/*newgr[comp].emplace_back(vertcomp[e->to]);
			newgr[vertcomp[e->to]].emplace_back(comp);*/
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	used.resize(n);
	d.resize(n);
	dp.resize(n);
	gr.resize(n);
	vertcomp.resize(n);
	for (int i = 0; i < m; i++) {
		int l, k;
		cin >> l >> k;
		Edge* a = new Edge(l - 1, i);
		Edge* b = new Edge(k - 1, i);
		a->back = b;
		b->back = a;
		gr[l - 1].push_back(b);
		gr[k - 1].push_back(a);
	}
	dfs(0);
	used.assign(n, false);
	newgr.resize(br + 1);
	compsize.resize(br + 1);
	compways.resize(br + 1);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfsc(i);
			comp++;
		}
	}
	ll ans1 = 0, ans2 = 1;
	for (int i = 0; i < comp; i++) {
		if (compways[i] == 1) {
			ans1++;
			ans2 *= compsize[i];
			ans2 %= 1000000007;
		}
	}
	if (ans1 == 0) {
		ans1 = 1;
		ans2 = compsize[0];
	}
	cout << ans1 << " " << ans2;
	return 0;
}