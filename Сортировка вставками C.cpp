#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int moveright(int* arr, int key, int last) {
    int i;
    for (i = last; i >= 1 && arr[i-1] > key; --i) {
        arr[i] = arr[i - 1];
    }
    return i;
}

void inssort(int* arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        int key, pos;
        key = arr[i];
        pos = moveright(arr, key, i);
        arr[pos] = key;
    }
}

int main() {
    int arr[] = { 1, 3, 2, 1 };
    inssort(arr, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(arr+i));
    }
    return 0;
}