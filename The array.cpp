#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int a, k, d, i, j, s;
	cout << "Hello!!!\nPlease enter the number of digits in the array" << endl;
	cin >> a;
	const int t = 15;
	int nums[t];
	cout << "Enter numbers of array\n" << endl;
	for (k = 0; k < t; k++) {
		cin >> d;
		nums[k] = d;
	}
	for (k=1; k<=t-1; k++){
		for (j = 0; j < t - k; j++) {
			if (nums[j] >= nums[j + 1]) {
				s = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = s;
			}
		}
	}
	cout << "Now array is:\n| ";
	for (k = 0; k < t; k++) {
		cout << nums[k] <<" | ";
	}
	system("pause > nul");
	return 0;
}