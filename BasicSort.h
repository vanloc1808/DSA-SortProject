#ifndef _BASIC_SORT_H
#define _BASIC_SORT_H

template<class T>
void _swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void selectionSort(int* a, int n);

long long selectionSortWithCounting(int* a, int n);

void insertionSort(int* a, int n);

long long insertionSortWithCounting(int* a, int n);

void bubbleSort(int* a, int n);

long long bubbleSortWithCounting(int* a, int n);

void shakerSort(int* a, int n);

long long shakerSortWithCounting(int* a, int n);

void shellSort(int* a, int n);

long long shellSortWithCounting(int* a, int n);

#endif