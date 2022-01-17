#include <iostream>
#include "BasicSort.h"
#include "FlashSort.h"

/* https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp */

void flashSort(int* a, int n)
{
	int minVal = a[0];
	int maxIdx = 0;
	int m = int(0.43 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++) {
        l[i] = 0;
    }
		
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal) {
            minVal = a[i];
        }
		if (a[i] > a[maxIdx]) {
            maxIdx = i;
        }
			
	}
    
	if (a[maxIdx] == minVal) {
        		return;
    }

	double c1 = 1.00 * (m - 1) / (a[maxIdx] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}

	for (int i = 1; i < m; i++) {
        l[i] += l[i - 1];
    }
		
	_swap(a[maxIdx], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}

		flash = a[j];

		if (k < 0) {
            break;
        }

		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];

			a[t] = flash;
			flash = hold;

			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);
}

long long flashSortWithCounting(int* a, int n) {
    long long cmp = 0;

    int minVal = a[0];
	int maxIdx = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++cmp && i < m; i++) {
        l[i] = 0;
    }
		
	for (int i = 1; ++cmp && i < n; i++)
	{
		if (++cmp && a[i] < minVal) {
            minVal = a[i];
        }
		if (++cmp && a[i] > a[maxIdx]) {
            maxIdx = i;
        }
			
	}
    
	if (++cmp && a[maxIdx] == minVal) {
        		return cmp;
    }

	double c1 = 1.00 * (m - 1) / (a[maxIdx] - minVal);

	for (int i = 0; ++cmp &&  i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}

	for (int i = 1; ++cmp &&  i < m; i++) {
        l[i] += l[i - 1];
    }
		
	_swap(a[maxIdx], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (++cmp && nmove < n - 1)
	{
		while (++cmp && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}

		flash = a[j];

		if (++cmp && k < 0) {
            break;
        }

		while (++cmp && j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];

			a[t] = flash;
			flash = hold;
            
			++nmove;
		}
	}
	delete[] l;
	cmp += insertionSortWithCounting(a, n);

    return cmp;
}