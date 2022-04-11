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
    Point p, a, b;
    cin >> p >> a >> b;
    if (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) && p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y)) {
        Point v1 = p - a;
        Point v2 = b - a;
        if (cross(v1, v2) == 0)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}