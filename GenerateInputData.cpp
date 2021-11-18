#include <iostream>
#include <fstream>
#include "DataGenerator.h"

int generate() {
    std::ofstream* fo = new std::ofstream[4];
	fo[0].open("randomized_data_500000.txt");
	fo[1].open("sorted_data_500000.txt");
	fo[2].open("reversed_sorted_data_500000.txt");
	fo[3].open("nearly_sorted_data_500000.txt");

	int n = 500000;

	int* a = new int[n];

	for (int i = 0; i < 4; i++) {
		GenerateData(a, n, i);

		for (int j = 0; j < n; j++) {
			fo[i] << a[j] << " ";
		}
	}

	delete[] a;

	for (int i = 0; i < 4; i++) {
		fo[i].close();
	}

	delete[] fo;

	return 0;
}