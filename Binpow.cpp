#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll po(ll a, ll n, ll c) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	else {
		if (n % 2 == 0) {
			ll x = po(a, n / 2, c);
			return x % c * x % c;
		}
		else {
			ll x = po(a, n-1, c);
			return x * a % c;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	cout << po(a, b, c);
	return 0;
}