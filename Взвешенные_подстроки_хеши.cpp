#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

/*
В строках длины 1 есть два повторяющихся элемента - a и b. 
Назовём весом подстрок длины L произведение максимального количества повторяющихся подстрок этой длины на длину L.
В нашем случае вес длины 1 есть 2 (2·1), длины 2 есть 4 (2·2), длины 3 - 3 (1·3), длины 4 - 4 и длины 5 - 5.
*/

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull mod = 555555643;
ull p = 13463;
vector<ull> pows;
vector<ull> hshs;

inline void mkpows(unsigned long long sz) {
	pows.resize(sz);
	hshs.resize(sz);
	pows[0] = 1;
	pows[1] = p;
	for (ull i = 2; i < sz; ++i) {
		pows[i] = (pows[i - 1] * p) % mod;
	}
}

inline unsigned long long gethash(ull& it1, ull& it2) {
	if (it1 == 0) {
		return hshs[it2];
	}
	else {
		return (hshs[it2] - ((hshs[it1 - 1] * pows[it2 - it1 + 1]) % mod) + mod) % mod;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	unordered_map<ull, ull> a;
	ull ans = 0;
	string s;
	cin >> s;
	mkpows(s.size());
	hshs[0] = s[0];
	for (ull i = 1; i < s.size(); ++i) {
		hshs[i] = (hshs[i - 1] * p + s[i]) % mod;
	}
	for (ull sz = 1; sz <= s.size(); ++sz) {
		ull tmp;
		ull counter = 1;
		ull it1 = 0;
		ull it2 = it1 + sz - 1;
		while (it2 < s.size()) {
			tmp = gethash(it1, it2);
			if (a.find(tmp) != a.end()) {
				a[tmp]++;
				counter = max(counter, a[tmp]);
			}
			else {
				a[tmp] = 1;
			}
			it1++;
			it2++;
		}
		ans = max(ans, counter * sz);
		a.clear();
	}
	cout << ans;
	return 0;
}