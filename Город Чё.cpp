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

int n, r;
ll ans = 0;

int getNewInd(const vector<int>& v, int ind1, int prev) {
    int left = prev - 1, right = v.size();
    while (right - left > 1) {
        int m = left + ((right - left) / 2);
        if (v[m] - v[ind1] > r) {
            right = m;
        }
        else {
            left = m;
        }
    }
    return right;
}

int main() {
    cin >> n >> r;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ind = 1;
    for (int i = 0; i < n; ++i) {
        ind = getNewInd(v, i, ind);
        ans += n - ind;
    }
    cout << ans;
    return 0;
}
