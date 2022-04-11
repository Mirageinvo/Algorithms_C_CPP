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

const int INF = 1e9;

struct Point {
    ld x, y;
    Point() {};
    Point(int x, int y) : x(x), y(y) {};
};

istream& operator>>(istream& in, Point& a) {
    in >> a.x >> a.y;
    return in;
}

Point operator+(Point& a, Point& b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point& a, Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

ld cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

ld dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

ld dist(const Point& a) {
    return hypot(a.x, a.y);
}

vector<Point> a;

bool good(int j, int i) {
    Point v = a[i] - a[j];
    for (int t = j + 1; t < i; t++) {
        if (cross(v, a[t] - a[j]) > 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(30);
    int n, k, r;
    cin >> n >> k >> r;
    a.resize(n);
    vector<vector<ld>> dp(n, vector<ld>(k + 1, INF));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + dist(a[i] - a[i - 1]);
        for (int num = 1; num <= k; num++) {
            dp[i][num] = min(dp[i][num], dp[i - 1][num] + dist(a[i] - a[i - 1]));
            for (int j = 0; j < i; j++) {
                if (good(j, i) && dist(a[i] - a[j]) <= r) {
                    dp[i][num] = min(dp[i][num], dp[j][num - 1] + dist(a[i] - a[j]));
                }
            }
        }
    }
    ld ans = INF;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dp[n - 1][i]);
    cout << ans;
    return 0;
}