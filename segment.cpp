#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
    vector <pair <int, int> > events;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        events.push_back(make_pair(l, -1));
        events.push_back(make_pair(r, 1));
    }
    sort(events.begin(), events.end());
    vector <int> ans;
    int count = 0;
    for (auto event : events)
    {
        int x = event.first;
        int type = event.second;
        count -= type;
        if (count == 0 || count == 1 && type == -1)
            ans.push_back(x);
    }
    cout << ans.size() / 2 << endl;
    for (int i = 0; i < ans.size(); i += 2)
        cout << ans[i] << " " << ans[i + 1] << endl;
	return 0;
}