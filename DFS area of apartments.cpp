#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, r, c, ans=1;
vector<string> a;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

inline bool good(int x, int y) {
	return x < n && x >= 0 && y < n && y >= 0;
}

void dfs(int x, int y, vector<vector<bool>>& used) {
	used[x][y] = true;
	for (int h = 0; h < 4; h++) {
		int cx = x + dx[h];
		int cy = y + dy[h];
		if (good(cx, cy) && a[cx][cy] == '.' && !used[cx][cy]) {
			ans++;
			dfs(cx, cy, used);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	vector<vector<bool>> used(n, vector<bool>(n));
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> r >> c;
	r--;
	c--;
	dfs(r, c, used);
	cout << ans;
	return 0;
}