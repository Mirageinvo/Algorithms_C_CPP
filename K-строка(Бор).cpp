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

struct Node {
    Node* next[26];
    bool flag;
    Node() {
        flag = false;
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};

Node head;
ll power[10];

int tonum(const string& s) {
    ll ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        ans += ll(s[i] - '0') * power[n - i - 1];
    }
    return ans;
}

void push(const string& s) {
    int n = s.size();
    Node* to = &head;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (to->next[c] == nullptr)
            to->next[c] = new Node;
        if (i == n - 1)
            to->next[c]->flag = true;
        to = to->next[c];
    }
}

ll k, counter = 0;
bool got = false, used = false;
string st;

void get_word(Node* to, string word) {
    if (to->flag)
        counter++;
    if (counter == k)
        got = true;
    if (got && !used) {
        st = word;
        used = true;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (to->next[i] != nullptr) {
            word+=(char)(i + 'a');
            get_word(to->next[i], word);
            word.pop_back();
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    power[0] = 1;
    for (int i = 1; i <= 9; i++) {
        power[i] = power[i - 1] * 10;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!isdigit(s[0])) {
            push(s);
        }
        else {
            k = tonum(s);
            string word="";
            get_word(&head, word);
            printf("%s\n", st.c_str());
            got = false;
            used = false;
            counter = 0;
        }
    }
    return 0;
}