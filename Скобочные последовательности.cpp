#include <iostream>
#include <vector>
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
	int n;
	cin >> n;
	vector<vector<ll>> dp(n*2+1, vector<ll>(n*2+1));
	dp[0][0] = 1;
	for (int i = 1; i <= 2*n; i++) {
		for (int bal = 0; bal <=i; bal++) {
			if (bal == 0) {
				dp[i][bal] = dp[i - 1][bal + 1] % 1000000007;
			}
			else if (bal == i) {
				dp[i][bal] = dp[i - 1][bal - 1] % 1000000007;
			}
			else {
				dp[i][bal] = (dp[i - 1][bal - 1] + dp[i - 1][bal + 1]) % 1000000007;
			}
		}
	}
	cout << dp[n*2][0];
	return 0;
}