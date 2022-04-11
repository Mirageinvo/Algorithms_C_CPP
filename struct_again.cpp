#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Person{
	string first_name, lst_name;
	char grade_letter;
	int grade, day, month, year;
};
std::istream& operator>>(std::istream &in, Person &A) {
	in >> A.lst_name >> A.first_name;
	scanf("%d%c", &A.grade, &A.grade_letter);
	scanf("%d.%d.%d", &A.day, &A.month, &A.year);
	return in;
}
std::ostream& operator<<(std::ostream& out, const Person& A) {
	printf("%d%c ", A.grade, A.grade_letter);
	out << A.lst_name << " " << A.first_name << " ";
	printf("%d.%d.%d", A.day, A.month, A.year);
	return out;
}
bool operator>(const Person& A, const Person& B){
	if(A.grade==B.grade) {
		if (A.grade_letter == B.grade_letter) {
			return A.lst_name > B.lst_name;
		}
		else {
			return A.grade_letter > B.grade_letter;
		}
	}
	else {
		return A.grade > B.grade;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <Person>	lst(n);
	for (int i = 0; i < n; i++)
		cin >> lst[i];
	for (int i = 1; i <= n-1; i++) {
		for (int j = 0; j<n-i; j++) {
			if (lst[j] > lst[j + 1])
				swap(lst[j], lst[j + 1]);
		}
	}
	for (Person A : lst)
		cout << A << endl;
}