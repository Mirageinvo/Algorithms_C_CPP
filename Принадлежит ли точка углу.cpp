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
    Point a, o, b, p;
    cin >> a >> o >> b >> p;
    Point oa = a - o;
    Point ob = b - o;
    Point op = p - o;
    if (p.x == o.x && p.y == o.y)
        cout << "YES";
    else if (cross(op, oa)*cross(op, ob)<=0 && abs(abs(atan2(cross(oa, ob), dot(oa, ob))) - abs(atan2(cross(oa, op), dot(oa, op))) - abs(atan2(cross(ob, op), dot(ob, op)))) < 1e-9)
        cout << "YES";
    else {
        cout << "NO";
    }
    return 0;
}