#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int m = 0, count = 0;
	bool l = true;
	cin >> n;
	while (m != 0 || l) {
		l = false;
		count++;
		m = (m * 10 + 1) % n;
		if (count >= 50000000) {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 1; i <= count; i++)
		cout << 1;
	return 0;
}