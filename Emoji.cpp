#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

char a[] = { ')', '(', '[', ']' };
char b[] = { ')', '(', '[', ']', ':', ';', '-'};

bool check_f(char w) {
	for (char u : b) {
		if (w == u)
			return true;
	}
	return false;
}

bool check(char t) {
	for (char u : a) {
		if (t == u)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	int a, b, c;
	string word;
	int com = 0;
	a = 0;
	b = 0;
	getline(cin, word);
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == '-'){
			if (i==0)
				word.erase(word.begin() + i, word.begin() + i + 1);
			else {
				word.erase(word.begin() + i, word.begin() + i + 1);
				i--;
			}
		}
		if (word[i] == ';')
			word[i] = ':';
		if (word[i] == '(' && word[i + 1] == '(') {
			word.erase(word.begin() + i, word.begin() + i + 1);
			i--;
		}
		if (word[i] == ')' && word[i + 1] == ')') {
			word.erase(word.begin() + i, word.begin() + i + 1);
			i--;
		}
		if (word[i] == '[' && word[i + 1] == '[') {
			word.erase(word.begin() + i, word.begin() + i + 1);
			i--;
		}
		if (word[i] == ']' && word[i + 1] == ']') {
			word.erase(word.begin() + i, word.begin() + i + 1);
			i--;
		}
		if ((word[i] == ';' || word[i] == ':') && (word[i + 1] == ';' || word[ i + 1 ]== ':' )) {
			word.erase(word.begin() + i, word.begin() + i + 1);
			i--;
		}
	}
	for (int i = 0; i < word.size(); i++) {
		if ((word[i] == ':' || word[i] == ';') && a == 0 && b == 0) {
			a = 1;
			continue;
		}
		else if (check(word[i]) && a==1) {
			com++;
			a = 0;
			b = 0;
			continue;
		}
		else {
			a = 0;
			b = 0;
			continue;
		}
	}
	cout << com;
}