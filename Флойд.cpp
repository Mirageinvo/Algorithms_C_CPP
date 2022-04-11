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
	int n, s, t;
	cin >> n >> s >> t;
	s--;
	t--;
	vector<vector<int>> gr(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			if (k!=-1 && i!=j)
				gr[i][j] = k;
			else {
				gr[i][j] = INF;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
			}
		}
	}
	cout << (gr[s][t] == INF ? -1 : gr[s][t]);
	return 0;
}