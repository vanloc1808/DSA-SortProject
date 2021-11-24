#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <string.h>
#include "BasicSort.h"
#include "AdvancedSort.h"
#include "NoComparisonSort.h"
#include "FlashSort.h"
#include "DataGenerator.h"
#include "AlgorithmTesting.h"
#include "CommandProcess.h"

int main(int argc, char** argv) {
    if (argc == 5) {
        if (strcmp(argv[1], "-a") == 0) {
            commandOneAndThree(argv[2], argv[3], argv[4]);
        } else if (strcmp(argv[1], "-c") == 0) {
            commandFour(argv[2], argv[3], argv[4]);
        }
    } else if (argc == 6) {
        if (strcmp(argv[1], "-a") == 0) {
            commandTwo(argv[2], argv[3], argv[4], argv[5]);
        } else if (strcmp(argv[1], "-c") == 0) {
            commandFive(argv[2], argv[3], argv[4], argv[5]);
        }
    }

    return 0;
}