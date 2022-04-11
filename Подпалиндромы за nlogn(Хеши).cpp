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

string s, s1;
int n;
ll ans = 0;
ll p = 101, m = 1000000321;
ll po[105000];
ll h[100001], h1[100001];

void start() {
	po[0] = 1;
	for (int i = 1; i < 105000; i++)
		po[i] = po[i - 1] * p % m;
	h[0] = s[0];
	h1[0] = s1[0];
	for (int i = 1; i < s.size(); i++)
		h[i] = (h[i - 1] * p + s[i]) % m;
	for (int i = 1; i < s1.size(); i++)
		h1[i] = (h1[i - 1] * p + s1[i]) % m;
}

ll gethash(ll h[100001], int l, int r) {
	if (l == 0)
		return h[r];
	else {
		return (h[r] - (h[l - 1] * po[r - l + 1] % m) + m) % m;
	}
}

bool f1(int g, int i) {
	if (gethash(h, i + 1, i + g) == gethash(h1, n - i, n - i - 1 + g))
		return true;
	return false;
}

bool f2(int g, int i) {
	if (gethash(h, i, i + g - 1) == gethash(h1, n - i, n - i - 1 + g))
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	s1 = s;
	n = s.size();
	reverse(s1.begin(), s1.end());
	start();
	ans += n;
	for (int i = 1; i < n-1; i++) {
		int r = min(i, n-i) + 1;
		int l = 0;
		while (r - l != 1) {
			int g = l + (r - l) / 2;
			if (f1(g, i))
				l = g;
			else {
				r = g;
			}
		}
		ans += l;
	}
	for (int i = 1; i <= n - 1; i++) {
		int r = min(i, n - i) + 1;
		int l = 0;
		while (r - l != 1) {
			int g = l + (r - l) / 2;
			if (f2(g, i))
				l = g;
			else {
				r = g;
			}
		}
		ans += l;
	}
	cout << ans;
	return 0;
}