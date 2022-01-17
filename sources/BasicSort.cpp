#include <iostream>
#include "BasicSort.h"

//https://nguyenvanhieu.vn/thuat-toan-sap-xep-selection-sort/
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

//https://www.geeksforgeeks.org/insertion-sort/
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

//https://nguyenvanhieu.vn/thuat-toan-sap-xep-bubble-sort/
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

//https://vi.wikipedia.org/wiki/Thu%E1%BA%ADt_to%C3%A1n_s%E1%BA%AFp_x%E1%BA%BFp_cocktail
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

//https://www.programiz.com/dsa/shell-sort
void shellSort(int* a, int n) {
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int j = i - gap;
            int key = a[i];

            while (j >= 0 && a[j] > key) {
                a[j + gap] = a[j];
                j -= gap;
            }

            a[j + gap] = key;
        }

        gap /= 2;
    }
}

long long shellSortWithCounting(int* a, int n) {
    long long cnt = 0;
    int gap = n / 2;

    while (++ cnt && gap > 0) {
        for (int i = gap; ++cnt && i < n; i++) {
            int j = i - gap;
            int key = a[i];

            while (++cnt && j >= 0 && ++cnt && a[j] > key) {
                a[j + gap] = a[j];
                j -= gap;
            }

            a[j + gap] = key;
        }

        gap /= 2;
    }

    return cnt;
}