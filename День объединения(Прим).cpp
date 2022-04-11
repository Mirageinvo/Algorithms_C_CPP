#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> gr(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        gr[i] = { x, y };
    }
    ld ans = 0;
    vector<bool> used(n);
    vector<ld> d(n, INF);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (pos == -1 || d[pos] > d[j]))
                pos = j;
        }
        used[pos] = true;
        ans += d[pos];
        for (int j = 0; j < n; j++) {
            ld dist = sqrt((gr[pos].first - gr[j].first) * (gr[pos].first - gr[j].first) + (gr[pos].second - gr[j].second) * (gr[pos].second - gr[j].second));
            if (j != pos && d[j] >= dist)
                d[j] = dist;
        }
    }
    cout.precision(15);
    cout << ans;
    return 0;
}