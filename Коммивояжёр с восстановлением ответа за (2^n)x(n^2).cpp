#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cctype>
#include <stack>
#include <cstdio>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> gr(n, vector<int>(n, INF)), dp(1 << n,  vector<int>(n, INF));
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                int h;
                cin >> h;
            }
            else {
                cin >> gr[i][j];
            }
        }
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)))
                continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j))
                    continue;
                int nmask = (mask ^ (1 << j));
                //dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + gr[i][j]);
                if (dp[nmask][j] > dp[mask][i] + gr[i][j]) {
                    dp[nmask][j] = dp[mask][i] + gr[i][j];
                    p[j] = i;
                }
            }
        }
    }
    int m = dp[(1 << n) - 1][0];
    int curr = 0;
    for (int i = 1; i < n; i++) {
        if (m > dp[(1 << n) - 1][i]) {
            m = dp[(1 << n) - 1][i];
            curr = i;
        }
    }
    cout << m << endl;
    int start = curr;
    do {
        cout << curr + 1 << " ";
        curr = p[curr];
    } while (curr != -1 && curr != start);
    return 0;
}