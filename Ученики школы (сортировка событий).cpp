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

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back({ p.first, -1 });
        v.push_back({ p.second, 1 });
    }
    sort(v.begin(), v.end());
    int ward_count = 0;
    int ans = v[0].first;
    for (int i = 0; i < v.size(); ++i) {
        if (ward_count == 0 && i != 0) {
            ans += v[i].first - v[i - 1].first - 1;
        }
        if (v[i].second == -1) {
            ward_count++;
        }
        else {
            ward_count--;
        }

    }
    ans += n - v[v.size() - 1].first - 1;
    cout << ans;
    return 0;
}
