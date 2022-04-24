#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<size_t>> dp(s1.size() + 1, vector<size_t>(s2.size() + 1, 0));
    for (size_t i = 0; i < dp.size(); ++i) {
        dp[i][0] = i;
    }
    for (size_t i = 0; i < dp[0].size(); ++i) {
        dp[0][i] = i;
    }
    for (size_t i = 1; i < dp.size(); ++i) {
        for (size_t j = 1; j < dp[i].size(); ++j) {
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s1[i] == s2[j] ? 0 : 1)));
        }
    }
    cout << dp[s1.size()][s2.size()];
    return 0;
}