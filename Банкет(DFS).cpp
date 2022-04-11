#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<vector<int>> a;
vector<int> color;
vector<int> visited(false);
bool bad = false;

void dfs(int u, int col) {
	visited[u] = true;
	color[u] = col;
	if (bad)
		return;
	for (int v : a[u]) {
		if (!visited[v]) {
			dfs(v, 3 - col);
		}
		else if (color[v]==col) {
			bad = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, start;
	cin >> n >> m;
	a.resize(n);
	color.resize(n);
	visited.resize(n);
	for (int i = 0; i < m; i++) {
		int k, l;
		cin >> k >> l;
		k--;
		l--;
		a[k].emplace_back(l);
		a[l].emplace_back(k);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, 1);
		}
	}
	if (bad)
		cout << "NO";
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
			if (color[i] == 1)
				cout << i + 1 << " ";
	}
	return 0;
}