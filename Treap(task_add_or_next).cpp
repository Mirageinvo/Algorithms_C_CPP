#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <ctime>

using namespace std;

//Task from: https://informatics.msk.ru/mod/statements/view.php?id=1974&chapterid=2782#1
//Thanks to: https://habr.com/en/post/101818/ and https://algorithmica.org/ru/treap

const int INF = 1000000000;

class Treap {
public:
    Treap(int x_, int y_, Treap* left_ = nullptr, Treap* right_ = nullptr) : x(x_), y(y_), left(left_), right(right_) {}
    ~Treap() { delete left;  delete right; }

    //Treap* l always has keys (l->x) less or equal than keys of Treap* r (r->x) 
    static Treap* merge(Treap* l, Treap* r) {
        if (l == nullptr) {
            return r;
        }
        if (r == nullptr) {
            return l;
        }
        if (l->y < r->y) { //min heap
            l->right = merge(l->right, r);
            return l;
        }
        else {
            r->left = merge(l, r->left);
            return r;
        }
    }
    static pair<Treap*, Treap*> split(Treap* base, int nm) {
        if (base == nullptr) {
            return make_pair(nullptr, nullptr);
        }
        if (base->x > nm) {
            auto newV = split(base->left, nm);
            base->left = newV.second;
            return make_pair(newV.first, base);
        }
        else {
            auto newV = split(base->right, nm);
            base->right = newV.first;
            return make_pair(base, newV.second);
        }
    }
    static Treap* add(Treap* base, int inx, int iny) {
        auto pr = split(base, inx);
        Treap* to_add = new Treap(inx, iny);
        return merge(merge(pr.first, to_add), pr.second);
    }
    static Treap* del(Treap* base, int inx, int iny) { //iny is not needed since we assume that all elements in the Treap have different keys
        auto tmp1 = split(base, inx - 1);
        auto tmp2 = split(tmp1.second, inx);
        delete tmp2.first;
        return merge(tmp1.first, tmp2.second);
    }
    int next(int num, int best = INF + 1) {
        if (x == num) {
            return x;
        }
        if (x > num) {
            if (abs(best - num) > abs(x - num)) {
                best = x;
            }
            if (left != nullptr) {
                return left->next(num, best);
            }
            else {
                return best;
            }
        }
        else {
            if (right != nullptr) {
                return right->next(num, best);
            }
            else {
                return best;
            }
        }
    }

private:
    int x, y;
    Treap* left, * right;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    size_t n;
    char c = '.', prev_c;
    int num = 0, prev_num;
    Treap* trp = nullptr;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        prev_c = c;
        cin >> c >> num;
        if (i == 0) {
            trp = new Treap(num, rand() % INF);
        }
        else {
            if (c == '?') {
                prev_num = trp->next(num);
                if (prev_num == INF + 1) {
                    prev_num = -1;
                }
                cout << prev_num << endl;
            }
            else if (prev_c == '?') { // c = '+'
                int tmp = trp->next((prev_num + num) % INF);
                if (tmp != (prev_num + num) % INF) {
                    trp = Treap::add(trp, (prev_num + num) % INF, rand() % INF);
                }
            }
            else {
                int tmp = trp->next(num);
                if (tmp != num) {
                    trp = Treap::add(trp, num, rand() % INF);
                }
            }
        }
    }
    return 0;
}