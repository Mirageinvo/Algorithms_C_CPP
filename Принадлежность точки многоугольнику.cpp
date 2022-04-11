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

bool onray(Point p, Point f, Point s) {
    if (cross(p - f, s - f) == 0 && dot(p - f, s - f) >= 0)
        return true;
    return false;
}

bool onside(Point p, Point f, Point s) {
    if (onray(p, s, f) && onray(p, f, s))
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    Point p;
    cin >> n >> p;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ld angle = 0;
    for (int i = 0; i < n; i++) {
        if (onside(p, a[i], a[(i + 1) % n])) {
            cout << "YES";
            return 0;
        }
        angle += atan2(cross(a[i] - p, a[(i + 1) % n] - p), dot(a[i] - p, a[(i + 1) % n] - p));
    }
    if (abs(abs(angle) - PI * 2) < 1e-9)
        cout << "YES";
    else {
        cout << "NO";
    }
    return 0;
}