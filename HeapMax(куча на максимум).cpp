#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <set>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long int INF = 1e9;

template<typename T>
class HeapMax {
public:
    void Add(int el) {
        arr.push_back(el);
        int cur = arr.size() - 1;
        int parent = (cur - 1) / 2;
        while (cur > 0 && arr[cur] > arr[parent]) {
            swap(arr[cur], arr[parent]);
            cur = parent;
            parent = (cur - 1) / 2;
        }
    }

    void Heapify(int i) {
        int left, right, largestChild;
        while (true) {
            left = i * 2 + 1;
            right = i * 2 + 2;
            largestChild = i;

            if (left < arr.size() && arr[left] > arr[largestChild]) {
                largestChild = left;
            }
            if (right < arr.size() && arr[right] > arr[largestChild]) {
                largestChild = right;
            }

            if (largestChild == i) {
                break;
            }

            swap(arr[i], arr[largestChild]);
            i = largestChild;
        }
    }

    T GetAndRemoveMax() {
        T ret = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        Heapify(0);
        return ret;
    }

    HeapMax<T> BuildHeapOnArray(vector<T>&& tmp_arr) {
        move(arr, tmp_arr);
        for (int i = (arr.size() - 1) / 2; i >= 0; --i) {
            Heapify(i);
        }
    }

private:
    vector<T> arr;
};

int main() {
    HeapMax<int> heap;
    int n, type, val;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        if (type == 0) {
            cin >> val;
            heap.Add(val);
        }
        else {
            cout << heap.GetAndRemoveMax() << endl;
        }
    }
    return 0;
}
