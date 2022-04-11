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

const int SIZE = 115000;
pair<ll, ll> t[4 * SIZE];
vector<int> a(110000);

void build(int v, int l, int r) {
	if (r - l == 1) {
		t[v].first = a[l];
		t[v].second = a[l];
		return;
	}
	int m = l + (r - l) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	t[v].first = min(t[v * 2 + 1].first, t[v * 2 + 2].first);
	t[v].second = max(t[v * 2 + 1].second, t[v * 2 + 2].second);
}

pair<ll, ll> ask(int v, int l, int r, int askl, int askr) {
	if (l >= askr || r <= askl)
		return {1000000000000, -1000000000000};
	else if (l >= askl && r <= askr)
		return t[v];
	int m = l + (r - l) / 2;
	auto fir = ask(v * 2 + 1, l, m, askl, askr);
	auto sec = ask(v * 2 + 2, m, r, askl, askr);
	return {min(fir.first, sec.first), max(fir.second, sec.second)};
}

void change(int v, int l, int r, int pos, ll val) {
	if (r - l == 1) {
		t[v].first = val;
		t[v].second = val;
		return;
	}
	int m = l + (r - l) / 2;
	if (pos < m)
		change(v * 2 + 1, l, m, pos, val);
	else {
		change(v * 2 + 2, m, r, pos, val);
	}
	t[v].first = min(t[v * 2 + 1].first, t[v * 2 + 2].first);
	t[v].second = max(t[v * 2 + 1].second, t[v * 2 + 2].second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	for (int i = 0; i < 110000; i++) {
		a[i] = ((i + 1) * (i + 1) % 12345) + ((i + 1) * (i + 1) % 23456 * (i + 1) % 23456);
	}
	build(0, 0, 110000);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if (x > 0) {
			auto p = ask(0, 0, 110000, x - 1, y);
			cout << p.second - p.first << endl;
		}
		else {
			change(0, 0, 110000, abs(x) - 1, y);
		}
	}
	return 0;
}