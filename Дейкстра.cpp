#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <tuple>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, s, f, a;
	ll dist[150];
	bool proc[150];
	cin >> n >> s >> f;
	vector<vector<pair<ll, ll>>> v(n + 1);
	priority_queue<pair<ll, ll>> q;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++) {
			cin >> a;
			if (a != -1 && i != j)
				v[i].push_back(make_pair(j, a));
		}
	for (int i = 1; i < n + 1; i++) {
		dist[i] = 1e9;
		proc[i] = false;
	}
	dist[s] = 0;
	q.push({ 0, s });
	while (!q.empty()) {
		int a = q.top().second;
		q.pop();
		if (proc[a]) continue;
		proc[a] = true;
		for (auto u : v[a]) {
			int b = u.first, w = u.second;
			if (dist[a] + w < dist[b]) {
				dist[b] = dist[a] + w;
				q.push({ -dist[b], b });
			}
		}
	}
	if (dist[f] != 1e9)
		cout << dist[f];
	else { cout << -1; }
	return 0;
}