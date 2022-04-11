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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	vector<vector<int>> lea(1000), db(1000);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sq = sqrt(n);
	for (int i = 0; i < n; i++) {
		lea[i / sq].emplace_back(a[i]);
		db[i / sq].emplace_back(a[i]);
	}
	for (int i = 0; i <= (n - 1) / sq; i++)
		sort(lea[i].begin(), lea[i].end());
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, k;
		vector<int> ans;
		cin >> l >> r >> k;
		l--;
		r--;
		int num = r / sq - l / sq;
		int ln = l % sq;
		int rn = r % sq;
		if (num == 0) {
			for (int j = ln; j < ln + k; j++) {
				ans.emplace_back(lea[l / sq][j]);
			}
			sort(ans.begin(), ans.end());
			for (int j = 0; j < k; j++)
				cout << ans[j] << " ";
			continue;
		}
		for (int j = ln; j < sq; j++) {
			ans.emplace_back(db[l / sq][j]);
		}
		for (int j = 0; j <= rn; j++)
			ans.emplace_back(db[r / sq][j]);
		sort(ans.begin(), ans.end());
		int it = rn + sq - ln + 1;
		for (int j = l / sq + 1; j < r / sq; j++) {
			for (int h = 0; h < sq; h++) {
				ans.emplace_back(lea[j][h]);
			}
			inplace_merge(ans.begin(), ans.begin() + it, ans.end());
			it += sq;
		}
		for (int j = 0; j < k; j++)
			cout << ans[j] << " ";
	}
	/*int n, m, k = 0;
	vector<int> ans;
	cin >> n >> m;
	queue<int> a;
	vector<int> b(n);
	vector<queue<int>> pos();
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		a.push(t);
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];
		*/
	return 0;
}