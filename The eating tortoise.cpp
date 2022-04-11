#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

#pragma GCC_optimize("0fast");
#pragma GCC_optimize("fast_math");
#pragma GCC_optimize("03 unroll-no-loops");

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int st, cl;
	cin >> st >> cl;
	int a[101][101];
	a[0][1] = 0;
	a[1][0] = 0;
	for (int i=1; i<=st; i++)
		for (int j = 1; j <= cl; j++) {
			cin >> a[i][j];
		}
	char f[101][101];
	for (int i=1; i<=st; i++)
		for (int j = 1; j <= cl; j++) {
			if (i == 1) {
				a[1][j] += a[1][j - 1];
				f[1][j] = 'R';
			}
			else if (j == 1) {
				a[i][1] += a[i - 1][1];
				f[i][1] = 'D';
			}
			else {
				if (a[i - 1][j] > a[i][j - 1]) {
					a[i][j] += a[i - 1][j];
					f[i][j] = 'D';
				}
				else {
					a[i][j] += a[i][j - 1];
					f[i][j] = 'R';
				}
			}
		}
	f[1][1] = 'Z';
	vector<char> ans;
	int i = st, j = cl;
	while (f[i][j] != 'Z') {
		if (f[i][j] == 'R') {
			ans.emplace_back('R');
			j--;
		}
		else {
			ans.emplace_back('D');
			i--;
		}
	}
	cout << a[st][cl] << endl;
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i]<<" ";
	}
	return 0;
}