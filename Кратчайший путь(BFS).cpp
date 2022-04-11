#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, s, f;
	cin >> n >> m;
	cin >> s >> f;
	queue<int> q;
	vector<vector<int>> gr(n);
	vector<int> mindist(n, INF);
	vector<int> anc(n, -1);
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int l, k;
		cin >> l >> k;
		gr[l - 1].emplace_back(k - 1);
		gr[k - 1].emplace_back(l - 1);
	}
	q.push(s-1);
	mindist[s-1] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : gr[v]) {
			if (mindist[v] + 1 < mindist[u]) {
				mindist[u] = mindist[v] + 1;
				anc[u] = v;
				q.push(u);
			}
		}
	}
	int cur = f - 1;
	ans.emplace_back(f - 1);
	while (anc[cur] != -1) {
		ans.emplace_back(anc[cur]);
		cur = anc[cur];
	}
	reverse(ans.begin(), ans.end());
	if (mindist[f - 1] == INF) {
		cout << -1;
		return 0;
	}
	cout << mindist[f - 1] << endl;
	for (int i : ans)
		cout << i + 1 << " ";
	return 0;
}