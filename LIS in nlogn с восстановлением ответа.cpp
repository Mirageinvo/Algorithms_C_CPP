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
	vector<int> dp(n, 1e9), ind(n, -1), anc(n, -1), ans;
	a[0] = a1;
	for (int i = 1; i < n; i++) {
		a[i] = (a[i - 1] * k + b) % m;
	}
	for (int i = 0; i < n; i++) {
		int x = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		dp[x] = a[i];
		ind[x] = i;
		if (x!=0)
			anc[i] = ind[x - 1];
	}
	int cur, len;
	for (int i = n-1; i >= 0; i--) {
		if (dp[i] != 1e9) {
			len = i;
			break;
		}
	}
	cur = ind[len];
	while (cur != -1) {
		ans.emplace_back(a[cur]);
		cur = anc[cur];
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";
	return 0;
}