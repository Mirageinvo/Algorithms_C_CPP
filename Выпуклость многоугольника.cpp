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
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool pos = false, neg = false;
    for (int i = 0; i < n; i++) {
        Point prev = a[(i - 1 + n) % n];
        Point next = a[(i + 1) % n];
        ld d = cross(a[i] - prev, next - a[i]);
        if (d < 0)
            neg = true;
        else if (d > 0)
            pos = true;
        if (pos && neg) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    /*int start;
    if (cross(a[0] - a[n - 1], a[1] - a[0])!=0)
        start = cross(a[0] - a[n - 1], a[1] - a[0]) / abs(cross(a[0] - a[n - 1], a[1] - a[0]));
    else {
        start = cross(a[1] - a[0], a[2] - a[1]) / abs(cross(a[1] - a[0], a[2] - a[1]));
    }
    for (int i = 0; i < n; i++) {
        Point prev = a[(i - 1 + n) % n];
        Point next = a[(i + 1) % n];
        if (start*cross(a[i]-prev, next-a[i])<0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";*/
    return 0;
}