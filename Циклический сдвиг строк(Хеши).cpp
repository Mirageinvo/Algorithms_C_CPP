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

string s1, s2;
ll p = 101, m = 1000000321;
ll po[105000];
ll h1[100001], h2[100001];

void start() {
	po[0] = 1;
	for (int i = 1; i < 105000; i++)
		po[i] = po[i - 1] * p % m;
	h1[0] = s1[0];
	h2[0] = s2[0];
	for (int i = 1; i < s1.size(); i++)
		h1[i] = (h1[i - 1] * p + s1[i]) % m;
	for (int i = 1; i < s2.size(); i++)
		h2[i] = (h2[i - 1] * p + s2[i]) % m;
}

ll gethash(ll h[100001], int l, int r) {
	if (l == 0)
		return h[r];
	else {
		return (h[r] - (h[l - 1] * po[r - l + 1] % m) + m) % m;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s1;
	cin >> s2;
	if (s1 == s2) {
		cout << 0;
		return 0;
	}
	start();
	int n = s2.size();
	for (int ans = 1; ans < n; ans++) {
		if (gethash(h2, 0, ans-1) == gethash(h1, n - ans, n - 1) && gethash(h2, ans, n - 1) == gethash(h1, 0, n - ans - 1)) {
			cout << ans;
			return 0;
		}
	}
	cout << -1;
	return 0;
}