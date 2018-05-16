#include <iostream>
#include "WordList.h"
int main() {
//    ReadFile *readFile = new ReadFile();
//    readFile->readFile("text-file.txt");
//
//    char answer;
//    std::cout << "Do you want to search word in the file? (y = yes, n = no) : " ;
//    std::cin >> answer;
//    if(answer == 'Y' || answer == 'y'){
//        readFile->search();
//        std::cout << std::endl;
//        readFile->print();
//    }else{
//        return 0;
//    }

    //Tree <WordList *> *tree = new Tree<WordList *>();
    std::ifstream is ("text-file.txt", std::ifstream::binary);
    WordList *list = new WordList();
    std::istream& s = is;
    s >> *list;

    return 0;
}