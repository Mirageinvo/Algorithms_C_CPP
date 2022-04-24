#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void mk_z_func(vector<size_t>& z, const string& s) {
    size_t l = 0, r = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<size_t> z(s.size(), 0);
    mk_z_func(z, s);
    for (auto&& el : z) {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}