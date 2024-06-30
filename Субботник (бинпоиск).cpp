#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long int INF = 1e9;

bool good(const vector<int>& v, int m, int r, int c) {
    int begin = 0;
    for (int k = 0; k < r; ++k) {
        while (begin + c - 1 < v.size() && v[begin + c - 1] - v[begin] > m) {
            begin++;
        }
        if (begin + c - 1 >= v.size()) {
            return false;
        }
        begin += c;
    }
    return true;

    // Another way:

    /*int i = 0;
    int count = 0;
    while (i + c - 1 < v.size()) {
        if (v[i + c - 1] - v[i] <= m) {
            count++;
            i += c;
        }
        else {
            i++;
        }
    }
    return count >= r;*/
}

int main() {
    int n, r, c;
    cin >> r >> c;
    n = r * c;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int left = -1, right = v[n - 1] - v[0];
    while (right - left > 1) {
        int m = left + ((right - left) / 2);
        if (good(v, m, r, c)) {
            right = m;
        }
        else {
            left = m;
        }
    }
    cout << right;
    return 0;
}
