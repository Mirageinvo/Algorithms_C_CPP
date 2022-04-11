#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int s[2000];
	for (int i = 0; i < 2000; i++)
		s[i] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sq = sqrt(n);
	for (int i = 0; i < n; i++)
		s[i / sq] += a[i];
	int q, l, r;
	for (int i = 0; i < m; i++) {
		cin >> q >> l >> r;
		l--;
		r--;
		if (!q) {
			ll sum = 0;
			if (l == r) {
				cout << a[l] << endl;
				continue;
			}
			if (r - l + 1 < sq) {
				for (int j=l; j<=r; j++)
					sum += a[j];
				cout << sum << endl;
			}
			else {
				int blockl = l/sq + 1;
				int blockr = r / sq;
				for (int j = blockl; j < blockr; j++) {
					sum += s[j];
				}
				for (int j = l; j < blockl*sq; j++) {
					sum += a[j];
				}
				for (int j = blockr*sq; j <= r; j++) {
					sum += a[j];
				}
				cout << sum << endl;
			}
		}
		else {
			int blockl = l / sq;
			int blockr = r / sq;
			reverse(a.begin()+l, a.begin()+r+1);
			for (int j = blockl; j <= blockr; j++)
				s[j] = 0;
			for (int j = blockl; j <= blockr; j++) {
				for (int h = sq * blockl; h < sq * blockl + sq; h++)
					s[j] += a[h];
			}
		}
	}
	return 0;
}