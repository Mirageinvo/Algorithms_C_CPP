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

int n, k;
vector<int> a;
const int SIZE = 100010;
int t[SIZE * 4];

void build(int v, int l, int r) {
	if (r - l == 1) {
		if (a[l] == 0) {
			t[v] = 1;
			return;
		}
		else {
			t[v] = 0;
			return;
		}
	}
	int m = l + (r - l) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int ask(int v, int l, int r, int al, int ar) {
	if (r <= al || l >= ar)
		return 0;
	if (l >= al && r <= ar)
		return t[v];
	int m = l + (r - l) / 2;
	return ask(v * 2 + 1, l, m, al, ar) + ask(v * 2 + 2, m, r, al, ar);
}

void change(int v, int l, int r, int ind, int val) {
	if (r - l == 1) {
		if (val == 1) {
			t[v] = 0;
			a[l] = 1;
		}
		else {
			t[v] = 1;
			a[l] = 0;
		}
		return;
	}
	int m = l + (r - l) / 2;
	if (ind >= m) {
		change(v * 2 + 2, m, r, ind, val);
	}
	else {
		change(v * 2 + 1, l, m, ind, val);
	}
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p > 0)
			a[i] = 1;
		else {
			a[i] = 0;
		}
	}
	build(0, 0, n);
	cin >> k;
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		if (c == 's') {
			int l, r;
			cin >> l >> r >> num;
			if (ask(0, 0, n, l - 1, r) < num) {
				cout << -1 << " ";
				continue;
			}
			l--;
			int st = l;
			while (r - l != 1) {
				int m = l + (r - l) / 2;
				if (ask(0, 0, n, st, m) >= num)
					r = m;
				else {
					l = m;
				}
			}
			cout << r << " ";
		}
		else {
			int pos, val;
			cin >> pos >> val;
			if (val > 0)
				val = 1;
			change(0, 0, n, pos - 1, val);
		}
	}
	return 0;
}