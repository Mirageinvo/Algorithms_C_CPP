#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    cin.tie(0);
    cout.tie(0);
    size_t n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    if (n == 2) {
        cout << arr[1] - arr[0];
        return 0;
    }
    else if (n == 3) {
        cout << arr[2] - arr[0];
        return 0;
    }
    dp[1] = arr[1] - arr[0];
    dp[2] = arr[2] - arr[0];
    for (int i = 3; i < n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + arr[i] - arr[i - 1];
    }
    cout << dp[n - 1];
    return 0;
}