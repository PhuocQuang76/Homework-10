//
// Created by phuoc quang on 4/29/18.
//

#include "WordList.h"
//#include <vector>

const int MAX_STRING_LENGTH = 1024; //i doubt there are words in the english alphabet longer thatn 1024 characters.
const char CHAR_UCASE_A = 65;
const char CHAR_UCASE_Z = 90;

const char CHAR_LCASE_A = 97;
const char CHAR_LCASE_Z = 122;

static BinaryTree *tree;

WordList::WordList() {
    tree = new BinaryTree();
}

WordList::~WordList() {
    delete[] tree;
}

std::istream &operator>>(std::istream &in, WordList &WL) {
    //std::cout << CHAR_UCASE_A << ':' << CHAR_UCASE_Z << '\n';
    char *word = new char[MAX_STRING_LENGTH];
    in.seekg (0, in.end);
    int length = in.tellg();
    in.seekg (0, in.beg);
    char * buffer = new char [length];
    //std::vector<std::string*> *words = new std::vector<std::string*>();
    int line = 1;
    int currentLetterPosition = 0;
    in.read(buffer, length);
    if (in) {
        for (int x = 0; x < length; x++) {
            char letter = buffer[x];
            if ((letter <= CHAR_UCASE_Z && letter >= CHAR_UCASE_A) || (letter <= CHAR_LCASE_Z && letter >= CHAR_LCASE_A)) {
                word[currentLetterPosition++] = letter;
            } else {
                if (currentLetterPosition > 0) {
                    word[currentLetterPosition] = '\0';
                    currentLetterPosition = 0;
                    std::string *s = new std::string(word);
                    word = new char[MAX_STRING_LENGTH];
                    WordList *wl = new WordList();
                    wl->word = s;
                    tree->addLeaf(wl);
                    delete[] word;
                }
                if (letter == '\n') line++;
            }
        }
    }
//    std::cout<<words->size()<<'\n';
//    for(std::string *s : *words) {
//        std::cout << *s << '\n';
//    }
    std::cout << '\n';
    return in;
}

bool WordList::operator<(Object const &object) {
    return Object::operator<(object);
}

bool WordList::operator>(Object const &object) {
    return Object::operator>(object);
}

bool WordList::operator==(Object const &object) {
    return Object::operator==(object);
}


