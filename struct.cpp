#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	double x, y;
	double dist()const {
		return x * x + y * y;
	}
};
std::istream& operator>>(std::istream& in, Point& A) {
	in >> A.x >> A.y;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Point& A) {
	out << A.x << " " << A.y;
	return out;
}
Point operator+(const Point& A, const Point& B) {
	return { A.x + B.x, A.y + B.y };
}
Point operator-(const Point& A, const Point& B) {
	return{ A.x - B.x, A.y-B.y};
}
Point operator/(const Point& A, int k) {
	return{A.x / k, A.y / k};
}
double quick(const vector<Point>& lst) {
	int n = lst.size();
	double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((lst[i] - lst[j]).dist() > ans)
				ans = (lst[i] - lst[j]).dist();
		}
	}
	return sqrt(ans);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <Point> lst(n);
	for (int i = 0; i < n; i++)
		cin >> lst[i];
	cout.precision(17);
	cout << fixed;
	cout << quick(lst);
	return 0;
}