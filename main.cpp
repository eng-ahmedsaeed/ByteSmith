#include <iostream>
#include <Scanner>
int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    Scanner scn (file);
    return 0;
}
