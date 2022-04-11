#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	int a[1000][2];
	for (int i = 0; i < 1000; i++)
		a[i][1] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t - 1][0] = t;
		a[t - 1][1] += 1;
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < a[i][1]; j++) {
			cout << a[i][0] << " ";
		}
	}
	return 0;
}