//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int majority_element(const int* parr, int len);

/*int main() {
    int n;
    scanf("%d", &n);
    int arr[5] = {1, 2, 4, 7, 1};
    int ans = majority_element(arr, 5);
    printf("%d", ans);
    return 0;
}*/

int majority_element(const int* parr, int len) {
    if (len > 1) {
        int x1 = majority_element(parr, len / 2);
        int x2 = majority_element(parr + len / 2, len - len / 2);
        if (x1 == -1 && x2 == -1) {
            return -1;
        }
        else if (x1 == x2) {
            return x1;
        }
        else {
            int count1 = 0;
            int count2 = 0;
            for (int i = 0; i < len; ++i) {
                if (*(parr + i) == x1) {
                    count1++;
                }
                if (*(parr + i) == x2) {
                    count2++;
                }
            }
            if (count1 <= len / 2 && count2 <= len / 2) {
                return -1;
            }
            else if (count1 <= len / 2) {
                return x2;
            }
            else if (count2 <= len / 2) {
                return x1;
            }
            else {
                if (count1 >= count2) {
                    return x1;
                }
                else {
                    return x2;
                }
            }
        }
    }
    else {
        return *(parr);
    }
}