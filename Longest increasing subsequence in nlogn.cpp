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
	int n, a1, k, b, m;
	cin >> n >> a1 >> k >> b >> m;
	vector<int> a(n);
	vector<int> dp(n, 1e9);
	a[0] = a1;
	for (int i = 1; i < n; i++) {
		a[i] = (a[i - 1] * k + b) % m;
	}
	for (int i = 0; i < n; i++) {
		dp[lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin()] = a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] != 1e9) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}