#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<int> ts;
vector<int> tr;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pair<ll, ll> a;
	cin >> n;
	ts.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> ts[i];
	}
	cin >> m;
	tr.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> tr[i];
	}
	int i = 0;
	int j = 0;
	a.first = ts[0];
	a.second = tr[0];
	int dif = abs(ts[j] - tr[i]);
	while (dif != 0 && i < m && j < n) {
		if (abs(ts[j] - tr[i]) < dif) {
			dif = abs(ts[j] - tr[i]);
			a.first = ts[j];
			a.second = tr[i];
		}
		if (ts[j] - tr[i] < 0)
			j++;
		else { i++; }
	}
	cout << a.first << " " << a.second;
	return 0;
}