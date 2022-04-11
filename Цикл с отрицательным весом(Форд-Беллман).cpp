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
	int n;
	cin >> n;
	vector<vector<int>> edges;
	vector<int> d(n, INF), p(n, -1);
	d[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int r;
			cin >> r;
			if (r!=100000)
				edges.push_back({ i, j, r });
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (vector<int>& edge : edges) {
			if (d[edge[1]] > d[edge[0]] + edge[2]) {
				d[edge[1]] = d[edge[0]] + edge[2];
				p[edge[1]] = edge[0];
			}
		}
	}
	vector<int> newd = d;
	for (vector<int>& edge : edges) {
		if (newd[edge[1]] > newd[edge[0]] + edge[2]) {
			newd[edge[1]] = newd[edge[0]] + edge[2];
			p[edge[1]] = edge[0];
		}
	}
	int cur = -1;
	for (int i = 0; i < n; i++) {
		if (newd[i] != d[i]) {
			cur = i;
			break;
		}
	}
	if (cur == -1)
		cout << "NO";
	else {
		vector<int> a, ans;
		vector<bool> used(n, false);
		int start;
		while (true) {
			a.push_back(cur);
			if (used[cur]) {
				for (size_t i = 0; i < a.size(); i++)
					if (a[i] == cur) {
						start = i;
						break;
					}
				break;
			}
			used[cur] = true;
			cur = p[cur];
		}
		for (size_t i = start; i < a.size(); i++) {
			ans.push_back(a[i]);
		}
		cout << "YES" << endl;
		reverse(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i : ans)
			cout << i + 1 << " ";
	}
	return 0;
}