#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, s, f;
	cin >> n >> s >> f;
	s--;
	f--;
	vector<int> d(n, INF);
	vector<int> anc(n, -1);
	vector<vector<pair<int, int>>> gr(n);
	vector<bool> used(n, false);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int l;
			cin >> l;
			if (l > 0)
				gr[i].push_back({j, l});
		}
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!used[j] && d[j] != INF) {
				if (v == -1 || d[v] > d[j]) {
					v = j;
				}
			}
		}
		if (v == -1) {
			break;
		}
		used[v] = true;
		for (auto& u : gr[v]) {
			if (d[u.first] > d[v] + u.second) {
				d[u.first] = d[v] + u.second;
				anc[u.first] = v;
			}
		}
	}
	if (d[f] == INF) {
		cout << -1;
		return 0;
	}
	int cur = f;
	vector<int> ans;
	ans.emplace_back(f);
	while (anc[cur] != -1) {
		ans.emplace_back(anc[cur]);
		cur = anc[cur];
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i + 1 << " ";
	return 0;
}