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
    Point(ld x, ld y) : x(x), y(y) {};
};

Point operator -(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

ld dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

ld cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

ld dist(const Point& a) {
    return hypot(a.x, a.y);//Pythagorean
}

bool anch(Point v1, Point v2, Point p) {
    if (cross(p, v1) * cross(p, v2) <= 0 && abs(abs(atan2(cross(v1, v2), dot(v1, v2))) - abs(atan2(cross(v1, p), dot(v1, p))) - abs(atan2(cross(v2, p), dot(v2, p)))) < 1e-9)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(30);
    Point a, b, c, p;
    cin >> a >> b >> c >> p;
    Point ab = b - a;
    Point ac = c - a;
    Point ap = p - a;
    Point ba = a - b;
    Point bc = c - b;
    Point bp = p - b;
    Point ca = a - c;
    Point cb = b - c;
    Point cp = p - c;
    if (p.x == a.x && p.y == a.y || p.x == b.x && p.y == b.y || p.x == c.x && p.y == c.y)
        cout << "YES";
    else if (anch(ab, ac, ap) && anch(ba, bc, bp) && anch(ca, cb, cp))
        cout << "YES";
    else {
        cout << "NO";
    }
    return 0;
}