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
	for (int i=0; i<n1; i++)
		for (int q = 0; q < n2; q++) {
			if (s1[i] == s2[q]) {
				if(q-1<0 || i-1<0)
					dp[i][q] = 1;
				else {
					dp[i][q] = dp[i-1][q - 1] + 1;
				}
			}
			else {
				if (i - 1 < 0 && q - 1 < 0)
					dp[i][q] = 0;
				else if (i - 1 < 0)
					dp[i][q] = dp[i][q - 1];
				else if (q - 1 < 0)
					dp[i][q] = dp[i - 1][q];
				else {
					dp[i][q] = max(dp[i - 1][q], dp[i][q-1]);
				}
			}
		}
	cout << dp[n1 - 1][n2 - 1];
	return 0;
}