#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>

using namespace std;

int main() {
	queue<int> first;
	deque<int> second;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		int t;
		cin >> a;
		if (a == '+') {
			cin >> t;
			second.push_back(t);
		}
		else if (a == '*') {
			cin >> t;
			second.push_front(t);
		}
		else if (a == '-') {
			cout << first.front()<<endl;
			first.pop();
		}
		if (first.size() < second.size()) {
			first.push(second.front());
			second.pop_front();
		}
	}
	return 0;
}