#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

void radix_sort(unsigned int* arr, unsigned int* nw, unsigned int N);

int main() {
	unsigned int N = 0, K = 0, M = 0, L = 0;
	unsigned long long d = 0;
	scanf("%u%u%u%u", &N, &K, &M, &L);
	unsigned int* arr = (unsigned int*)calloc(N, sizeof(unsigned int));
	unsigned int* nw = (unsigned int*)calloc(N, sizeof(unsigned int));
	arr[0] = K;
	for (size_t i = 0; i < N - 1; i++) {
		arr[i + 1] = (unsigned int)((arr[i] * (unsigned long long)M) & 0xFFFFFFFFU) % L;
	}

	radix_sort(arr, nw, N);

	for (size_t i = 0; i < N; i += 2) {
		d += arr[i];
	}
	printf("%llu\n", d % L);
	free(arr);
	free(nw);
	return 0;
}

void radix_sort(unsigned int* arr, unsigned int* nw, unsigned int N) {
	unsigned int c1[256] = { 0 };
	unsigned int c2[256] = { 0 };
	unsigned int c3[256] = { 0 };
	unsigned int c4[256] = { 0 };
	unsigned int d = 0, count = 0, tmp = 0;

	for (size_t j = 0; j < N; j++) {
		d = arr[j] & 255;
		c1[d]++;
		d = (arr[j] >> 8) & 255;
		c2[d]++;
		d = (arr[j] >> 16) & 255;
		c3[d]++;
		d = (arr[j] >> 24) & 255;
		c4[d]++;
	}

	for (size_t j = 0; j < 256; j++) {
		tmp = c1[j];
		c1[j] = count;
		count += tmp;
	}
	for (size_t j = 0; j < N; j++) {
		d = arr[j] & 255;
		nw[c1[d]] = arr[j];
		c1[d]++;
	}

	count = 0;
	for (size_t j = 0; j < 256; j++) {
		tmp = c2[j];
		c2[j] = count;
		count += tmp;
	}
	for (size_t j = 0; j < N; j++) {
		d = (nw[j] >> 8) & 255;
		arr[c2[d]] = nw[j];
		c2[d]++;
	}

	count = 0;
	for (size_t j = 0; j < 256; j++) {
		tmp = c3[j];
		c3[j] = count;
		count += tmp;
	}
	for (size_t j = 0; j < N; j++) {
		d = (arr[j] >> 16) & 255;
		nw[c3[d]] = arr[j];
		c3[d]++;
	}

	count = 0;
	for (size_t j = 0; j < 256; j++) {
		tmp = c4[j];
		c4[j] = count;
		count += tmp;
	}
	for (size_t j = 0; j < N; j++) {
		d = (nw[j] >> 24) & 255;
		arr[c4[d]] = nw[j];
		c4[d]++;
	}
}