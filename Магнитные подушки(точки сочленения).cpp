#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<vector<int>> gr;
vector<int> tin, up;
vector<bool> used;
vector<bool> ans;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    int kids = 0;
    tin[v] = timer;
    up[v] = timer;
    timer++;
    for (int i : gr[v]) {
        if (!used[i]) {
            dfs(i, v);
            up[v] = min(up[v], up[i]);
            if (p != -1 && up[i] >= tin[v]) {
                ans[v] = true;
            }
            kids++;
        }
        else {
            up[v] = min(up[v], tin[i]);
        }
    }
    if (p == -1 && kids > 1) {
        ans[v] = true;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
    gr.resize(n + m);
    tin.resize(n + m);
    up.resize(n + m);
    used.resize(n + m);
    ans.resize(n + m);
    timer = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        gr[x].push_back(n + i);
        gr[y].push_back(n + i);
        gr[z].push_back(n + i);
        gr[n + i].push_back(x);
        gr[n + i].push_back(y);
        gr[n + i].push_back(z);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    int count = 0;
    for (int i = n; i < n + m; ++i) {
        if (ans[i]) {
            count++;
        }
    }
    cout << count << endl;
    for (int i = n; i < n + m; ++i) {
        if (ans[i]) {
            cout << i - n + 1 << ' ';
        }
    }
    cout << endl;
	return 0;
}