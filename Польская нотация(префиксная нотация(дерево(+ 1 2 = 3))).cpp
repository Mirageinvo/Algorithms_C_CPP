#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int oper = 0;

struct tree {
    tree* left = NULL;
    tree* right = NULL;
};

bool get_word(string& word) {
    word = "";
    bool ret = false;
    char c = '#';
    while (c != '\n' && c != ' ') {
        c = getchar();
        if (c != '\n' && c != ' ') {
            word += c;
        }
        if (c == '\n')
            ret = true;
    }
    return ret;
}

double count(double numf, double nums, char oper) {
    if (oper == '+') {
        return numf + nums;
    }
    if (oper == '-') {
        return numf - nums;
    }
    if (oper == '*') {
        return numf * nums;
    }
    if (oper == '/') {
        return numf / nums;
    }
    return 0;
}

double btree(struct tree* node, const vector<string>& w, int max_ind) {
    if (oper == max_ind) {
        return (double)stoi(w[oper]);
    }
    if (int(w[oper][0]) >= 48 && int(w[oper][0]) <= 57) {
        return (double)stoi(w[oper]);
    }
    else {
        int sgn = oper;
        node->left = (struct tree*)malloc(sizeof(struct tree));
        node->right = (struct tree*)malloc(sizeof(struct tree));
        oper++;
        double tmp_1 = btree(node->left, w, max_ind);
        oper++;
        double tmp_2 = btree(node->right, w, max_ind);
        return count(tmp_1, tmp_2, w[sgn][0]);
    }
}

int main() {
    int it = 0;
    string word = "#";
    bool stop = false;
    vector<string> w(1000);
    tree node;
    while (!stop) {
        stop = get_word(word);
        w[it++] = word;
    }
    cout << btree(&node, w, it - 1) << endl;
    return 0;
}