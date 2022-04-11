#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void*, const void*);

int main() {
    unsigned long long int n;
    unsigned char* k = &n;
    int m = -1;
    scanf("%llu", &n);
    for (int i = 0; i < sizeof(n); ++i) {
        if (*(k + i) != '0') {
            for (int j = 0; j < 8; ++j) {
                int num = (int)*(k + i);
                if ((num & (1 << j)) != 0) {
                    m = j + i * 8;
                }
            }
        }
    }
    printf("%d", m);
    return 0;
}
