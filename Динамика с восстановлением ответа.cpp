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
	ll n;
	cin >> n;
	vector<ll> a(n * 3, 1e9);
	vector<ll> anc(n * 3, -1);
	a[1] = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] + 1 < a[i + 1]) {
			a[i + 1] = a[i] + 1;
			anc[i + 1] = 1;
		}
		if (a[i] + 1 < a[i * 2]) {
			a[i * 2] = a[i] + 1;
			anc[i * 2] = 2;
		}
		if (a[i] + 1 < a[i * 3]) {
			a[i * 3] = a[i] + 1;
			anc[i * 3] = 3;
		}
	}
	vector<ll> ans;
	int i = n;
	while (anc[i] != -1) {
		if (anc[i] == 1) {
			ans.push_back(1);
			i--;
		}
		else if (anc[i] == 2) {
			ans.push_back(2);
			i /= 2;
		}
		else if (anc[i] == 3) {
			ans.push_back(3);
			i /= 3;
		}
	}
	//shows all numbers
	/*ll h = 1;
	cout << a[n] << endl;
	cout << h << " ";
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i] == 1)
			h++;
		else if (ans[i] == 2)
			h *= 2;
		else if (ans[i] == 3)
			h *= 3;
		cout << h << " ";
	}*/
	//shows the sequence of operations with numbers
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	return 0;
}