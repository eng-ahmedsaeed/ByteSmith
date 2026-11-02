#include <fstream>
#include <iostream>
#include "Scanner.h"

int main() {
    std::ifstream infile("input.txt");
    std ::ofstream outfile("output.txt");

    if (!infile.is_open()) {
        std::cout << "Error opening infile!" << std::endl;
        return 1;
    }
    if (!outfile.is_open()) {
        std::cout << "Error opening outfile!" << std::endl;
        return 1;
    }

    Scanner scn(infile, outfile);

    return scn.encounteredError() ? 1 : 0;
}
