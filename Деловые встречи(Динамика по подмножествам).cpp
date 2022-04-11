#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, k;
vector<pair<pair<int, int>, int>> a;

int count(int mask) {
    int sum = k;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))
            sum += a[i].second;
    return sum;
}

int num(int mask) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))
            sum += 1;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    vector<bool> dp(1 << n);
    vector<int> last((1 << n), -1);
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    dp[0] = true;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            //if (mask & (1 << i)) {
              int nmask = (mask ^ (1 << i));
              if (dp[nmask] && count(nmask) >= a[i].first.first && count(nmask) <= a[i].first.second) {
                  dp[mask] = true;
                  last[mask] = i;
              }
            //}
        }
    }
    int c = 0;
    int bmask = 0;
    vector<int> ans;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i] && num(i) > c) {
            c = num(i);
            bmask = i;
        }
    }
    while (last[bmask] != -1) {
        ans.push_back(last[bmask]);
        bmask ^= (1 << last[bmask]);
    }
    cout << c << endl;
    /*reverse(ans.begin(), ans.end());
    for (int h : ans)
        cout << h + 1 << " ";*/
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] + 1 << " ";
    return 0;
}