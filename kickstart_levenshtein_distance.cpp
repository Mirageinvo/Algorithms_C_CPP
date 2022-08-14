#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, ans, it;
    string f, s;
    scanf("%d", &n);
    for (int _ = 0; _ < n; ++_) {
        cin >> f >> s;
        ans = 0, it = 0;
        if (s.size() < f.size()) {
            cout << "Case #" << _ + 1 << ": IMPOSSIBLE" << endl;
            continue;
        }
        for (size_t i = 0; i < f.size(); ++i) {
            while (true) {
                if (it == s.size()) {
                    cout << "Case #" << _ + 1 << ": IMPOSSIBLE" << endl;
                    goto jmp;
                }
                if (s[it] == f[i]) {
                    ++it;
                    break;
                }
                else {
                    ++it;
                    ++ans;
                }
            }
            if (i == f.size() - 1) {
                ans += s.size() - it;
            }
        }
        cout << "Case #" << _ + 1 << ": " << ans << endl;
        jmp: continue;
    }
    return 0;
}