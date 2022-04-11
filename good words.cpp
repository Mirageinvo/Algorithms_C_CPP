#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

char l[6] = { 'o', 'i', 'a', 'e', 'u', 'y' };
bool check(char a) {
	for (char y : l) {
		if (a == y)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	string word;
	int num_vowel, num_cons, total;
	num_vowel = 0;
	num_cons = 0;
	total = 0;
	cin >> word;
	if (check(word[word.size() - 1]))
		word.push_back('b');
	else {
		word.push_back('a');
	}
	for (int i = 0; i < word.size(); i++) {
		if (check(word[i])) {
			num_vowel++;
			if (num_cons>2 && num_cons % 2 == 0) {
				total += (num_cons / 2) - 1;
			}
			else {
				if (num_cons>2)
					total += num_cons / 2;}
			num_cons = 0;
		}
		else {
			num_cons++;
			if (num_vowel>2 && num_vowel%2==0)
				total += (num_vowel / 2) - 1;
			else {
				if (num_vowel>2)
					total += num_vowel / 2;}
			num_vowel = 0;
		}
	}
	cout << total;
}