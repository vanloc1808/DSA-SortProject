#include <iostream>
#include "BasicSort.h"

template<class T>
void _swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void selectionSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            _swap(a[i], a[minIndex]);
        }
    }
}

long long selectionSortWithCounting(int* a, int n) {
    long long cnt = 0;

    for (int i = 0; ++cnt && i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; ++cnt && j < n; j++) {
            if (++cnt && a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        if (++cnt && minIndex != i) {
            _swap(a[i], a[minIndex]);
        }
    }

    return cnt;
}