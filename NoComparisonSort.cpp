#include <iostream>
#include "BasicSort.h"
#include "NoComparisonSort.h"

void countingSort(int* a, int n) {
    int* c = new int[n];
    for (int i = 0; i < n; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }

    for (int i = 1; i < n; i++) {
        c[i] += c[i - 1];
    }

    int* b = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }

    delete[] c;
    delete[] b;
}

long long countingSortWithCounting(int* a, int n) {
    long long cnt = 0;

    int* c = new int[n];
    for (int i = 0; ++cnt && i < n; i++) {
        c[i] = 0;
    }

    for (int i = 0; ++cnt && i < n; i++) {
        c[a[i]]++;
    }

    for (int i = 1; ++cnt && i < n; i++) {
        c[i] += c[i - 1];
    }

    int* b = new int[n];
    for (int i = n - 1; ++cnt && i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; ++cnt && i < n; i++) {
        a[i] = b[i];
    }

    delete[] c;
    delete[] b;

    return cnt;
}

 /* https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp */
void radixSort(int* a, int n)
{
	int* b = new int[n];

	int m = a[0], exp = 1;

	for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }		
    }
		

	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) {
            bucket[a[i] / exp % 10]++;
        }
			
		for (int i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
			
		for (int i = n - 1; i >= 0; i--) {
            b[--bucket[a[i] / exp % 10]] = a[i];
        }
			
		for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }

		exp *= 10;
	}
	delete[] b;
}

long long radixSortWithCounting(int* a, int n) {
    long long cmp = 0;

    int* b = new int[n];

	int m = a[0], exp = 1;

	for (int i = 0; ++cmp && i < n; i++) {
        if (++cmp && a[i] > m) {
            m = a[i];
        }		
    }
		

	while (++cmp && m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; ++cmp && i < n; i++) {
            bucket[a[i] / exp % 10]++;
        }
			
		for (int i = 1; ++cmp && i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
			
		for (int i = n - 1; ++cmp && i >= 0; i--) {
            b[--bucket[a[i] / exp % 10]] = a[i];
        }
			
		for (int i = 0; ++cmp && i < n; i++) {
            a[i] = b[i];
        }

		exp *= 10;
	}
	delete[] b;

    return cmp;
}