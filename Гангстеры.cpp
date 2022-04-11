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
    int n, k, t;
    cin >> n >> k >> t;
    vector<pair<int, pair<int, int>>> a(n);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second.first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second.second;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].first >= a[i].second.second) {
            dp[i] = a[i].second.first;
            for (int j = 0; j < i; j++) {
                if (a[i].first - a[j].first >= abs(a[i].second.second - a[j].second.second))
                    dp[i] = max(dp[i], dp[j] + a[i].second.first);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}