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
	cin >> n;
	vector<int> lp(n + 1);
	vector<int> pr;
	for (int i = 2; i <= n; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.emplace_back(i);
		}
		for (size_t j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
	for (int l : pr)
		cout << l << " ";
	/*int n;
	cin >> n;
	vector<bool> isprime(n + 1, true);
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isprime[i])
			cout << i << " ";
	}*/
	return 0;
}