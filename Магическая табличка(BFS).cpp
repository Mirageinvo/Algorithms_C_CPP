#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int INF = 1e9;
int n, m;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

bool good(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	queue<pair<int, int>> q;
	vector<vector<int>> a(n, vector<int>(m)), ans(n, vector<int>(m, INF));
	vector<pair<int, int>> p;
	for (int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i, j });
				ans[i][j] = 0;
			}
		}
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();//tuple
		q.pop();
		for (int h = 0; h < 4; h++) {
			int nx = x + dx[h];
			int ny = y + dy[h];
			if (good(nx, ny)) {
				if (ans[x][y] + 1 < ans[nx][ny]) {
					ans[nx][ny] = ans[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}