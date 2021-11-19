#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "BasicSort.h"
#include "AdvancedSort.h"
#include "NoComparisonSort.h"
#include "FlashSort.h"


void testAlgorithm() {
    std::ifstream* fi = new std::ifstream[4];
    std::ofstream* fo = new std::ofstream[4];

    int inputSize[] = {10000, 30000, 50000, 100000, 300000, 500000};

    for (int i = 0; i < 6; i++) {
        std::cout << "Part " << i << "\n";
        //iterate through inputSize[]
        int n = inputSize[i];

        std::string* s = new std::string[4];

        s[0] = "randomized_data_" + std::to_string(n);
        s[1] = "sorted_data_" + std::to_string(n);
        s[2] = "reversed_sorted_data_" + std::to_string(n);
        s[3] = "nearly_sorted_data_" + std::to_string(n);

        for (int j = 0; j < 4; j++) {
            fi[j].open(s[j] + ".txt");
            fo[j].open(s[j] + "_result.txt");
        }

        int* a = new int[n];

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < n; k++) {
                fi[j] >> a[k];
            }

            clock_t start = clock();

            flashSort(a, n);

            clock_t end = clock();

            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

            std::cout << "Time used for " << j << ": " << timeUsed << "\n";

            for (int k = 0; k < n; k++) {
                fo[j] << a[k] << " ";
            }

            fi[j].clear();
            fi[j].seekg(0, std::ios::beg);

            for (int k = 0; k < n; k++) {
                fi[j] >> a[k];
            }

            long long cmp = flashSortWithCounting(a, n);
            
            std::cout << "Comparisons used for " << j << ": " << cmp << "\n";
        }

        delete[] a;

        for (int j = 0; j < 4; j++) {
            fi[j].close();
            fo[j].close();
        }

        delete[] s;
        
    }

    delete[] fi;
    delete[] fo;

}