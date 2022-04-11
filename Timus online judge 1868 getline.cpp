#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
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


//https://acm.timus.ru/problem.aspx?space=1&num=1868


using namespace std;

bool empt(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, best = 0, num_best = 0, counter;
    vector<pair<string, int>> a(12);
    for (int i = 0; i < 12; ++i) {
        cin >> a[i].first;
        if (i<4)
            a[i].second = 1;
        else if(i<8)
            a[i].second = 2;
        else {
            a[i].second = 3;
        }
    }
    cin >> n;
    for (int t = 0; t < n; t++) {
        int k;
        counter = 0;
        cin >> k;
        for (int u = 0; u < k; u++) {
            bool was_name = false;
            string main;
            string s = "";
            string s2 = "";
            getline(cin, main);
            if (empt(main)) {
                u--;
                continue;
            }
            for (int i = 0; i < main.size(); i++) {
                if (main[i] == ' ' && !was_name) {
                    was_name = true;
                }
                else if (main[i] != ' ' && main[i] != ':') {
                    if (!was_name) {
                        s += main[i];
                    }
                    else {
                        s2 += main[i];
                    }
                }
            }
            int place = 0;
            for (int j = 0; j < 12; j++) {
                if (a[j].first == s) {
                    place = a[j].second;
                    break;
                }
            }
            if (s2[0] == 'g' && place == 1)
                counter++;
            else if (s2[0] == 's' && place == 2)
                counter++;
            else if (s2[0] == 'b' && place == 3)
                counter++;
        }
        if (counter > best) {
            num_best = 1;
            best = counter;
        }
        else if (counter == best) {
            num_best++;
        }
    }
    cout << num_best*5;
    return 0;
}