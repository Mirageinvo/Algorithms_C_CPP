#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>

ostream& operator<<(ostream& out, const vector<T>& A) {
	for (T o : A)
		cout << o << " ";
	return out;
}

void print(const vector<T>& A) {
	copy(A.begin(), A.end(), ostream_iterator<T>(cout, " "));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	cin >> n;
	vector<int> p;
	p.reserve(n);
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		p.push_back(t);
	}
	cout << endl;
	cout << p;
	print(p);
	return 0;
}