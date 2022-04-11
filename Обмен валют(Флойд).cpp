#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<double>> gr(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double l;
			cin >> l;
			gr[i][j] = l;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				gr[i][j] = max(gr[i][j], gr[i][k] * gr[k][j]);
			}
		}
	}
	double ans = 1;
	for (int i = 0; i < n; i++)
			if (gr[i][i] > ans)
				ans = gr[i][i];
	if (ans == 1)
		cout << "NO";
	else {
		cout << "YES";
	}
	return 0;
}