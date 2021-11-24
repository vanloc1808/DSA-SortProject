#include <iostream>
#include "BasicSort.h"
#include "AdvancedSort.h"

void heapify(int* a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        _swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

//https://www.geeksforgeeks.org/heap-sort/
void heapSort(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        _swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

long long heapifyWithCounting(int* a, int n, int i) {
    long long cnt = 0;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++cnt && left < n && ++cnt && a[left] > a[largest]) {
        largest = left;
    }

    if (++cnt && right < n && ++cnt && a[right] > a[largest]) {
        largest = right;
    }

    if (++cnt && largest != i) {
        _swap(a[i], a[largest]);
        heapify(a, n, largest);
    }

    return cnt;
}

long long heapSortWithCounting(int* a, int n) {
    long long cnt = 0;

    for (int i = n / 2 - 1; ++cnt && i >= 0; i--) {
        cnt += heapifyWithCounting(a, n, i);
    }

    for (int i = n - 1; ++cnt && i >= 0; i--) {
        _swap(a[0], a[i]);
        cnt += heapifyWithCounting(a, i, 0);
    }

    return cnt;
}

//https://www.geeksforgeeks.org/merge-sort/
void mergeSort(int* a, int n) {
    if (n <= 1) {
        return;
    }

    int mid = n / 2;
    int* left = new int[mid];
    int* right = new int[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = a[i];
    }

    for (int i = mid; i < n; i++) {
        right[i - mid] = a[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);

    int i = 0, j = 0, k = 0;

    while (i < mid && j < n - mid) {
        if (left[i] < right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    while (i < mid) {
        a[k++] = left[i++];
    }

    while (j < n - mid) {
        a[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

long long mergeSortWithCounting(int* a, int n) {
    long long cnt = 0;

    if (++cnt && n <= 1) {
        return cnt;
    }

    int mid = n / 2;
    int* left = new int[mid];
    int* right = new int[n - mid];

    for (int i = 0; ++cnt && i < mid; i++) {
        left[i] = a[i];
    }

    for (int i = mid; ++cnt && i < n; i++) {
        right[i - mid] = a[i];
    }

    cnt += mergeSortWithCounting(left, mid);
    cnt += mergeSortWithCounting(right, n - mid);

    int i = 0, j = 0, k = 0;

    while (++cnt && i < mid && j < n - mid) {
        if (left[i] < right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    while (++cnt && i < mid) {
        a[k++] = left[i++];
    }

    while (++cnt && j < n - mid) {
        a[k++] = right[j++];
    }

    delete[] left;
    delete[] right;

    return cnt;
}

//https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp
void quickSort(int* a, int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            _swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(a, left, j);
    }
    if (i < right) {
        quickSort(a, i, right);
    }
}

long long quickSortWithCounting(int* a, int left, int right) {
    long long cnt = 0;

    int i = left, j = right;
    int pivot = a[(left + right) / 2];
    while (++cnt && i <= j) {
        while (++cnt && a[i] < pivot) {
            i++;
        }
        while (++cnt && a[j] > pivot) {
            j--;
        }
        if (++cnt && i <= j) {
            _swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (++cnt && left < j) {
        cnt += quickSortWithCounting(a, left, j);
    }
    
    if (++cnt && i < right) {
        cnt += quickSortWithCounting(a, i, right);
    }

    return cnt;
}