#include <iostream>
#include "ReadFile.h"

int main() {
    ReadFile *readFile = new ReadFile();
    readFile->readFile("text-file.txt");

    char answer;
    std::cout << "Do you want to search word in the file? (y = yes, n = no) : " ;
    std::cin >> answer;
    if(answer == 'Y' || answer == 'y'){
        readFile->search();
        std::cout << std::endl;
        readFile->print();
    }else{
        return 0;
    }

    return 0;
}