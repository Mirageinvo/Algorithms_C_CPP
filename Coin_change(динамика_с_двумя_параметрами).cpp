#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long int INF = 1e9;

// https://leetcode.com/problems/coin-change-ii/description/

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(m);
    for (int i = 0; i < m; ++i) {
        cin >> coins[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1]) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    cout << dp[m][n];
    return 0;
}
