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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<Point> a(n);
    vector<pair<Point, int>> ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].x < a[start].x || a[i].x == a[start].x && a[i].y < a[start].y) {
            start = i;
        }
    }
    ans.push_back({ a[start], start });
    while (true) {
        int last = ans.back().second;
        int next = 0;
        for (int i = 0; i < n; i++) {
            if (cross(a[i] - a[last], a[next] - a[last]) > 0 || cross(a[i] - a[last], a[next] - a[last]) == 0 && dist(a[i] - a[last]) > dist(a[next] - a[last]))
                next = i;
        }
        if (next == start)
            break;
        else {
            ans.push_back({ a[next], next });
        }
    }
    int l = ans.size();
    ld p = 0, s = 0;
    for (int i = 0; i < l; i++) {
        p += dist(ans[(i + 1) % l].first - ans[i].first);
        s += cross(ans[(i + 1) % l].first, ans[i].first);
    }
    s = abs(s);
    s /= 2;
    cout << p << " " << s;
    return 0;
}