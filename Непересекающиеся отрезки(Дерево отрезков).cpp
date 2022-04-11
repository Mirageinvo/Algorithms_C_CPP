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

int n, ind = 1;
const int INF = 1e9;
pair<int, int> gr[110000];
const int SIZE = 110000;
int t[SIZE * 4], ch[SIZE * 4];
bool isch[SIZE * 4];

void push(int v) {
    if (isch[v]) {
        ch[v * 2 + 1] = ch[v];
        ch[v * 2 + 2] = ch[v];
        isch[v * 2 + 1] = true;
        isch[v * 2 + 2] = true;
        isch[v] = false;
    }
}

void update(int v) {
    t[v] = max(isch[v * 2 + 1] ? ch[v * 2 + 1] : t[v * 2 + 1], isch[v * 2 + 2] ? ch[v * 2 + 2] : t[v * 2 + 2]);
}

int ask(int v, int l, int r, int askl, int askr) {
    if (l >= askr || r <= askl)
        return -INF;
    if (l >= askl && r <= askr)
        return (isch[v] ? ch[v] : t[v]);
    push(v);
    int m = l + (r - l) / 2;
    int ans=max(ask(v * 2 + 1, l, m, askl, askr), ask(v * 2 + 2, m, r, askl, askr));
    update(v);
    return ans;
}

void crg(int v, int l, int r, int al, int ar, int val) {
    if (l >= ar || r <= al)
        return;
    if (l >= al && r <= ar) {
        ch[v] = val;
        isch[v] = true;
        return;
    }
    push(v);
    int m = l + (r - l) / 2;
    crg(v * 2 + 1, l, m, al, ar, val);
    crg(v * 2 + 2, m, r, al, ar, val);
    update(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int askl, askr;
            cin >> askl >> askr;
            int ans = ask(0, 0, n, askl - 1, askr);
            if (ans == 0) {
                crg(0, 0, n, askl - 1, askr, ind);
                gr[ind].first = askl;
                gr[ind].second = askr;
                ind++;
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            int in;
            cin >> in;
            int ans = ask(0, 0, n, in - 1, in);
            if (ans == 0)
                cout << 0 << " " << 0 << endl;
            else {
                crg(0, 0, n, gr[ans].first - 1, gr[ans].second, 0);
                cout << gr[ans].first << " " << gr[ans].second << endl;
            }
        }
    }
    return 0;
}