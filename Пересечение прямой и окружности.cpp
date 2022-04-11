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
    cout.precision(30);
    Point o;
    ld r, A, B, C;
    cin >> o >> r;
    cin >> A >> B >> C;
    ld sq = sqrt(A * A + B * B);
    ld d = (o.x * A + o.y * B + C) / sq;
    if (d > r) {
        cout << 0;
    }
    else if (abs(d - r) < 1e-9) {
        Point v = Point(A, B);
        v.x = d * A / sq;
        v.y = d * B / sq;
        if ((o.x + v.x) * A + (o.y + v.y) * B + C != 0) {
            v.x *= -1;
            v.y *= -1;
        }
        cout << 1 << endl << o.x + v.x << " " << o.y + v.y;
    }
    else {
        Point v = Point(A, B);
        v.x = d * A / sq;
        v.y = d * B / sq;
        if ((o.x + v.x) * A + (o.y + v.y) * B + C != 0) {
            v.x *= -1;
            v.y *= -1;
        }
        Point n = v + o;
        v = Point(-B, A);
        ld d2 = sqrt(r * r - d * d);
        v.x = d2 * v.x / sq;
        v.y = d2 * v.y / sq;
        cout << 2 << endl << n.x + v.x << " " << n.y + v.y << endl << n.x - v.x << " " << n.y - v.y;
    }
    return 0;
}