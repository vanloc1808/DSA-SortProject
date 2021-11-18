#include <iostream>
#include <fstream>
#include <ctime>
#include "BasicSort.h"
#include "DataGenerator.h"

int main() {
    std::ifstream* fi = new std::ifstream[4];
	fi[0].open("randomized_data_300000.txt");
	fi[1].open("sorted_data_300000.txt");
	fi[2].open("reversed_sorted_data_300000.txt");
	fi[3].open("nearly_sorted_data_300000.txt");

    std::ofstream* fo = new std::ofstream[4];
    fo[0].open("randomized_data_300000_result.txt");
    fo[1].open("sorted_data_300000_result.txt");
    fo[2].open("reversed_sorted_data_300000_result.txt");
    fo[3].open("nearly_sorted_data_300000_result.txt");

    int n = 300000;

	int* a = new int[n];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            fi[i] >> a[j];
        }

        clock_t start = clock();
        selectionSort(a, n);
        clock_t end = clock();
        double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

        std::cout << "Time used for " << i << ": " << timeUsed << "\n";

        for (int j = 0; j < n; j++) {
            fo[i] << a[j] << " ";
        }

        for (int j = 0; j < n; j++) {
            fi[i] >> a[j];
        }

        long long cmp = selectionSortWithCounting(a, n);
        std::cout << "Comparison used for " << i << ": " << cmp << "\n";
    }

    for (int i = 0; i < 4; i++) {
        fi[i].close();
        fo[i].close();
    }

    delete[] fi;
    delete[] fo;

    return 0;
}