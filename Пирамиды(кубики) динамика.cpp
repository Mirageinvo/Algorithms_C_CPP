#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

/*
На большом столе находится 3⩽N⩽225 одинаковых кубиков. Их можно укладывать друг на друга, образуя пирамидки.
Важно, что если в каком-то слое пирамидки положить столько же кубиков, как в предыдущем, или больше, пирамида развалится.
Вывести количество различных пирамид, которые можно собрать из всех кубиков.
*/

int main() {
    cin.tie(0);
    cout.tie(0);
    size_t n, ans = 0;
    cin >> n;
    vector<vector<size_t>> dp(n + 1, vector<size_t>(n + 1, 0));
    dp[0][0] = 1;
    for (size_t i = 1; i <= n; ++i) {      //dp[i][j] - число пирамид из i кубиков, с j кубиков в нижнем слое
        for (size_t j = 1; j <= i; ++j) {
            for (size_t k = 0; k < j; ++k) {
                dp[i][j] += dp[i - j][k]; //перебираем второй снизу слой
            }
        }
    }
    for (size_t i = 0; i <= n; ++i) {
        ans += dp[n][i];
    }
    cout << ans;
    return 0;
}