#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct Point {
    Point(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    ll x, y;
};

istream& operator>>(istream& in, Point& el) {
    in >> el.x >> el.y;
    return in;
}

struct Triangle {
    Triangle() {
        arr.resize(3);
    }
    vector<Point> arr;
};

istream& operator>>(istream& in, Triangle& el) {
    for (size_t i = 0; i < 3; ++i) {
        in >> el.arr[i];
    }
    return in;
}

inline ll scal(const Point& f, const Point& s) {
    return f.x * s.x + f.y * s.y;
}

inline ll vect(const Point& f, const Point& s) {
    return f.x * s.y - f.y * s.x;
}

inline bool in_trngl(const Triangle& tr, const Point& p) {
    for (size_t i = 0; i < 3; ++i) {
        Point tmp(p.x - tr.arr[i].x, p.y - tr.arr[i].y);
        Point pf(tr.arr[(i + 1) % 3].x - tr.arr[i].x, tr.arr[(i + 1) % 3].y - tr.arr[i].y);
        Point ps(tr.arr[(i + 2) % 3].x - tr.arr[i].x, tr.arr[(i + 2) % 3].y - tr.arr[i].y);
        if ((vect(pf, tmp) > 0 && vect(tmp, ps) < 0) || (vect(pf, tmp) < 0 && vect(tmp, ps) > 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    Triangle tr;
    Point p;
    cin >> tr;
    cin >> p;
    while (cin) {
        if (in_trngl(tr, p)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        cin >> p;
    }
    return 0;
}