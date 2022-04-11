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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> dp(n);
	vector<int> anc(n, -1);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		anc[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					anc[i] = j;
				}
		}
	}
	int ansk = 0;
	int cur;
	vector<int> ans;
	for (int i = 0; i < n; i++)
		if (dp[i] > ansk) {
			ansk = dp[i];
			cur = i;
		}
	if (anc[cur] == -1) {
		cout << a[cur];
		return 0;
	}
	while (cur!=-1) {
		ans.emplace_back(a[cur]);
		cur = anc[cur];
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";
	return 0;
}