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
    int n, m;
    int b, e, w;
    size_t ans = 0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> gr(n);
    vector<bool> used(n, false);
    vector<int> dist(n, INF);
    for (int i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        gr[b - 1].push_back({ e - 1, w });
        gr[e - 1].push_back({ b - 1, w });
    }

    set<pair<int, int>> best;
    dist[0] = 0;
    best.insert({ 0, 0 });
    for (int i = 0; i < n; ++i) {
        auto pr = *best.begin();
        best.erase(best.begin());
        ans += dist[pr.second];
        dist[pr.second] = 0;
        for (auto& el : gr[pr.second]) {
            if (el.second < dist[el.first]) {
                best.erase({ dist[el.first], el.first });
                dist[el.first] = el.second;
                best.insert({ dist[el.first], el.first });
            }
        }
    }
    cout << ans;

    return 0;
}