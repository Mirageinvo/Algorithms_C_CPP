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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Point a, b, c, d;
    cin >> a >> b >> c >> d;
    Point ca = a - c;
    Point cb = b - c;
    Point cd = d - c;
    Point ba = a - b;
    Point bc = c - b;
    Point bd = d - b;
    if (cross(ba, bc) == 0 && cross(ba, bd) == 0) {
        //if (cross(ba, cd)==0) {
        Point v = Point(1, 0);
        if (dot(ba, v) == 0) {
            if ((a.y >= min(c.y, d.y) && a.y <= max(c.y, d.y)) || (b.y >= min(c.y, d.y) && b.y <= max(c.y, d.y)) || (c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y)) || (d.y >= min(a.y, b.y) && d.y <= max(a.y, b.y))) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if (c.x == 0 && b.x == 0) {
            if (c.y == b.y) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if (c.x == 0) {
            if (abs(c.y - ((a.y - (a.x * b.y / b.x)) / (1 - (a.x / b.x)))) < 1e-6 && ((a.x >= min(c.x, d.x) && a.x <= max(c.x, d.x)) || (b.x >= min(c.x, d.x) && b.x <= max(c.x, d.x)) || (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x)) || (d.x >= min(a.x, b.x) && d.x <= max(a.x, b.x)))) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if (b.x == 0) {
            if (abs(b.y - ((d.y - (d.x * c.y / c.x)) / (1 - (d.x / c.x)))) < 1e-6 && ((a.x >= min(c.x, d.x) && a.x <= max(c.x, d.x)) || (b.x >= min(c.x, d.x) && b.x <= max(c.x, d.x)) || (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x)) || (d.x >= min(a.x, b.x) && d.x <= max(a.x, b.x)))) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if (abs((d.y - (d.x * c.y / c.x)) / (1 - (d.x / c.x)) - (a.y - (a.x * b.y / b.x)) / (1 - (a.x / b.x))) < 1e-6 && ((a.x >= min(c.x, d.x) && a.x <= max(c.x, d.x)) || (b.x >= min(c.x, d.x) && b.x <= max(c.x, d.x)) || (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x)) || (d.x >= min(a.x, b.x) && d.x <= max(a.x, b.x))) && (a.y >= min(c.y, d.y) && a.y <= max(c.y, d.y)) || (b.y >= min(c.y, d.y) && b.y <= max(c.y, d.y)) || (c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y)) || (d.y >= min(a.y, b.y) && d.y <= max(a.y, b.y))) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        if (cross(cd, ca) * cross(cd, cb) <= 0 && cross(ba, bc) * cross(ba, bd) <= 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}