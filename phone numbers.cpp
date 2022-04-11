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
	vector<string> qwe;
	string l;
	int num = 0;
	for (int i = 0; i <= 3; i++) {
		cin >> l;
		qwe.push_back(l);
	}
	for (int y = 0; y<qwe.size(); y++) {
		if (qwe[y][0] == '+') {
			qwe[y][1] = '8';
			qwe[y].erase(qwe[y].begin(), qwe[y].begin()+1);
		}
		for (int i = 0; i < qwe[y].size();) {
			if (qwe[y][i] == '-' || qwe[y][i]== '(' || qwe[y][i]==')') {
				qwe[y].erase(qwe[y].begin() + i, qwe[y].begin() + i + 1);
				continue;
			}
			i++;
		}
	}
	for (int i = 1; i < qwe.size(); i++) {
		if (qwe[0] == qwe[i])
			cout << "YES"<<endl;
		else {
			l = qwe[0];
			if ((qwe[0].size() > qwe[i].size())&&(qwe[0][1]=='4') && (qwe[0][2] == '9') && (qwe[0][3] == '5')) {
				l.erase(l.begin(), l.begin() + 4);
				if (l == qwe[i])
					cout << "YES"<<endl;
				else { cout << "NO"<<endl; }
				l = qwe[0];
			}
			else {
				if ((qwe[i][1] == '4') && (qwe[i][2] == '9') && (qwe[i][3] == '5')) {
					qwe[i].erase(qwe[i].begin(), qwe[i].begin() + 4);
					if (l == qwe[i])
						cout << "YES" << endl;
					else { cout << "NO" << endl; }
				}
				else { cout << "NO" << endl; }
			}
		}
	}
}