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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        int best_length = 0;
        for (int j = 0; j < i - 1; ++j) {
            if (v[j] < v[i - 1]) {
                best_length = max(best_length, dp[j + 1]);
            }
        }
        dp[i] = 1 + best_length;
    }

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
