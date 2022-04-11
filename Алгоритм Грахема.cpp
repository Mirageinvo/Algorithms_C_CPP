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

Point o;

bool cmp(const Point& a, const Point& b) {
    return cross(a - o, b - o) > 0 || cross(a - o, b - o) == 0 && dist(a - o) < dist(b - o);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(30);
    int n;
    cin >> n;
    vector<Point> a(n), ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].x < a[start].x || a[i].x == a[start].x && a[i].y < a[start].y) {
            start = i;
        }
    }
    ans.push_back(a[start]);
    o = a[start];
    swap(a[0], a[start]);
    sort(a.begin() + 1, a.end(), cmp);
    int sz = 1;
    for (int i = 1; i < n; i++) {
        while (sz > 1 && cross(a[i]-ans[sz-1], ans[sz-1]-ans[sz-2])>=0) {
            ans.pop_back();
            sz--;
        }
        ans.push_back(a[i]);
        sz++;
    }
    ld p = 0, sq = 0;
    for (int i = 0; i < sz; i++) {
        p += dist(ans[i] - ans[(i + 1) % sz]);
        sq += cross(ans[i], ans[(i + 1) % sz]);
    }
    sq = abs(sq);
    sq /= 2;
    cout << p << " " << sq;
    return 0;
}