//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main() {
    int n, k, it1 = 0, it2 = 0;
    size_t tmp, ans = 0, counter = 0;
    scanf("%d%d", &n, &k);
    vector<int> v(n), arr(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    while (true) {
        ans += v[it2];
        if (arr[v[it2]] == 0 && v[it2] >= 1 && v[it2] <= k) {
            ++counter;
        }
        ++arr[v[it2]];
        if (counter == k) {
            break;
        }
        ++it2;
    }
    tmp = ans;
    while (true) {
        if ((v[it1] >= 1 && v[it1] <= k && arr[v[it1]] > 1) || (v[it1] > k)) {
            --arr[v[it1]];
            tmp -= v[it1];
            ans = min(ans, tmp);
            ++it1;
        }
        else {
            ++it2;
            if (it2 == n) {
                break;
            }
            tmp += v[it2];
            ++arr[v[it2]];
        }
    }
    cout << ans;
    return 0;
}