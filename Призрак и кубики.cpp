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

/*string s1, s2;
ll p = 101, m = 1000000321;
ll po[105000];
ll h1[100001], h2[100001];

void start() {
	po[0] = 1;
	for (int i = 1; i < 105000; i++)
		po[i] = po[i - 1] * p % m;
	h1[0] = s1[0];
	h2[0] = s2[0];
	for (int i = 1; i < s1.size(); i++)
		h1[i] = (h1[i - 1] * p + s1[i]) % m;
	for (int i = 1; i < s2.size(); i++)
		h2[i] = (h2[i - 1] * p + s2[i]) % m;
}

ll gethash(ll h[100001], int l, int r) {
	if (l == 0)
		return h[r];
	else {
		return (h[r] - (h[l - 1] * po[r - l + 1] % m) + m) % m;
	}
}*/

int n, m;
vector<int> a, b;

bool check(int j) {
	for (int i = j+1; i <= 2*j+1; i++) {
		if (a[i] != b[n - 2 - j + i - j]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> ans;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	b = a;
	reverse(b.begin(), b.end());
	ans.emplace_back(a.size());
	for (int i = 0; i < n/2; i++) {
		if (check(i))
			ans.emplace_back(n - i - 1);
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";
	return 0;
}