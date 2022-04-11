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
    cout.precision(30);
    Point  o, p;
    ld r;
    cin >> o >> r;
    cin >> p;
    Point check = o - p;
    if (dist(check) < r)
        cout << 0;
    else if (abs(dist(check) - r) == 0)
        cout << 1 << endl << p.x << " " << p.y;
    else {
        if (o.x == p.x) {
            ld B = 0;
            ld A = 1;
            ld C = -o.x;
            Point f = o - p;
            ld tlen = sqrt(dist(f) * dist(f) - r * r);
            ld h = tlen * r / dist(f);
            Point v = Point(A, B);
            v.x = h * v.x / sqrt(A * A + B * B);
            v.y = h * v.y / sqrt(A * A + B * B);
            Point helper = Point(-B, A);
            helper.x = sqrt(r * r - h * h) * helper.x / sqrt(A * A + B * B);
            helper.y = sqrt(r * r - h * h) * helper.y / sqrt(A * A + B * B);
            Point last = o + helper;
            if (dist(last - p) > dist(f))
                last = o - helper;
            cout << 2 << endl << last.x + v.x << " " << last.y + v.y << endl << last.x - v.x << " " << last.y - v.y;
        }
        else {
            ld B = 1;
            Point f = o - p;
            ld A = -f.y / f.x;
            ld C = o.y + (A * o.x);
            ld tlen = sqrt(dist(f) * dist(f) - r * r);
            ld h = tlen * r / dist(f);
            Point v = Point(A, B);
            v.x = h * v.x / sqrt(A * A + B * B);
            v.y = h * v.y / sqrt(A * A + B * B);
            Point helper = Point(-B, A);
            helper.x = sqrt(r * r - h * h) * helper.x / sqrt(A * A + B * B);
            helper.y = sqrt(r * r - h * h) * helper.y / sqrt(A * A + B * B);
            Point last = o + helper;
            if (dist(last - p) > dist(f))
                last = o - helper;
            cout << 2 << endl << last.x + v.x << " " << last.y + v.y << endl << last.x - v.x << " " << last.y - v.y;
        }
    }
    return 0;
}