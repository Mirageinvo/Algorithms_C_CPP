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

inline int bin_search_ind(const vector<int>& dp, int el) {
    int l = 0, r = dp.size();
    while (r - l > 1) {
        int m = l + ((r - l) / 2);
        if (dp[m] < el) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> seq1(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq1[i];
    }
    cin >> m;
    vector<int> seq2(m);
    for (int i = 0; i < m; ++i) {
        cin >> seq2[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
