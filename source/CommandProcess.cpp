#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <ctime>
#include "BasicSort.h"
#include "AdvancedSort.h"
#include "NoComparisonSort.h"
#include "FlashSort.h"
#include "DataGenerator.h"
#include "CommandProcess.h"

const char* algo[] = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort",
                    "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort"};
int nAlgo = sizeof(algo) / sizeof(algo[0]);

const char* inputOrder[] = {"-rand", "-sorted", "-rev", "-nsorted"};
int nInputOrder = sizeof(inputOrder) / sizeof(inputOrder[0]);

const char* outputParameter[] = {"-time", "-comp", "-both"};
int nOutputParameter = sizeof(outputParameter) / sizeof(outputParameter[0]);

double timeCounting(int* a, int n, int iAlgo) {
    clock_t start = clock();

    if (iAlgo == 0) {
        selectionSort(a, n);
    } else if (iAlgo == 1) {
        insertionSort(a, n);
    } else if (iAlgo == 2) {
        bubbleSort(a, n);
    } else if (iAlgo == 3) {
        shakerSort(a, n);
    } else if (iAlgo == 4) {
        shellSort(a, n);
    } else if (iAlgo == 5) {
        heapSort(a, n);
    } else if (iAlgo == 6) {
        mergeSort(a, n);
    } else if (iAlgo == 7) {
        quickSort(a, 0, n - 1);
    } else if (iAlgo == 8) {
        countingSort(a, n);
    } else if (iAlgo == 9) {
        radixSort(a, n);
    } else if (iAlgo == 10) {
        flashSort(a, n);
    }

    clock_t end = clock();

    double ans = (double)(end - start) / CLOCKS_PER_SEC;

    return ans;
}

long long comparisonCounting(int* a, int n, int iAlgo) {
    long long ans = 0;

    if (iAlgo == 0) {
        ans = selectionSortWithCounting(a, n);
    }  else if (iAlgo == 1) {
        ans = insertionSortWithCounting(a, n);
    } else if (iAlgo == 2) {
        ans = bubbleSortWithCounting(a, n);
    } else if (iAlgo == 3) {
        ans = shakerSortWithCounting(a, n);
    } else if (iAlgo == 4) {
        ans = shellSortWithCounting(a, n);
    } else if (iAlgo == 5) {
        ans = heapSortWithCounting(a, n);
    } else if (iAlgo == 6) {
        ans = mergeSortWithCounting(a, n);
    } else if (iAlgo == 7) {
        ans = quickSortWithCounting(a, 0, n - 1);
    } else if (iAlgo == 8) {
        ans = countingSortWithCounting(a, n);
    } else if (iAlgo == 9) {
        ans = radixSortWithCounting(a, n);
    } else if (iAlgo == 10) {
        ans = flashSortWithCounting(a, n);
    }

    return ans;
}

void processOneOrder(int* a, int n, int iAlgo, char* opPara, std::ifstream& fi) {
    std::cout << "Running time (if required): ";
    if (strcmp(opPara, outputParameter[0]) == 0 || strcmp(opPara, outputParameter[2]) == 0) {
        std::cout << timeCounting(a, n, iAlgo) << " seconds" << "\n";
    } else {
        std::cout << "not required.\n";
    }

    std::cout << "Comparisons (if required): ";
    if (strcmp(opPara, outputParameter[1]) == 0 || strcmp(opPara, outputParameter[2]) == 0) {
        for (int i = 0; i < n; i++) {
        fi >> a[i];
        }
        std::cout << comparisonCounting(a, n, iAlgo) << "\n";
    } else {
        std::cout << "not required.\n";
    }    
}

