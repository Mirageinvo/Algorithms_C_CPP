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
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
	for (int i = 2; i <= k; i++) {
		dp[1][i] = 0;
		dp[2][i] = 0;
	}
	for (int i=1; i<=n; i++)
		dp[i][1] = 1;
	for (int i=3; i<=n; i++)
		for (int j = 2; j <= k; j++) {
			for (int h = i - 2; h >= 1; h--) {
				dp[i][j] += dp[h][j - 1] * (i - h - 1);
			}
		}
	cout << dp[n][k];
	return 0;
}