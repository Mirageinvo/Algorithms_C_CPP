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
	int n, m;
	cin >> n;
	vector<int> gas(n);
	vector<int> d(3 * n, INF);
	vector<bool> used(3 * n, false);
	d[0] = 0;
	vector<vector<pair<int, int>>> gr(3*n);
	for (int i = 0; i < n; i++)
		cin >> gas[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, k;
		cin >> l >> k;
		l--;
		k--;
		gr[3 * l + 1].push_back({ 3 * k, 0 });
		gr[3 * l + 2].push_back({ 3 * k + 1, 0 });
		gr[3 * k + 1].push_back({ 3 * l, 0 });
		gr[3 * k + 2].push_back({ 3 * l + 1, 0 });
	}
	for (int i = 0; i < n; i++) {
		gr[3 * i].push_back({ 3 * i + 1, gas[i] });
		gr[3 * i + 1].push_back({ 3 * i + 2, gas[i] });
	}
	for (int i = 0; i < 3 * n; i++) {
		int v = -1;
		for (int j = 0; j < 3 * n; j++) {
			if (!used[j] && d[j] != INF) {
				if (v == -1 || d[j] < d[v]) {
					v = j;
				}
			}
		}
		if (v == -1)
			break;
		used[v] = true;
		for (auto& u : gr[v]) {
			if (d[u.first] > d[v] + u.second) {
				d[u.first] = d[v] + u.second;
			}
		}
	}
	if (d[3 * (n - 1)] == INF) {
		cout << -1;
		return 0;
	}
	cout << d[3 * (n - 1)];
	return 0;
}