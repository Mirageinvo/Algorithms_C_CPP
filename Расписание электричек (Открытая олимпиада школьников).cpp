#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct TreeVertex {
    vector <long> edge;
    long color;
    bool used;
};

struct Train {
    long long int a, b, c, d;
};

vector <long> ans;

void dfs2(int v, vector <TreeVertex>& g) {
    g[v].used = true;
    for (int i = 0; i < g[v].edge.size(); i++) {
        int to = g[v].edge[i];
        if (!g[to].used)
            dfs2(to, g);
    }
    ans.push_back(v);
}

void topological_sort(vector <TreeVertex>& g, long long int n) {
    for (int i = 0; i < n; i++)
        g[i].used = false;
    ans.clear();
    for (int i = 0; i < n; i++)
        if (!g[i].used)
            dfs2(i, g);
    reverse(ans.begin(), ans.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    long long int n;
    cin >> n;
    vector <Train> x(n);
    vector <TreeVertex> g(n);
    for (int i = 0; i < n; i++)
        cin >> x[i].a >> x[i].b >> x[i].c >> x[i].d;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i].b < x[j].a || x[j].b < x[i].a) continue;
            long long int st;
            if (x[j].a <= x[i].b && x[i].b <= x[j].b)
                st = x[i].b;
            if (x[j].a <= x[i].a && x[i].a <= x[j].b)
                st = x[i].a;
            if (x[i].a <= x[j].b && x[j].b <= x[i].b)
                st = x[j].b;
            if (x[i].a <= x[j].a && x[j].a <= x[i].b)
                st = x[j].a;
            long long int t1 = x[i].c + (st - x[i].a) * x[i].d;
            long long int t2 = x[j].c + (st - x[j].a) * x[j].d;
            if (t1 < t2)
                g[i].edge.push_back(j);
            if (t1 > t2)
                g[j].edge.push_back(i);
        }
    }
    topological_sort(g, n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
	return 0;
}