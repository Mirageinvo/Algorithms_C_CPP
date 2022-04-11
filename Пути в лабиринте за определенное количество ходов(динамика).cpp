#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void add_num(pair<size_t, size_t> ind, pair<size_t, size_t> maxes, size_t cur, vector<vector<vector<ull>>>& dp, const vector<vector<char>>& arr) {
    if (ind.first > 0 && arr[ind.first - 1][ind.second] != '+') {
        dp[ind.first][ind.second][cur] += dp[ind.first - 1][ind.second][cur - 1];
    }
    if (ind.second < maxes.second && arr[ind.first][ind.second + 1] != '+') {
        dp[ind.first][ind.second][cur] += dp[ind.first][ind.second + 1][cur - 1];
    }
    if (ind.first < maxes.first && arr[ind.first + 1][ind.second] != '+') {
        dp[ind.first][ind.second][cur] += dp[ind.first + 1][ind.second][cur - 1];
    }
    if (ind.second > 0 && arr[ind.first][ind.second - 1] != '+') {
        dp[ind.first][ind.second][cur] += dp[ind.first][ind.second - 1][cur - 1];
    }
}

int main() {
    size_t n, m, k;
    pair<size_t, size_t> st, fin;
    cin >> n >> m >> k;
    vector<vector<char>> arr(n, vector<char>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '@') {
                st = { i, j };
            }
            else if (arr[i][j] == '#') {
                fin = { i, j };
            }
        }
    }
    vector<vector<vector<ull>>> dp(n, vector<vector<ull>>(m, vector<ull>(k + 1, 0)));
    dp[st.first][st.second][0] = 1;
    for (size_t q = 1; q <= k; ++q) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (arr[i][j] != '+') {
                    add_num({ i, j }, { n - 1, m - 1 }, q, dp, arr);
                }
            }
        }
    }
    cout << dp[fin.first][fin.second][k];
    return 0;
}