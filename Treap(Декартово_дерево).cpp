#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

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

private:
    int x, y;
    Treap* left, * right;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    Treap* trp = nullptr;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        if (i == 1) {
            trp = new Treap(x, y);
        }
        else {
            trp = Treap::add(trp, x, y);
        }
    }
    delete trp;
    return 0;
}