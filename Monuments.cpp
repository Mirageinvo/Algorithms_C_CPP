#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, r;
ll ans=0;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> r;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int right = n;
		int left = -1;
		while (right - left != 1) {
			int m = left + (right - left) / 2;
			if (a[m] - r > a[i])
				right = m;
			else {
				left = m;
			}
		}
		ans += n - right;
	}
	cout << ans;
	return 0;
}