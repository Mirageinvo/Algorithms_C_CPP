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

// https://informatics.msk.ru/mod/statements/view.php?chapterid=98#1

const long int INF = 1e9;

bool cycle = false;
vector<vector<int>> gr;
vector<int> color;

void dfs(int u) {
    if (cycle == true) {
        return;
    }
    color[u] = 1;
    for (auto& v : gr[u]) {
        if (color[v] == 1) {
            cycle = true;
            return;
        }
        else if (color[v] == 0) {
            dfs(v);
        }
    }
    color[u] = 2;
}

int main() {
    int n;
    int u, v;
    cin >> n;
    gr.resize(n + 1);
    color.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> u;
            if (u == 1) {
                gr[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
        if (cycle) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
