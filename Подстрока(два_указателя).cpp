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

/*
    В этой задаче Вам требуется найти максимальную по длине подстроку данной строки,
    такую что каждый символ встречается в ней не более k раз.
*/

bool goodString(const vector<int>& v, int k) {
    for (auto& el : v) {
        if (el > k) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    ll best_len = 0;
    int best_ind = 0;
    cin >> n >> k;
    vector<int> v(26, 0);
    string s;
    cin >> s;
    int i = 0, ind = 0;
    while (true) {
        while (ind < n && goodString(v, k)) {
            v[s[ind] - 'a']++;
            ind++;
        }
        if (ind - i - !goodString(v, k) > best_len) {
            best_len = ind - i - !goodString(v, k);
            best_ind = i;
        }
        while (!goodString(v, k)) {
            v[s[i] - 'a']--;
            i++;
        }
        if (ind == n && goodString(v, k)) {
            if (ind - i > best_len) {
                best_len = ind - i;
                best_ind = i;
            }
            break;
        }
    }
    cout << best_len << " " << best_ind + 1;
    return 0;
}
