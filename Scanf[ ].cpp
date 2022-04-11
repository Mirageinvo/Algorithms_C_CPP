#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	float a, b, c, ans;
	int n = scanf("%f%*[/ ]%f%*[/ ]%f", &a, &b, &c);
	if (n == 3) {
		ans = a + (b / c);
		printf("%.6f", ans);
	}
	else if (n == 2) {
		ans = a / b;
		printf("%.6f", ans);
	}
	else if (n == 1) {
		ans = a;
		printf("%.6f", ans);
	}
}