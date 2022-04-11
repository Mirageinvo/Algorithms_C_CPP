/*#include <iostream>
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
using namespace std;

int n, num;
const int INF = 1e9;
const int SIZE = 200010;
int ch[SIZE * 4];
int t[SIZE * 4];

void push(int v) {
	ch[v * 2 + 1] += ch[v];
	ch[v * 2 + 2] += ch[v];
	ch[v] = 0;
}

void upg(int v) {
	ch[v] = max(ch[v * 2 + 1], ch[v * 2 + 2]);
}

int ask(int v, int l, int r, int askl, int askr) {
	if (l >= askr || r <= askl) {
		return -INF;
	}
	if (l >= askl && r <= askr)
		return ch[v];
	int m = l + (r - l) / 2;
	push(v);
	int ans = max(ask(v * 2 + 1, l, m, askl, askr), ask(v * 2 + 2, m, r, askl, askr));
	upg(v);
	return ans;
	//return max(ask(v * 2 + 1, l, m, askl, askr), ask(v * 2 + 2, m, r, askl, askr));
}

void update(int v, int l, int r, int askl, int askr) {
	if (l >= askr || r <= askl)
		return;
	if (l >= askl && r <= askr) {
		ch[v] += 1;
		return;
	}
	push(v);
	int m = l + (r - l) / 2;
	update(v * 2 + 1, l, m, askl, askr);
	update(v * 2 + 2, m, r, askl, askr);
	upg(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> n >> num >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if (ask(0, 0, n, x, y - 1) < num) {
			cout << 1 << endl;
			update(0, 0, n, x, y - 1);
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}*/
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

struct node {
    int left, right, min, add;
    node* child_left, * child_right;
};

const int INF = 2000000000;

node* build(int left, int right, vector<int>& values) {
    if (left > right)
        return 0;
    node* res = new node;
    res->left = left;
    res->right = right;
    if (right == left) {
        res->child_left = res->child_right = 0;
        res->min = values[left];
        res->add = 0;
    }
    else {
        int mid = (left + right) / 2;
        res->child_left = build(left, mid, values);
        res->child_right = build(mid + 1, right, values);
        res->min = min(res->child_left->min, res->child_right->min);
        res->add = 0;
    }
    return res;
}

int query(node* root, int left, int right)
{
    if (right < root->left || left > root->right)
        return INF;
    if (left <= root->left && right >= root->right)
        return root->add + root->min;
    int ans1 = query(root->child_left, left, right);
    int ans2 = query(root->child_right, left, right);
    return root->add + min(ans1, ans2);
}

void update(node* root, int left, int right, int delta)
{
    if (right < root->left || left > root->right)
        return;
    if (left <= root->left && right >= root->right)
        root->add += delta;
    else
    {
        update(root->child_left, left, right, delta);
        update(root->child_right, left, right, delta);
        root->min = min(root->child_left->min + root->child_left->add,
            root->child_right->min + root->child_right->add);
    }
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n - 1, k);
    node* root = build(0, n - 2, a);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (query(root, x, y - 1) <= 0) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
            update(root, x, y - 1, -1);
        }
    }
    return 0;
}