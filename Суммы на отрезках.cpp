#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> s(n + 1);
    for (int i = 0; i < n; ++i)
        s[i + 1] = s[i] + a[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
	return 0;
}