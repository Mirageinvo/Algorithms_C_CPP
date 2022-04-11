#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, f, ans, nums, s, u;
	vector<int> a;
	a.reserve(300000);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> f;
			if (f % 2 == 0) {
				a.push_back(f);
			}
		}
		sort(a.begin(), a.end());
		while (a.size()!=0) {
			if (a.size() >= 2) {
				u = (int)(a.size() - 2);
				m++;
				while (u >= 0 && a[u] == a[a.size() - 1]) {
					a[u] /= 2;
					if (a[u] % 2 == 1) {
						a.erase(a.begin() + u, a.begin() + u + 1);
					}
					u--;
				}
				a[a.size() - 1] /= 2;
				if (a[a.size() - 1] % 2 == 1)
					a.pop_back();
				ans++;
			}
			else {
				while (a[a.size() - 1] % 2 == 0) {
					a[a.size() - 1] /= 2;
					ans++;
				}
				a.pop_back();
			}
		}
		cout << ans << endl;
		ans = 0;
		a.clear();
	}
	return 0;
}