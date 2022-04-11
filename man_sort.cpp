#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

struct Man {
	string name, surname;
	double avg_sc;
	Man(string surname, string name, int a, int b, int c):name(name), surname(surname), avg_sc((double)(a+b+c)/3) {}
};

bool cmp(const Man& A, const Man& B) {
	return A.avg_sc > B.avg_sc;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<Man> m;
	m.reserve(n);
	for (int i = 0; i < n; i++) {
		string sn, nm;
		int a, b, c;
		cin >> sn >> nm >> a >> b >> c;
		m.push_back(Man(sn, nm, a, b, c));
	}
	stable_sort(m.begin(), m.end(), cmp);
	for (auto& man : m)
		cout << man.surname << " " << man.name << endl;
	//the second solution is down here
	/*int n, t;
	double  f = 0;
	string s, y;
	cin >> n;
	vector<pair<pair<string, string>, double>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		for (int o = 0; o < 3; o++) {
			cin >> t;
			f += (double)t;
		}
		f /= 3;
		a[i].first.first = s;
		a[i].first.second = y;
		a[i].second = f;
	}
	stable_sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i].first.first<<" "<<a[i].first.second<<endl;
	}*/
	return 0;
}