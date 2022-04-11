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

const long long MOD1 = 1000000007;
const long long BASE1 = 2017;

const long long MOD2 = 1000000009;
const long long BASE2 = 1000003;

const int MAX = 100005;

long long pow1[MAX];
long long pow2[MAX];
long long pref_s1[MAX];
long long pref_s2[MAX];
long long pref_t1[MAX];
long long pref_t2[MAX];

void precalc(const string& s, long long* prefix, long long mod, long long base)
{
    prefix[0] = 0;
    for (int i = 0; i < s.size(); ++i)
        prefix[i + 1] = (prefix[i] * base + s[i]) % mod;
}

long long get_hash(int i, int j, long long* prefix, long long* pow, long long mod, long long base){
    return (prefix[j] - prefix[i - 1] * pow[j - i + 1] % mod + mod) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string s, t;
    cin >> s;
    precalc(s, pref_s1, MOD1, BASE1);
    precalc(s, pref_s2, MOD2, BASE2);
    cin >> t;
    precalc(t, pref_t1, MOD1, BASE1);
    precalc(t, pref_t2, MOD2, BASE2);
    pow1[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i < MAX; ++i)
    {
        pow1[i] = pow1[i - 1] * BASE1 % MOD1;
        pow2[i] = pow2[i - 1] * BASE2 % MOD2;
    }
    int left = 0;
    int right = min(s.size(), t.size()) + 1;
    while (right - left > 1)
    {
        int len = (left + right) / 2;
        set <pair<long long, long long> > hashes;
        for (int i = 1, j = len; j <= s.size(); ++i, ++j)
        {
            hashes.insert(make_pair(
                get_hash(i, j, pref_s1, pow1, MOD1, BASE1),
                get_hash(i, j, pref_s2, pow2, MOD2, BASE2)));
        }
        bool common_substr_found = false;
        for (int i = 1, j = len; j <= t.size(); ++i, ++j)
            if (hashes.count(make_pair(
                get_hash(i, j, pref_t1, pow1, MOD1, BASE1),
                get_hash(i, j, pref_t2, pow2, MOD2, BASE2)))) {
                common_substr_found = true;
                break;
            }
        if (common_substr_found)
            left = len;
        else
            right = len;
    }
    cout << left << endl;
	return 0;
}