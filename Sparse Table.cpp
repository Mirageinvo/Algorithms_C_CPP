#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int sparse[20][100001];
int logs[100001];

int asklvl(int l, int r) {
	int level = logs[r - l + 1];
	return min(sparse[level][l], sparse[level][r - (1 << level) + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, a1, u1, v1;
	cin >> n >> m >> a1;
	cin >> u1 >> v1;
	vector<int> a(100001);
	logs[0] = logs[1] = 0;
	for (int i = 2; i < 100001; i++)
		logs[i] = logs[i / 2] + 1;
	a[1] = a1;
	for (int i = 2; i <= n; i++) {
		a[i] = (a[i - 1] * 23 + 21563) % 16714589;
	}
	for (int i = 1; i <= n; i++) {
		sparse[0][i] = a[i];
	}
	for (int level=1; (1<<level)<=n; level++)
		for (int i = 1; i + (1 << level)-1 <= n; i++) {
			sparse[level][i] = min(sparse[level - 1][i], sparse[level-1][i+(1<<(level-1))]);
		}
	int ans = asklvl(min(v1, u1), max(v1, u1));
	for (int i = 1; i < m; i++) {
		u1 = (17 * u1 + 751 + ans + 2 * i) % n + 1;
		v1 = (13 * v1 + 593 + ans + 5 * i) % n + 1;
		ans = asklvl(min(v1, u1), max(v1, u1));
	}
	cout << min(v1, u1) << " " << max(v1, u1) << " " << ans << endl;
	return 0;
}