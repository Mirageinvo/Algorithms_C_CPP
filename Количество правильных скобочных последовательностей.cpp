#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <deque>
#include <tuple>
#include <set>
#include <cctype>
#include <stack>
#include <cstdio>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000007;
            }
        }
    }
    cout << dp[2 * n][0] % 1000000007;
    return 0;
}