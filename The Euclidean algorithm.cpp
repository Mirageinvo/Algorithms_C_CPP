#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int gcd(int a, int b, int &x, int&y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c, x, y, k;
	bool signa = false, signb = false;
	cin >> a >> b >> c;
	if (a < 0) {
		signa = true;
		a *= -1;
	}
	if (b < 0) {
		signb = true;
		b *= -1;
	}
	k = gcd(a, b, x, y);
	if (signa) {
		a *= -1;
		x *= -1;
	}
	if (signb) {
		b *= -1;
		y *= -1;
	}
	if (c % k != 0) {
		cout << "Impossible";
		return 0;
	}
	x *= c / k;
	y *= c / k;
	printf("%d * %d + %d * %d = %d", a, x, b, y, c);
	return 0;
}