#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(n + 1, vector<int>(k));
	dp[1][1] = 2;
	for (int i = 2; i < k; i++) {
		dp[1][i] = 0;
	}
	for (int i=2; i<n+1; i++)
		for (int j = 1; j < k && j<=n; j++) {
			if (j == 1) {
				for (int t = 1; t < k && t <= n; t++) {
					dp[i][j] += dp[i - 1][t];
				}
				continue;
			}
			dp[i][j] = dp[i - 1][j - 1];
		}
	int ans = 0;
	for (int i = 1; i < k; i++)
		ans += dp[n][i];
	cout << ans;
	return 0;
}