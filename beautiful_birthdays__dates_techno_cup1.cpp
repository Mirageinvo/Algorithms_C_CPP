#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, year, ans, num, m, y;
	k = 0;
	num = 0;
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> year;
		if (year < 10) {
			cout << year << endl;
			continue;
		}
		y = year;
		while (year > 0) {
			year /= 10;
			k += 1;
		}
		k -= 1;
		m = y / pow(10, k);
		for (int u = k; u > 0; u--) {
			num += m*pow(10, u);
		}
		num += m;
		ans += m - 1;
		if (y >= num) {
			ans += 1;
		}
		ans += k * 9;
		cout << ans << endl;
		ans = 0;
		k = 0;
		num = 0;
	}
	return 0;
}