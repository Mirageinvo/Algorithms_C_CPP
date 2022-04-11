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
    Point a, b, c, d;
    cin >> a >> b >> c >> d;
    Point ab = b - a;
    Point cd = d - c;
    if (abs(cross(ab, cd)) == 0) {
        if (a.x == b.x) {
            if (c.x == a.x) {
                if (dot(ab, cd) < 0) {
                    if (b.y < a.y) {
                        if (c.y <= a.y)
                            cout << "YES";
                        else {
                            cout << "NO";
                        }
                    }
                    else{
                        if (c.y >= a.y)
                            cout << "YES";
                        else {
                            cout << "NO";
                        }
                    }
                }
                else {
                    cout << "YES";
                }
            }
            else {
                cout << "NO";
            }
        }
        else {
            ld f1, f2;
            if (a.x == 0)
                f1 = a.y;
            else if (b.x == 0)
                f1 = b.y;
            else {
                f1 = (a.y * b.x - b.y * a.x) / (b.x - a.x);
            }
            if (c.x == 0)
                f2 = c.y;
            else if (d.x == 0)
                f2 = d.y;
            else {
                f2 = (c.y * d.x - d.y * c.x) / (d.x - c.x);
            }
            if (abs(f1 - f2) < 1e-9) {
                if (dot(ab, cd) < 0) {
                    if (b.x < a.x) {
                        if (c.x <= a.x)
                            cout << "YES";
                        else {
                            cout << "NO";
                        }
                    }
                    else {
                        if (c.x >= a.x)
                            cout << "YES";
                        else {
                            cout << "NO";
                        }
                    }
                }
                else {
                    cout << "YES";
                }
            }
            else {
                cout << "NO";
            }
        }
    }
    else {
        ld f1, f2, k1, k2;
        if (a.x == 0)
            f1 = a.y;
        else if (b.x == 0)
            f1 = b.y;
        else {
            f1 = (a.y * b.x - b.y * a.x) / (b.x - a.x);
        }
        if (c.x == 0)
            f2 = c.y;
        else if (d.x == 0)
            f2 = d.y;
        else {
            f2 = (c.y * d.x - d.y * c.x) / (d.x - c.x);
        }
        if (a.x != b.x) {
            if (a.x == 0) {
                k1 = (b.y - f1) / b.x;
            }
            else {
                k1 = (a.y - f1) / a.x;
            }
            if (c.x == d.x) {
                //if (d.y>c.y) {
                Point h = Point(c.x, k1 * c.x + f1);
                Point ah = h - a;
                Point ch = h - c;
                if (dot(ab, ah) >= 0 && dot(cd, ch) >= 0) {
                    cout << "YES";
                }
                else {
                    cout << "NO";
                }
                //}
                /*else {
                    if (k1 * c.x + f1 <= c.y) {
                        cout << "YES";
                    }
                    else {
                        cout << "NO";
                    }
                }*/
            }
            else {
                if (c.x == 0) {
                    k2 = (d.y - f2) / d.x;
                }
                else {
                    k2 = (c.y - f2) / c.x;
                }
                ld x = (f1 - f2) / (k2 - k1);
                ld y = k1 * x + f1;
                Point h = Point(x, y);
                Point ah = h - a;
                Point ch = h - c;
                if (dot(ab, ah) >= 0 && dot(cd, ch) >= 0) {
                    cout << "YES";
                }
                else {
                    cout << "NO";
                }
            }
        }
        else {
            if (c.x == 0) {
                k2 = (d.y - f2) / d.x;
            }
            else {
                k2 = (c.y - f2) / c.x;
            }
            Point h = Point(a.x, k2 * a.x + f2);
            Point ah = h - a;
            Point ch = h - c;
            if (dot(ab, ah) >= 0 && dot(cd, ch) >= 0) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
        }
    }
    return 0;
}