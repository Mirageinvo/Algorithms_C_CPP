#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, y, d;
	bool t = true;
	cin >> n;
	vector<int> f;
	for (int i = 0; i < n; i++) {
		cin >> k;
		f.emplace_back(k);
	}
	cin >> y;
	vector<int> s;
	for (int i = 0; i < y; i++) {
		cin >> d;
		s.emplace_back(d);
	}
	sort(f.begin(), f.end());
	sort(s.begin(), s.end());
	f.resize(unique(f.begin(), f.end()) - f.begin());
	s.resize(unique(s.begin(), s.end()) - s.begin());
	cout << (equal(f.begin(), f.end(), s.begin(), s.end()) ? "YES" : "NO") << endl;
	//the second solution is down here
	/*if (f.size() == s.size()) {
		for (int i = 0; i < f.size(); i++) {
			if (find(f.begin(), f.end(), s[i]) == f.end()) {
				t = false;
				cout << "NO";
				break;
			}
		}
		if (t)
			cout << "YES";
	}
	else {
		cout << "NO";
	}*/
	return 0;
}