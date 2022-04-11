#include <iostream>
#include <iterator>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
	return a + b > b + a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	vector<string> a;
	while (cin >> s)
		a.push_back(s);
	s = "";
	sort(a.begin(), a.end(), cmp);
	for (string h : a)
		s += h;
	cout << s;
	return 0;
}