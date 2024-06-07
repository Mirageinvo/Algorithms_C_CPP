#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cstdio>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> w(N + 1);
    vector<int> c(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (w[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= M; ++i) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}
