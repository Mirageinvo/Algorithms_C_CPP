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
	int n, m, k, x1, x2, y1, y2;
	cin >> n >> m >> k;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	vector<vector<ll>> s(n + 1, vector<ll>(m + 1));
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++) {
			cin >> a[i][j];
		}
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++) {
			s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
	}
	return 0;
}