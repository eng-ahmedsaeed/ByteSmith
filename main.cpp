#include <fstream>
#include <iostream>
#include "Tokens/Scanner.h"

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    Scanner scn(file);
    return 0;
}
