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

void insertionSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = a[i];

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

long long insertionSortWithCounting(int* a, int n) {
    long long cnt = 0;

    for (int i = 1; ++cnt && i < n; i++) {
        int j = i - 1;
        int key = a[i];

        while (++cnt && j >= 0 && ++cnt && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    return cnt;
}

void bubbleSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                _swap(a[j], a[j + 1]);
            }
        }
    }
}

long long bubbleSortWithCounting(int* a, int n) {
    long long cnt = 0;

    for (int i = 0; ++cnt && i < n - 1; i++) {
        for (int j = 0; ++cnt && j < n - i - 1; j++) {
            if (++cnt && a[j] > a[j + 1]) {
                _swap(a[j], a[j + 1]);
            }
        }
    }

    return cnt;
}

void shakerSort(int* a, int n) {
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) { 
                _swap(a[i], a[i + 1]);
                k = i;
            }
        }

        right = k;

        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                _swap(a[i], a[i - 1]);
                k = i;
            }
        }

        left = k;
    }
}

long long shakerSortWithCounting(int* a, int n) {
    int left = 0;
    int right = n - 1;
    int k = 0;

    long long cnt = 0;

    while (++cnt && left < right) {
        for (int i = left; ++cnt && i < right; i++) {
            if (++cnt && a[i] > a[i + 1]) { 
                _swap(a[i], a[i + 1]);
                k = i;
            }
        }

        right = k;

        for (int i = right; ++cnt && i > left; i--) {
            if (++cnt && a[i] < a[i - 1]) {
                _swap(a[i], a[i - 1]);
                k = i;
            }
        }

        left = k;
    }

    return cnt;
}