void commandOneAndThree(char* algor, char* givenInput, char* opPara) {
    //identify algorithms
    int iAlgo = 0;
    for (; iAlgo < nAlgo; iAlgo++) {
        if (strcmp(algor, algo[iAlgo]) == 0) {
            break;
        }
    }

    //command 3
    if (givenInput[strlen(givenInput - 1)] >= '0' && givenInput[strlen(givenInput - 1)] <= '9') {
        int nSize = atoi(givenInput);
        int* a = new int[nSize];

        std::ofstream* dataFile = new std::ofstream[4];

        std::cout << "ALGORITHM MODE\n";
        std::cout << "Algorithm: " << algor << "\n";
        std::cout << "Input size: " << nSize << "\n";
        std::cout << "\n";

        for (int i = 0; i < 4; i++) {
            dataFile[i].open("input_" + std::to_string(i + 1) + ".txt");
        }

        for (int i = 0; i < 4; i++) {
            std::cout << "Input order: ";
            if (i == 0) {
                std::cout << "Randomized\n";
            } else if (i == 1) {
                std::cout << "Sorted\n";
            } else if (i == 2) {
                std::cout << "Reversed\n";
            } else if (i == 3) {
                std::cout << "Nearly sorted\n";
            }
            std::cout << "------------------------------\n";


            GenerateData(a, nSize, i);

            dataFile[i] << nSize << "\n";
            for (int j = 0; j < nSize; j++) {
                dataFile[i] << a[j] << " ";
            }

            std::ifstream fi("input_" + std::to_string(i + 1) + ".txt");

            processOneOrder(a, nSize, iAlgo, opPara, fi);

            fi.close();

        }

        for (int i = 0; i < 4; i++) {
            dataFile[i].close();
        }

        delete[] dataFile;
        delete[] a;

    } else { //command 1
        std::ifstream fi(givenInput);

        int nSize;
        fi >> nSize;

        int* a = new int[nSize];

        std::cout << "ALGORITHM MODE\n";
        std::cout << "Algorithm: " << algor << "\n";
        std::cout << "Input file: " << givenInput << "\n";
        std::cout << "Input size: " << nSize << "\n";
        std::cout << "------------------------------\n";

        for (int i = 0; i < nSize; i++) {
            fi >> a[i];
        }

        fi.clear();
        fi.seekg(0, std::ios::beg);

        processOneOrder(a, nSize, iAlgo, opPara, fi);

        std::ofstream fo("output.txt");
        fo << nSize << "\n";
        for (int i = 0; i < nSize; i++) {
            fo << a[i] << " ";
        }

        fi.close();
        fo.close();
        delete[] a;
    }
}

void commandTwo(char* algor, char* inputSize, char* ipOrder, char* opPara) {
    //identify algorithms
    int iAlgo = 0;
    for (; iAlgo < nAlgo; iAlgo++) {
        if (strcmp(algor, algo[iAlgo]) == 0) {
            break;
        }
    }

    //identify order
    int iOrder = 0;
    for (; iOrder < nInputOrder; iOrder++) {
        if (strcmp(ipOrder, inputOrder[iOrder]) == 0) {
            break;
        }
    }

    //generate data
    int nSize = atoi(inputSize);
    int* a = new int[nSize];

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algor << "\n";
    std::cout << "Input size: " << nSize << "\n";
    std::cout << "Input order: " << ipOrder << "\n";
    std::cout << "------------------------------\n";

    GenerateData(a, nSize, iOrder);
    std::ofstream finp("input.txt");

    finp << nSize << "\n";
    for (int i = 0; i < nSize; i++) {
        finp << a[i] << " ";
    }
    finp.close();

    std::ifstream fi("input.txt");

    for (int i = 0; i < nSize; i++) {
        fi >> a[i];
    }

    fi.clear();
    fi.seekg(0, std::ios::beg);

    processOneOrder(a, nSize, iAlgo, opPara, fi);

    fi.close();

    std::ofstream fo("output.txt");

    fo << nSize << "\n";
    for (int i = 0; i < nSize; i++) {
        fo << a[i] << " ";
    }

    fo.close();

    delete[] a;  
}

