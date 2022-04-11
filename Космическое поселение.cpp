#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;

ll n, a, b, w, h;

ll f(ll x) {
	return max((max(h, w) / (max(a, b) + 2 * x)) * (min(h, w) / (min(a, b) + 2 * x)), (max(h, w) / (min(a, b) + 2 * x)) * (min(h, w) / (max(a, b) + 2 * x)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> b >> w >> h;
	ll l = -1;
	ll r = pow(10, 18)+1;
	while (r - l != 1) {
		ll m = l + (r - l) / 2;
		if (f(m) >= n)
			l = m;
		else {
			r = m;
		}
	}
	cout << l;
	return 0;
}