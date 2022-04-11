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
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	vector<vector<int>> dp(n, vector<int>(m)), anc(n, vector<int>(m, -1));
	vector<int> anss;
	int ans = 0;
	for (int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = 1;
				if (j != 0) {
					for (int h = 0; h < i; h++) {
						if (dp[h][j - 1]+1 > dp[i][j] && a[h] < a[i]) {
							dp[i][j] = dp[h][j - 1] + 1;
							anc[i][j] = h;
						}
					}
				}
			}
			else {
				if (j != 0) {
					dp[i][j] = dp[i][j - 1];
					anc[i][j] = -2;
				}
			}
		}
	int curx = 0;
	int cury = m-1;
	for (int i = 0; i < n; i++)
		if (dp[i][cury] > dp[curx][cury])
			curx = i;
	if (dp[curx][cury] == 0) {
		cout << 0;
		return 0;
	}
	cout << dp[curx][cury] << endl;
	while (curx!=-1) {
		if (anc[curx][cury] == -2)
			cury--;
		else {
			anss.emplace_back(a[curx]);
			curx = anc[curx][cury];
			cury--;
		}
	}
	reverse(anss.begin(), anss.end());
	for (int l : anss)
		cout << l << " "; 
	return 0;
}