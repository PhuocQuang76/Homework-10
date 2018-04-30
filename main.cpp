#include <iostream>
#include "ReadFile.h"
//#include "ReadFile.cpp"

int main() {
    ReadFile *readFile = new ReadFile();
    readFile->readFile("text-file.txt");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}