void compModeStatistics(int* a, int n, int iAlgo1, int iAlgo2, std::ifstream& fi) {
    std::cout << "Running time: " << timeCounting(a, n, iAlgo1) << " seconds | ";
    for (int i = 0; i < n; i++) {
        fi >> a[i];
    }
    fi.clear();
    fi.seekg(0, std::ios::beg);

    std::cout << timeCounting(a, n, iAlgo2) << " seconds\n";

    for (int i = 0; i < n; i++) {
        fi >> a[i];
    }
    fi.clear();
    fi.seekg(0, std::ios::beg);

    std::cout << "Comparisons: " << comparisonCounting(a, n, iAlgo1) << " | ";
    for (int i = 0; i < n; i++) {
        fi >> a[i];
    }
    fi.clear();
    fi.seekg(0, std::ios::beg);

    std::cout << comparisonCounting(a, n, iAlgo2) << "\n";

}

void commandFour(char* givenAlgo1, char* givenAlgo2, char* inputFile) {
    std::cout << "COMPARISON MODE\n";
    std::cout << "Algorithm: " << givenAlgo1 << " | " << givenAlgo2 << "\n";
    std::cout << "Input file: " << inputFile << "\n";

    std::ifstream fi(inputFile);

    int iAlgo1 = 0, iAlgo2 = 0;
    for (; iAlgo1 < nAlgo; iAlgo1++) {
        if (strcmp(givenAlgo1, algo[iAlgo1]) == 0) {
            break;
        }
    }
    for (; iAlgo2 < nAlgo; iAlgo2++) {
        if (strcmp(givenAlgo2, algo[iAlgo2]) == 0) {
            break;
        }
    }
    
    int nSize;
    fi >> nSize;
    std::cout << "Input size: " << nSize << "\n";
    std::cout << "------------------------------\n";

    int* a = new int[nSize];

    for (int i = 0; i < nSize; i++) {
        fi >> a[i];
    }

    fi.clear();
    fi.seekg(0, std::ios::beg);

    compModeStatistics(a, nSize, iAlgo1, iAlgo2, fi);

    fi.close();
    delete[] a;
}

void commandFive(char* givenAlgo1, char* givenAlgo2, char* inputSize, char* ipOrder) {
    std::cout << "COMPARISON MODE\n";
    std::cout << "Algorithm: " << givenAlgo1 << " | " << givenAlgo2 << "\n";
    std::cout << "Input size: " << inputSize << "\n";
    std::cout << "Input order: " << inputOrder << "\n";

    int iAlgo1 = 0, iAlgo2 = 0;
    for (; iAlgo1 < nAlgo; iAlgo1++) {
        if (strcmp(givenAlgo1, algo[iAlgo1]) == 0) {
            break;
        }
    }
    for (; iAlgo2 < nAlgo; iAlgo2++) {
        if (strcmp(givenAlgo2, algo[iAlgo2]) == 0) {
            break;
        }
    }

    int iOrder = 0;
    for (; iOrder < nInputOrder; iOrder++) {
        if (strcmp(ipOrder, inputOrder[iOrder]) == 0) {
            break;
        }
    }

    int nSize = atoi(inputSize);
    int* a = new int[nSize];

    std::cout << "Input size: " << nSize << "\n";
    std::cout << "------------------------------\n";

    GenerateData(a, nSize, iOrder);
    std::ofstream finp("input.txt");

    finp << nSize << "\n";
    for (int i = 0; i < nSize; i++) {
        finp << a[i] << " ";
    }
    finp.close();

    std::ifstream fi("input.txt");

    for (int i = 0; i < nSize; i++) {
        fi >> a[i];
    }

    fi.clear();
    fi.seekg(0, std::ios::beg);

    compModeStatistics(a, nSize, iAlgo1, iAlgo2, fi);

    fi.close();
    delete[] a;
}