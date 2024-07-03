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

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

const long int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) {
        cin >> nums[i];
    }
    int l = 0, r = nums.size();
    while (r - l > 1) {
        int m = l + ((r - l) / 2);
        if (nums[m] < nums[l]) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << nums[(l + 1) % nums.size()];

    return 0;
}