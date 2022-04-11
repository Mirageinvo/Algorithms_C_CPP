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
    cout.precision(30);
    Point a, b;
    Point h = Point(1, 0);
    const ld pi = 3.14159265358979323846;
    cin >> a >> b;
    ld an1, an2, ans;
    ld d1 = dist(a);
    ld d2 = dist(b);
    cout << acos(dot(a, b) / d1 / d2);
    return 0;
}