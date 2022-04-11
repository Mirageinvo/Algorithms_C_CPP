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

vector<ll> a;
const int SIZE = 100010;
ll ch[SIZE * 4];

void push(int v) {
	ch[v * 2 + 1] += ch[v];
	ch[v * 2 + 2] += ch[v];
	ch[v] = 0;
}

ll ask(int v, int l, int r, int ind) {
	if (r - l == 1) {
		return a[ind] + ch[v];
	}
	push(v);
	int m = l + (r - l) / 2;
	if (ind >= m) {
		return ask(v * 2 + 2, m, r, ind);
	}
	else {
		return ask(v * 2 + 1, l, m, ind);
	}
}

void upgrade(int v, int l, int r, int upgl, int upgr, ll val) {
	if (l >= upgr || r <= upgl) {
		return;
	}
	if (l >= upgl && r <= upgr) {
		ch[v] += val;
		return;
	}
	push(v);
	int m = l + (r - l) / 2;
	upgrade(v * 2 + 1, l, m, upgl, upgr, val);
	upgrade(v * 2 + 2, m, r, upgl, upgr, val);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> k;
	for (int i = 0; i < k; i++) {
		char type;
		cin >> type;
		if (type == 'g') {
			int ind;
			cin >> ind;
			cout << ask(0, 0, n, ind - 1) << endl;
		}
		else {
			int upgl, upgr;
			ll val;
			cin >> upgl >> upgr >> val;
			upgrade(0, 0, n, upgl - 1, upgr, val);
		}
	}
	return 0;
}