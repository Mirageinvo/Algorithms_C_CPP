#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*void per(int n, int left, vector<int> p, vector<int> done) {
	if (left == 0) {
		for (int i : p)
			cout << i;
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (find(done.begin(), done.end(), i) == done.end()) {
			p.push_back(i);
			done.push_back(i);
			per(n, left - 1, p, done);
			p.pop_back();
			done.pop_back();
		}
	}
}*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> p;
	p.reserve(n);
	for (int i = 1; i <= n; ++i) {
		p.push_back(i);
	}
	vector<int> start(p);
	do {
		for (int i : p) {
			cout << i;
		}
		cout << endl;
		next_permutation(p.begin(), p.end());
	} while (!equal(p.begin(), p.end(), start.begin(), start.end()));

	//the secons solution is down here
	/*int n, left;
	vector<int> p, done;
	cin >> n;
	left = n;
	per(n, left, p, done);*/
	return 0;
}