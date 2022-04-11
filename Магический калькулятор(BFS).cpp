#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int sum(int n) {
	int ans = 0;
	while (n != 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	vector<int> dist(10000, -1);
	dist[a] = 0;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vector<int> next;
		next.emplace_back(v * 3);
		next.emplace_back(v - 2);
		next.emplace_back(v + sum(v));
		for (int u : next) {
			if (u >= 0 && u <= 9999 && dist[u] == -1) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	cout << dist[b];
	return 0;
}