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
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int delcost=1, addcost=1, replcost = 1;
	vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
	for (int i=0; i<=s1.size(); i++)
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				dp[i][j] = j*addcost;
			else if (j == 0)
				dp[i][j] = i*delcost;
			else {
				if (s1[i-1] == s2[j-1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					dp[i][j] = min({ dp[i - 1][j - 1] + replcost, dp[i - 1][j] + delcost, dp[i][j - 1] + addcost });
				}
			}
		}
	cout << dp[s1.size()][s2.size()];
	return 0;
}