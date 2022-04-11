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

int n;
Point o;
vector<pair<Point, int>> a;
vector<bool> used;

bool cmp(const pair<Point, int>& a, const pair<Point, int>& b) {
    return cross(a.first - o, b.first - o) > 0 || cross(a.first - o, b.first - o) == 0 && dist(a.first - o) < dist(b.first - o);
}

bool good() {
    int start = 0;
    while (used[a[start].second])
        start++;
    int next = start + 1;
    while (used[a[next].second])
        next++;
    Point v = a[next].first - a[start].first;
    for (int i = next + 1; i < n; i++) {
        if (!used[a[i].second]) {
            if (abs(cross(v, a[i].first - a[start].first)) > 1e-9)
                return true;
        }
    }
    return false;
}

int d() {
    if (!good())
        return -1;
    vector<pair<Point, int>> ans;
    int start = 0;
    while (used[a[start].second])
        start++;
    for (int i = 0; i < n; i++) {
        if (!used[a[i].second] && (a[i].first.x < a[start].first.x || a[i].first.x == a[start].first.x && a[i].first.y < a[start].first.y)) {
            start = i;
        }
    }
    ans.push_back(a[start]);
    o = a[start].first;
    swap(a[0], a[start]);
    used[a[0].second] = true;
    sort(a.begin() + 1, a.end(), cmp);
    int sz = 1;
    for (int i = 1; i < n; i++) {
        if (used[a[i].second])
            continue;
        while (sz > 1 && cross(a[i].first - ans[sz - 1].first, ans[sz - 1].first - ans[sz - 2].first) > 0) {
            used[ans.back().second] = false;
            ans.pop_back();
            sz--;
        }
        ans.push_back(a[i]);
        used[a[i].second] = true;
        sz++;
    }
    for (int i = 0; i < n; i++) {//можно убрать
        if (!used[a[i].second]) {
            if (abs(cross(ans[ans.size() - 1].first - ans[0].first, ans[ans.size() - 1].first - a[i].first)) < 1e-16 && dot(ans[ans.size() - 1].first - ans[0].first, ans[ans.size() - 1].first - a[i].first) >= 0)
                used[a[i].second] = true;
        }
    }
    return ans.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(30);
    cin >> n;
    a.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p;
        a[i] = { p, i };
    }
    int num = n;
    int anss = 0;
    while (num > 2) {
        int g = d();
        if (g == -1)
            break;
        num -= g;
        anss++;
    }
    cout << anss;
    return 0;
}