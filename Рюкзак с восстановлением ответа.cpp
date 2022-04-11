#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

#pragma GCC_optimize("0fast");
#pragma GCC_optimize("fast_math");
#pragma GCC_optimize("03 unroll-no-loops");

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> w(n), c(n);
	vector<vector<int>> dp(n, vector<int>(m + 1)), anc(n, vector<int>(m + 1));
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	dp[0][0] = 0;
	if (w[0] <= m) {
		dp[0][w[0]] = c[0];
		anc[0][w[0]] = 1;
	}
	for (int i=1; i<n; i++)
		for (int j = 0; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			anc[i][j] = 0;
			if (j >= w[i] && dp[i - 1][j - w[i]] + c[i] > dp[i][j]) {
				dp[i][j] = dp[i - 1][j - w[i]] + c[i];
				anc[i][j] = 1;
			}
		}
	int pos = 0;
	for (int i = 0; i <= m; i++) {
		if (dp[n - 1][i] > dp[n - 1][pos])
			pos = i;
	}
	int cur_pr = n-1, cur_w = pos;
	vector<int> ans;
	while (cur_pr >= 0) {
		int par = anc[cur_pr][cur_w];
		if (par == 0) {
			cur_pr--;
		}
		else {
			ans.push_back(cur_pr + 1);
			cur_w -= w[cur_pr];
			cur_pr--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}
	return 0;
}