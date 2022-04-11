#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/*
Назовём повторяющейся подстрокой строки s непрерывную подстроку строки, встречающуюся два или более раза.
Пример: abracadabra -----> abra
*/

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

unsigned long long mod = 111111361;
unsigned long long p = 3121;
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
	unordered_set<ull> a;
	string s;
	cin >> s;
	mkpows(s.size());
	hshs[0] = s[0];
	for (ull i = 1; i < s.size(); ++i) {
		hshs[i] = (hshs[i - 1] * p + s[i]) % mod;
	}
	for (ull sz = s.size() - 1; sz >= 1; --sz) {
		ull tmp;
		ull it1 = 0;
		ull it2 = it1 + sz - 1;
		while (it2 < s.size()) {
			tmp = gethash(it1, it2);
			if (a.find(tmp) != a.end()) {
				for (ull ind = it1; ind <= it2; ++ind) {
					printf("%c", s[ind]);
				}
				return 0;
			}
			a.insert(tmp);
			it1++;
			it2++;
		}
		a.clear();
	}
	return 0;
}