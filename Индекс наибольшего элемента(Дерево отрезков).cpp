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
		t[v] = l;
		return;
	}
	int m = l + (r - l) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	if (a[t[v * 2 + 1]] > a[t[v * 2 + 2]])
		t[v] = t[v * 2 + 1];
	else {
		t[v] = t[v * 2 + 2];
	}
	return;
}

int ask(int v, int l, int r, int al, int ar) {
	if (r <= al || l >= ar) {
		return n;
	}
	else if (l >= al && r <= ar)
		return t[v];
	int m = l + (r - l) / 2;
	int ab = ask(v * 2 + 1, l, m, al, ar);
	int bb = ask(v * 2 + 2, m, r, al, ar);
	if (a[ab] >= a[bb])
		return ab;
	else {
		return bb;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n+1);
	a[n] = -100000099;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build(0, 0, n);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		int h = ask(0, 0, n, l - 1, r);
		cout << a[h] << " " << h + 1 << endl;
	}
	return 0;
}