#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

vector<int> a;
long long int ct = 0;
void merge_sort(int l, int r) {
	if (r - l == 1)
		return;
	int m = (r + l) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	//inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r);
	vector<int> tmp(r - l);
	int it1 = l, it2 = m;
	while (it1 < m || it2 < r) {
		int ind = it1 - l + it2 - m;
		if (it1==m) {
			tmp[ind] = a[it2];
			it2++;
		}
		else if (it2 == r) {
			tmp[ind] = a[it1];
			it1++;
		}
		else if (a[it1] <= a[it2]) {
			tmp[ind] = a[it1];
			it1++;
		}
		else {
			tmp[ind] = a[it2];
			ct+=m-it1;
			it2++;
		}
	}
	copy(tmp.begin(), tmp.end(), a.begin() + l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(0, n);
	cout << ct;
	return 0;
}