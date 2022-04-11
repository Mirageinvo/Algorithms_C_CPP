#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, m, ans=0;
vector<string> a;
vector<vector<bool>> used;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = {0, -1, 1, 0};

inline bool good(int x, int y) {
	return x >= 0 && y >= 0 && x < m && y < n;
}

void dfs(int x, int y) {
	used[x][y] = true;
	for (int h = 0; h < 4; h++) {
		int cx = x + dx[h];
		int cy = y + dy[h];
		if (good(cx, cy) && !used[cx][cy] && a[cx][cy]=='#')
			dfs(cx, cy);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	a.resize(m);
	used.resize(m, vector<bool>(n));
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i=0; i<m; i++)
		for (int j = 0; j < n; j++) {
			if (!used[i][j] && a[i][j]=='#') {
				dfs(i, j);
				ans++;
			}
		}
	cout << ans;
	return 0;
}