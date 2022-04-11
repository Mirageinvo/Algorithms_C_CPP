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
	vector<vector<int>> dp(n + 1, vector<int>(11));
	for (int i=1; i<10; i++)
		dp[1][i] = 1;
	dp[1][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int num = 0; num < 10; num++) {
			if (num<=8)
				dp[i + 1][num + 1] += dp[i][num];
			if (num>=1)
				dp[i + 1][num - 1] += dp[i][num];
			dp[i + 1][num] += dp[i][num];
		}
	}
	ll sum = 0;
	for (int h = 0; h < 10; h++)
		sum += dp[n][h];
	cout << sum;
	return 0;
}