#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<vector<int>> a;
vector<bool> visited(false);

void dfs(int u) {
	for (int v : a[u]) {
		if (!visited[v]) {
			visited[v] = true;
			dfs(v);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, start;
	cin >> n;
	a.resize(n);
	visited.resize(n);
	for (int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> k;
			if (k) {
				a[i].emplace_back(j);
				start = i;
			}
		}
	dfs(start);
	for (bool h: visited)
		if (!h) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}