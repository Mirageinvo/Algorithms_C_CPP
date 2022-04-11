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

vector<ll> h;
ll po[100005];
ll p = 173, m=1000000321;


bool gethash(int l1, int r1, int l2, int r2) {
	ll num1, num2;
	if (l1 == 0) {
		num1 = h[r1];
	}
	else {
		num1 = (h[r1] - ((h[l1 - 1] * po[r1 - l1 + 1]) % m) + m) % m;
	}
	if (l2 == 0) {
		num2 = h[r2];
	}
	else {
		num2 = (h[r2] - ((h[l2 - 1] * po[r2 - l2 + 1]) % m) + m) % m;
	}
	return num1 == num2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int q, l1, l2, r1, r2;
	cin>>s;
	h.resize(s.size());
	po[0] = 1;
	for (int i = 1; i < 100005; i++)
		po[i] = (po[i - 1] * p) % m;
	h[0] = s[0];
	for (int i = 1; i < s.size(); i++) {
		h[i] = (h[i - 1] * p + s[i]) % m;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l1 >> r1 >> l2 >> r2;
		l1--;
		r1--;
		l2--;
		r2--;
		if (gethash(l1, r1, l2, r2))
			cout << "+";
		else {
			cout << "-";
		}
	}
	return 0;
}