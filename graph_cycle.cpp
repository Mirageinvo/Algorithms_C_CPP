#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int INF = 1e9;

int n, best_length = -1;
vector<vector<int>> gr;
vector<int> col; // 0 - white, 1 - grey, 2 - black
vector<int> cycle;
vector<int> ans;


void dfs(int v, int p) {
    col[v] = 1;
    for (int i = 0; i < n; ++i) {
        if (i != v && i != p && gr[v][i] == 1) {
            if (col[i] == 1) { // Grey color means that we've encountered a cycle
                for (int j = cycle.size() - 1; j >= 0; --j) {
                    if (cycle[j] == i) {
                        if (((int)cycle.size() - j) > best_length) {
                            ans.clear(); // Remove previous cycle info
                            for (int q = cycle.size() - 1; q >= j; --q) {
                                ans.push_back(cycle[q]);
                            }
                            best_length = cycle.size() - j;
                        }
                        break;
                    }
                }
            }
            else if (col[i] == 0) {
                cycle.push_back(i);
                dfs(i, v);
                cycle.pop_back();
            }
        }
    }

    col[v] = 2;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin >> n;
    gr.resize(n, vector<int>(n));
    col.resize(n, 0);
    cycle.reserve(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            gr[i][j] = tmp;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            cycle.push_back(i);
            dfs(i, -1);
        }
    }
    if (best_length == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << best_length << endl;
        for (auto& el : ans) {
            cout << el + 1 << " ";
        }
    }
    return 0;
}