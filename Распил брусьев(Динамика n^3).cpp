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

const ld PI = 3.1415926535;

struct Point {
    ld x, y;
    Point() {}
    Point(ld x, ld y) :x(x), y(y) {}
};

Point operator +(const Point& a, const Point& b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

istream& operator >>(istream& in, Point& a) {
    in >> a.x >> a.y;
    return in;
}

ld dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

ld cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

ld dist(const Point& a) {
    return hypot(a.x, a.y);
}

const ll INF = 1e10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin >> l >> n;
    n += 2;
    vector<int> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n));
    a[0] = 0;
    a[n - 1] = l;
    dp[0][1] = 0;
    for (int i = 1; i < n - 1; i++) {
        cin >> a[i];
        dp[i][i + 1] = 0;
    }
    for(int len = 3; len <= n; len++)
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l + 1; k <= r - 1; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + a[r] - a[l]);
        }
    cout << dp[0][n - 1];
    return 0;
}