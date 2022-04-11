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
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> gr(n);
    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        gr[l - 1].push_back({ r - 1, k });
        gr[r - 1].push_back({ l - 1, k });
    }
    vector<int> d(n, INF);
    d[0] = 0;
    vector<bool> used(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (pos == -1 || d[pos] > d[j])) {
                pos = j;
            }
        }
        used[pos] = true;
        ans += d[pos];
        for (auto& edge : gr[pos]) {
            if (d[edge.first] > edge.second) {
                d[edge.first] = edge.second;
            }
        }
    }
    cout << ans;
    return 0;
}