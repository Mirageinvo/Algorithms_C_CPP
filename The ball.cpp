#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<ll> dp(n+1);
	if (n == 1) {
		cout << 1;
		return 0;
	}
	dp[n] = 1;
	dp[n - 1] = 1;
	dp[n - 2] = 2;
	for (int i = n-3; i >= 0; i--) {
		dp[i] = dp[i + 1] + dp[i + 2] + dp[i + 3];
	}
	cout << dp[0];
	return 0;
}