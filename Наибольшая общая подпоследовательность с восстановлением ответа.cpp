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
	int n1, n2;
	cin >> n1;
	vector<int> s1(n1);
	for (int i = 0; i < n1; i++)
		cin >> s1[i];
	cin >> n2;
	vector<int> s2(n2);
	for (int i = 0; i < n2; i++)
		cin >> s2[i];
	vector<vector<int>> dp(n1, vector<int>(n2));
	vector<vector<int>> anc(n1, vector<int>(n2));
	for (int i = 0; i < n1; i++)
		for (int q = 0; q < n2; q++) {
			if (s1[i] == s2[q]) {
				if (q - 1 < 0 || i - 1 < 0) {
					dp[i][q] = 1;
					anc[i][q] = 1;
				}
				else {
					dp[i][q] = dp[i - 1][q - 1] + 1;
					anc[i][q] = 1;
				}
			}
			else {
				if (i - 1 < 0 && q - 1 < 0) {
					dp[i][q] = 0;
					anc[i][q] = 2;
				}
				else if (i - 1 < 0) {
					dp[i][q] = dp[i][q - 1];
					anc[i][q] = 3;
				}
				else if (q - 1 < 0) {
					dp[i][q] = dp[i - 1][q];
					anc[i][q] = 2;
				}
				else {
					if (dp[i - 1][q] > dp[i][q - 1]) {
						dp[i][q] = dp[i - 1][q];
						anc[i][q] = 2;
					}
					else { 
						dp[i][q] = dp[i][q-1];
						anc[i][q] = 3;
					}
				}
			}
		}
	vector<int> ans;
	int curx = n1-1, cury = n2-1;
	while (curx >= 0 && cury >= 0) {
		if (anc[curx][cury] == 1) {
			ans.push_back(s1[curx]);
			curx--;
			cury--;
		}
		else if (anc[curx][cury] == 2) {
			curx--;
		}
		else if (anc[curx][cury] == 3) {
			cury--;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int u : ans)
		cout << u <<" ";
	return 0;
}