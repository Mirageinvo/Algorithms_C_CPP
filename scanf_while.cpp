#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int sum, d;
	sum = 0;
	scanf("%d", &d);
	sum = d;
	while (scanf(",%d", &d)==1) {
		sum += d;
	}
	cout << sum;
}