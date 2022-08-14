#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> lp(n + 1, 0);
    vector<int> pr;
    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= n; ++j) {
            lp[pr[j] * i] = pr[j];
        } 
    }
    for (auto& el: pr) {
        cout << el << " ";
    }
    return 0;
}