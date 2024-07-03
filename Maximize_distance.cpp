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

// https://leetcode.com/problems/maximize-distance-to-closest-person/description/

using namespace std;

const long int INF = 1e9;

int main() {
    int n, ans = 0;
    cin >> n;
    int tmp;
    int first = -1, next = -1;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp == 1 && first == -1) {
            first = i;
            ans = max(ans, i);
        }
        else if (tmp == 1) {
            if (next != -1) {
                first = next;
            }
            next = i;
            ans = max(ans, (next - first) / 2);
        }

    }
    if (next != -1) {
        ans = max(ans, n - next - 1);
    }
    else {
        ans = max(ans, n - first - 1);
    }
    cout << ans << endl;

    return 0;
}