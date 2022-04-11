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
    Point o1, o2;
    ld r1, r2;
    cin >> o1 >> r1;
    cin >> o2 >> r2;
    if (r1 == 0 && r2 == 0) {
        if (o1.x == o2.x && o1.y == o2.y) {
            cout << 1 << endl << o1.x << " " << o1.y;
            return 0;
        }
        else {
            cout << 0;
            return 0;
        }
    }
    else if (r1 == 0) {
        Point check = o1 - o2;;
        if (abs(r2 - dist(check)) < 1e-9) {
            cout << 1 << endl << o1.x << " " << o1.y;
            return 0;
        }
        else {
            cout << 0;
            return 0;
        }
    }
    else if (r2 == 0) {
        Point check = o1 - o2;;
        if (abs(r1 - dist(check)) < 1e-9) {
            cout << 1 << endl << o2.x << " " << o2.y;
            return 0;
        }
        else {
            cout << 0;
            return 0;
        }
    }
    Point check = o1 - o2;
    if (max(r1, r2) - dist(check) > min(r1, r2)) {
        cout << 0;
        return 0;
    }
    if (dist(check) > r1 + r2 || o1.x == o2.x && o1.y == o2.y && r1 != r2) {
        cout << 0;
    }
    else if (o1.x == o2.x && o1.y == o2.y && r1 == r2)
        cout << 3;
    else {
        ld A, B, C;
        A = 2 * (o2.x - o1.x);
        B = 2 * (o2.y - o1.y);
        C = o1.x * o1.x - o2.x * o2.x + o1.y * o1.y - o2.y * o2.y + r2 * r2 - r1 * r1;
        ld sq = sqrt(A * A + B * B);
        ld d = (o1.x * A + o1.y * B + C) / sq;
        if (abs(d - r1) < 1e-9) {
            Point v = Point(A, B);
            v.x = d * A / sq;
            v.y = d * B / sq;
            if ((o1.x + v.x) * A + (o1.y + v.y) * B + C != 0) {
                v.x *= -1;
                v.y *= -1;
            }
            cout << 1 << endl << o1.x + v.x << " " << o1.y + v.y;
        }
        else {
            Point v = Point(A, B);
            v.x = d * A / sq;
            v.y = d * B / sq;
            if ((o1.x + v.x) * A + (o1.y + v.y) * B + C != 0) {
                v.x *= -1;
                v.y *= -1;
            }
            Point n = v + o1;
            v = Point(-B, A);
            ld d2 = sqrt(r1 * r1 - d * d);
            v.x = d2 * v.x / sq;
            v.y = d2 * v.y / sq;
            if (v.x == 0 && v.y == 0)
                cout << 1 << endl << n.x << " " << n.y;
            else {
                cout << 2 << endl << n.x + v.x << " " << n.y + v.y << endl << n.x - v.x << " " << n.y - v.y;
            }
        }
    }
    return 0;
}