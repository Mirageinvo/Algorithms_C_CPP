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

ll h1[31000];
ll h2[31000];
ll po[35000];
ll p = 173, m=1000000321;
string s1, s2;

void initial() {
	po[0] = 1;
	for (int i = 1; i < 35000; i++)
		po[i] = (po[i - 1] * p) % m;
	if (s1 > s2)
		swap(s1, s2);
	h1[0] = s1[0];
	h2[0] = s2[0];
	for (int i = 1; i < s1.size(); i++) {
		h1[i] = (h1[i - 1] * p + s1[i]) % m;
	}
	for (int i = 1; i < s2.size(); i++) {
		h2[i] = (h2[i - 1] * p + s2[i]) % m;
	}
}

ll gethash(ll h[35000], ll l1, ll r1) {
	if (l1 == 0) {
		return h[r1];
	}
	else {
		return (h[r1] - ((h[l1 - 1] * po[r1 - l1 + 1]) % m) + m) % m;
	}
}

bool f(ll y) {
	set<ll> a;
	for (ll i = 0; i + y <= s2.size(); i++) {
		a.insert(gethash(h2, i, i + y - 1));
	}
	for (ll i = 0; i + y <= s1.size(); i++) {
		if (a.find(gethash(h1, i, i + y - 1)) != a.end())
			return true;
	}
	a.erase(a.begin(), a.end());
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s1;
	cin >> s2;
	if (s1 == s2) {
		cout << s1.size();
		return 0;
	}
	initial();
	ll l = 0;
	ll r = s1.size() + 1;
	while (r - l != 1) {
		ll y = l + (r - l) / 2;
		if (!f(y))
			r = y;
		else {
			l = y;
		}
	}
	cout << l;
	return 0;
}