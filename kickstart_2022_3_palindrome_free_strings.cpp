#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

inline bool is_pal(string s) {
    if (s.size() % 2 == 0) {
        for (size_t i = 0; i * 2 < s.size(); ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
    }
    else {
        for (size_t i = 0; i * 2 < s.size() - 1; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int e, n;
    string s, tmp;
    cin >> e;
    for (size_t o = 1; o <= e; ++o) {
        cin >> n >> s;
        if (n < 5) {
            cout << "Case #" << o << ": POSSIBLE" << endl;
            continue;
        }
        vector<string> tmp = { "" };
        for (size_t i = 0; i < 5; ++i) {
            if (s[i] == '?') {
                vector<string> tmp_arr;
                for (auto& el : tmp) {
                    string ttt = el;
                    ttt += '0';
                    el += '1';
                    tmp_arr.push_back(ttt);
                }
                for (auto& el : tmp_arr) {
                    tmp.push_back(el);
                }
            }
            else {
                for (auto& el : tmp) {
                    el += s[i];
                }
            }
        }
        vector<string> arr;
        for (auto& el : tmp) {
            if (!is_pal(el)) {
                arr.push_back(el);
            }
        }
        if (arr.size() == 0) {
            cout << "Case #" << o << ": IMPOSSIBLE" << endl;
            continue;
        }
        for (size_t i = 5; i < s.size(); ++i) {
            if (s[i] == '?') {
                vector<string> tmp_arr;
                for (auto& el : arr) {
                    string ttt = (el + '0').substr(1, 5);
                    if (!is_pal(ttt) && !is_pal(el[0] + ttt)) {
                        tmp_arr.push_back(ttt);
                    }
                    ttt = (el + '1').substr(1, 5);
                    if (!is_pal(ttt) && !is_pal(el[0] + ttt)) {
                        tmp_arr.push_back(ttt);
                    }
                }
                swap(arr, tmp_arr);
            }
            else {
                vector<string> tmp_arr;
                for (auto& el : arr) {
                    string ttt = (el + s[i]).substr(1, 5);;
                    if (!is_pal(ttt) && !is_pal(el[0] + ttt)) {
                        tmp_arr.push_back(ttt);
                    }
                }
                swap(arr, tmp_arr);
            }
            if (arr.size() == 0) {
                cout << "Case #" << o << ": IMPOSSIBLE" << endl;
                goto jmp;
            }
        }
        cout << "Case #" << o << ": POSSIBLE" << endl;
        jmp: continue;
    }
    return 0;
}