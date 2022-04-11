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

int n;

int count(int mask) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i))
            ans += 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<vector<int>> gr(n);
    vector<bool> dp(1 << n);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'Y')
                gr[i].push_back(j);
        }
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        int v;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                v = i;
                break;
            }
        }
        for (int u : gr[v]) {
            if (mask & (1 << u) && dp[mask ^ (1 << v) ^ (1 << u)]) {
                dp[mask] = true;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i])
            ans = max(ans, count(i));
    }
    cout << ans;
    return 0;
}