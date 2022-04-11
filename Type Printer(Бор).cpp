/*#include <iostream>
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

struct node {
    ll num;
    bool flag;
    node* next[26];
    node() {
        flag = false;
        num = 0;
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};

node head;
string an = "";
ll ans = 0;

void push(const string& word) {
    ll n = word.size();
    node* to = &head;
    for (int q = 0; q < n; q++) {
        if (to->next[word[q] - 'a'] == nullptr)
            to->next[word[q] - 'a'] = new node;
        to->num = max(n - q - 1, to->num);
        if (q == n - 1)
            to->next[word[q] - 'a']->flag = true;
        to = to->next[word[q] - 'a'];
    }
}

void get(node* v) {
    ll ind = -1;
    ll maxx = 0;
    for (int i = 0; i < 26; i++) {
        if (v->next[i] != nullptr && maxx < v->next[i]->num) {
            ind = i;
            maxx = v->next[i]->num;
        }
    }
    if (v->flag) {
        ans++;
        an += 'P';
    }
    for (int i = 0; i < 26; i++) {
        if (i != ind && v->next[i] != nullptr) {
            an += (char)(i + 'a');
            ans++;
            get(v->next[i]);
            ans++;
            an += '-';
        }
    }
    if (ind != -1 && v->next[ind] != nullptr) {
        an += (char)(ind + 'a');
        ans++;
        get(v->next[ind]);
        ans++;
        an += '-';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        b = max(b, (ll)w.size());
        push(w);
    }
    node* v = &head;
    get(v);
    cout << ans - b << endl;
    for (int i = 0; i < an.size() - b; i++)
        printf("%c\n", an[i]);
    return 0;
}*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

struct node {
    node* next[26];
    long x;
    long flag;
    node() {
        x = 0;
        flag = 0;
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};

node head;

void push(string s) {
    node* v = &head;
    long sizen = s.size();
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (v->next[c] != nullptr) {
            v = v->next[c];
            v->x = max(v->x, sizen - i - 1);
            if (i == s.size() - 1)
                v->flag = 1;
        }
        else {
            v->next[c] = new node;
            v = v->next[c];
            v->x = sizen - i - 1;
            if (i == s.size() - 1)
                v->flag = 1;
        }
    }
}

string ans = "";

void get(node* v) {
    node* v1 = &head;
    long max1 = 0, ind = -1;
    for (int i = 0; i < 26; i++) {
        if (v->next[i] != nullptr) {
            v1 = v->next[i];
            if (v1->x > max1) {
                max1 = v1->x;
                ind = i;
            }
        }
    }
    if (v->flag == 1)
        ans += 'P';
    for (int i = 0; i < 26; i++) {
        if (v->next[i] != nullptr && i != ind) {
            ans += char(i + 'a');
            v1 = v->next[i];
            get(v1);
            ans += '-';
        }
    }
    if (ind != -1) {
        ans += char(ind + 'a');
        v1 = v->next[ind];
        get(v1);
        ans += '-';
    }
}

int main() {
    long n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        push(s);
    }
    node* v = &head;
    get(v);
    int i;
    for (i = ans.size() - 1; i >= 0; i--)
        if (ans[i] != '-') break;
    printf("%d\n", i + 1);
    for (int j = 0; j <= i; j++)
        printf("%c\n", ans[j]);
}