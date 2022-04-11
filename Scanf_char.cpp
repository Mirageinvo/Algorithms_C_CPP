#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a;
	char *c=(char*)malloc(10);
	scanf("%d%s", &a, c);
	cout << a << " " << c;
}