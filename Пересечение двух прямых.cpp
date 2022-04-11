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

const ld pi = 3.14159265358979323846;

struct Point {
    ld x, y;
    Point() {}
    Point(ld x, ld y) :x(x), y(y) {}
};

Point operator -(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

istream& operator >>(istream& in, Point& a) {
    in >> a.x >> a.y;
    return in;
}

ld dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y + b.y;
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
    Point a, b, c, d;
    cin >> a >> b >> c >> d;
    Point f = b - a;
    Point s = d - c;
    if (a.x == b.x) {
        if (c.x == d.x) {
            if (a.x == c.x)
                cout << 2;
            else {
                cout << 0;
            }
        }
        else {
            ld k = s.y / s.x;
            cout << 1 << " " << a.x << " " << k * a.x + (c.y - (c.x * k));
        }
    }
    else if (c.x == d.x) {
        ld k = f.y / f.x;
        cout << 1 << " " << c.x << " " << k * c.x + (a.y - (a.x * k));
    }
    else {
        ld k1 = f.y / f.x;
        ld k2 = s.y / s.x;
        if (k1 == k2) {
            if (a.y-(a.x*k1)==c.y-(c.x*k2)) {
                cout << 2;
            }
            else {
                cout << 0;
            }
        }
        else {
            ld g1 = a.y - (a.x * k1);
            ld g2 = c.y - (c.x * k2);
            cout << 1 << " " << (g2 - g1) / (k1 - k2) << " " << k1 * (g2 - g1) / (k1 - k2) + g1;
        }
    }
    return 0;
}