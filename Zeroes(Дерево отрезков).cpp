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

struct Vert {
    int max, maxl, maxr;
    bool nz;
    Vert(){}
    Vert(int max, int maxl, int maxr, bool nz) : max(max), maxl(maxl), maxr(maxr), nz(nz) {};
};

vector<int> a;
const int SIZE = 500010;
Vert t[SIZE * 4];
Vert neutral = Vert(0, 0, 0, true);

Vert f(const Vert& fir, const Vert& sec) {
    Vert ver = Vert();
    ver.nz = (fir.nz || sec.nz);
    ver.maxl = max(fir.maxl, (fir.nz ? -1 : fir.max + sec.maxl));
    ver.maxr = max(sec.maxr, (sec.nz ? -1 : sec.max + fir.maxr));
    ver.max = max({ fir.maxr + sec.maxl, fir.max, sec.max, ver.maxl, ver.maxr });
    return ver;
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        t[v] = Vert((a[l] == 0 ? 1 : 0), (a[l] == 0 ? 1 : 0), (a[l] == 0 ? 1 : 0), (a[l] == 0 ? false : true));
        return;
    }
    int m = l + (r - l) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = f(t[v * 2 + 1], t[v * 2 + 2]);
}

Vert ask(int v, int l, int r, int al, int ar) {
    if (l >= ar || r <= al)
        return neutral;
    if (l >= al && r <= ar)
        return t[v];
    int m = l + (r - l) / 2;
    return f(ask(v * 2 + 1, l, m, al, ar), ask(v * 2 + 2, m, r, al, ar));
}

void change(int v, int l, int r, int ind, int val) {
    if (r - l == 1) {
        t[v]= Vert((val == 0 ? 1 : 0), (val == 0 ? 1 : 0), (val == 0 ? 1 : 0), (val == 0 ? false : true));
        return;
    }
    int m = l + (r - l) / 2;
    if (ind >= m) {
        change(v * 2 + 2, m, r, ind, val);
    }
    else {
        change(v * 2 + 1, l, m, ind, val);
    }
    t[v] = f(t[v * 2 + 1], t[v * 2 + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(0, 0, n);
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        if (s == "UPDATE") {
            int pos, val;
            cin >> pos >> val;
            change(0, 0, n, pos - 1, val);
        }
        else {
            int al, ar;
            cin >> al >> ar;
            cout << ask(0, 0, n, al - 1, ar).max << endl;
        }
    }
    return 0;
}