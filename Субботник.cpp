#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;

ll n, r, c;
vector<ll> a;

ll f(ll x) {
	ll ans = 0;
	ll i = 0;
	ll count = 1;
	ll it = 1;
	while (i <= n-c) {
		while (count != c) {
			if (a[it] - a[i] <= x) {
				count++;
				it++;
			}
			else {
				i++;
				count--;
				break;
			}
		}
		if (count == c) {
			i = it;
			it = i + 1;
			ans++;
			count = 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> r >> c;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll l = -1;
	ll u = a[a.size() - 1]-a[0];
	while (u - l != 1) {
		ll m = l + (u - l) / 2;
		if (f(m) >= r)
			u = m;
		else {
			l = m;
		}
	}
	cout << u;
	return 0;
}