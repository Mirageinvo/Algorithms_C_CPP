#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cctype>
#include <stack>
#include <cstdio>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const ld pi = 3.14159265358979323846;

vector<vector<int>> gr;

int count_paths(int v, int f) {
    if (v == f)
        return 1;
    else {
        int paths = 0;
        for (int u : gr[v])
            paths += count_paths(u, f);
        return paths;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        gr[v].push_back(u);
    }
    cout << count_paths(0, n - 1);
    return 0;
}