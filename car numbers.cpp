#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*long long int num, let_b, let_a, s;
	num = 0;
	let_b = 0;
	let_a = 0;
	s = 0;
	string a;
	cin >> a;
	for (char i : a) {
		if (isdigit(i)) {
			num++;
			s++;
		}
		else {
			if (isupper(i)) {
				if (s == 0) {
					let_b++;
				}
				else { let_a++; }
			}
		}
	}
	if (let_b == 1 && num == 3 && let_a == 2 && a.size() == 6)
		cout << 1;
	else if (let_b == 2 && num == 3 && let_a == 0 && a.size() == 5)
		cout << 2;
	else if (let_b == 1 && num == 4 && let_a == 0 && a.size() == 5)
		cout << 3;
	else if (let_b == 0 && num == 4 && let_a == 2 && a.size() == 6)
		cout << 4;
	else { cout << 0; }*/

	//the second solution

	string s;
	cin >> s;
	for (int i=0;i<s.size();i++){
		if ('0' <= s[i] && s[i] <= '9')
			s[i] = '0';
		else { s[i] = 'A'; }
	}
	if (s == "A000AA")
		cout << 1;
	else if (s == "AA000")
		cout << 2;
	else if (s == "AA0000")
		cout << 3;
	else if (s == "0000AA")
		cout << 4;
	else { cout << 0; }
}