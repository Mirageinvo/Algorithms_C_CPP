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

// https://leetcode.com/problems/continuous-subarray-sum/description/

const long int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    unordered_set<int> st;
    int prefsumrem = nums[0] % k;
    if (prefsumrem != 0) {
        st.insert(prefsumrem);
    }
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] % k == 0) {
            continue;
        }
        prefsumrem += nums[i];
        prefsumrem %= k;
        if (prefsumrem == 0) {
            cout << true;
            return 0;
        }
        if (st.find(prefsumrem) != st.end()) {
            cout << true;
            return 0;
        }
        st.insert(prefsumrem);
    }
    for (int i=0; i<n-1; ++i) {
        if (nums[i] % k == 0 && nums[i+1] % k == 0) {
            cout << true;
            return 0;
        }
    }
    cout << false;

    return 0;
}