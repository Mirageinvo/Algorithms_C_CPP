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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n + 1);
    dp[0] = -INF;
    for (int i = 1; i <= n; ++i) {
        dp[i] = INF;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        int ind = bin_search_ind(dp, v[i]);
        dp[ind + 1] = v[i];
    }

    for (int i = n; i >= 0; --i) {
        if (dp[i] != INF) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
