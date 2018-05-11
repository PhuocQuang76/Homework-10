//
// Created by phuoc quang on 4/29/18.
//

#include "WordList.h"

const int BUFFER_SIZE = 1024;

WordList::WordList() {
}

WordList::~WordList() {

}

bool WordList::operator<(WordList const &wordList) {
    return false;
}

bool WordList::operator>(WordList const &wordList) {
    return false;
}

bool WordList::operator==(WordList const &wordList) {
    return false;
}

std::istream &operator>>(std::istream &in, WordList &WL) {
    char * buffer = new char [BUFFER_SIZE];
    in.read(buffer, BUFFER_SIZE);
    std::string *s = new std::string(buffer);
    std::cout << *s;
    return in;
}


