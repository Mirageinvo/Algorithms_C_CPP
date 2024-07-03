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

// https://leetcode.com/problems/trapping-rain-water/description/

const long int INF = 1e9;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    int mx = -INF;
    int mxInd = -1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] > mx) {
            mx = v[i];
            mxInd = i;
        }
    }
    int leftMx = v[0];
    for (int i = 1; i < mxInd; ++i) {
        if (leftMx > v[i]) {
            ans += leftMx - v[i];
        }
        else {
            leftMx = v[i];
        }
    }
    int rightMx = v[v.size() - 1];
    for (int i = v.size() - 2; i > mxInd; --i) {
        if (rightMx > v[i]) {
            ans += rightMx - v[i];
        }
        else {
            rightMx = v[i];
        }
    }
    cout << ans << endl;

    return 0;
}