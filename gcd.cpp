#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[0] = gcd(a[0], a[i]);
	}
	cout << a[0];
	return 0;
}