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
	cin >> n >> m;
	vector<int> d(n, INF);
	vector<pair<pair<int, int>, int>> gr(m);
	for (int i = 0; i < m; i++) {
		int s, f, w;
		cin >> s >> f >> w;
		gr[i] = { {s - 1, f - 1}, w };
	}
	d[0] = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			if (d[gr[j].first.first]!=INF && d[gr[j].first.second] > d[gr[j].first.first] + gr[j].second) {
				d[gr[j].first.second] = d[gr[j].first.first] + gr[j].second;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == INF)
			cout << 30000 << " ";
		else {
			cout << d[i] << " ";
		}
	}
	return 0;
}