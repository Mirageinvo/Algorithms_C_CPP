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

int n, k;
vector<Point> a;

string f(Point p) {
    p = p - a[0];
    Point oa = a[n-1] - a[0];
    Point ob = a[1] - a[0];
    if (cross(p, oa) * cross(p, ob) < 0 && abs(abs(atan2(cross(p, oa), dot(p, oa))) + abs(atan2(cross(p, ob), dot(p, ob))) - abs(atan2(cross(oa, ob), dot(oa, ob)))) < 1e-9) {
        int l = n - 1;
        int r = 1;
        while (l - r != 1) {
            int m = l + (r - l) / 2;
            if (cross(p, a[r] - a[0]) * cross(p, a[m] - a[0]) <= 0) {
                l = m;
            }
            else {
                r = m;
            }
        }
        if (cross(a[l] - a[r], p + a[0] - a[r]) == 0) {
            return "BORDER";
        }
        else if (cross(p + a[0] - a[r], a[l] - a[r]) * cross(p + a[0] - a[r], a[0] - a[r]) <= 0 && abs(abs(atan2(cross(p + a[0] - a[r], a[l] - a[r]), dot(p + a[0] - a[r], a[l] - a[r]))) + abs(atan2(cross(p + a[0] - a[r], a[0] - a[r]), dot(p + a[0] - a[r], a[0] - a[r]))) - abs(atan2(cross(a[l] - a[r], a[0] - a[r]), dot(a[l] - a[r], a[0] - a[r])))) < 1e-9) {
            return "INSIDE";
        }
        else {
            return "OUTSIDE";
        }
    }
    else if (cross(p, oa) == 0 && dot(p, oa) >= 0 && dist(oa) + 1e-9 >= dist(p) || cross(p, ob) == 0 && dot(p, ob) >= 0 && dist(ob) + 1e-9 >= dist(p)) {
        return "BORDER";
    }
    else {
        return "OUTSIDE";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        Point p;
        cin >> p;
        cout << f(p) << endl;
    }
    return 0;
}