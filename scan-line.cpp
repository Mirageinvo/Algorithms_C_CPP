#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> a;
	for (int i = 0; i < n; i ++) {
		int l, r;
		cin >> l >> r;
		a.emplace_back(make_tuple(min(l, r), -1, i));
		a.emplace_back(make_tuple(max(l, r), 1, i));
	}
	for (int i = 0; i < m; i++) {
		int u;
		cin >> u;
		a.emplace_back(make_tuple(u, 0, i));
	}
	sort(a.begin(), a.end());
	int counter = 0;
	vector<int> ans(m);
	for (int i = 0; i < a.size(); i++) {
		int type = get<1>(a[i]);
		int y = get<2>(a[i]);
		counter -= type;
		if (type == 0)
			ans[y] = counter;
	}
	for (int f : ans)
		cout << f << " ";
	return 0;
}