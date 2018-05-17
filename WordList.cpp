//
// Created by phuoc quang on 4/29/18.
//

#include "WordList.h"
#include "TreeNode.h"
#include "Tree.h"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <cwctype>

static Tree<WordList> tree;
//#include <vector>

const int MAX_STRING_LENGTH = 1024; //i doubt there are words in the english alphabet longer thatn 1024 characters.
const char CHAR_UCASE_A = 65;
const char CHAR_UCASE_Z = 90;

const char CHAR_LCASE_A = 97;
const char CHAR_LCASE_Z = 122;

WordList::WordList() {
    //WordList::tree = tree;
    WordList::lineList = nullptr;
}


WordList::~WordList() {

}

//bool caseInsCharCompareN(char a, char b) {
//    return(toupper(a) == toupper(b));
//}
//
//bool caseInsCompare(const std::string& s1, const std::string& s2) {
//return((s1.size() == s2.size()) &&
//    std::equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
//}

bool WordList::operator<(WordList const &wordList) {
    int r = std::strcmp(word->c_str(), wordList.word->c_str());
    return r < 0;
}

bool WordList::operator>(WordList const &wordList) {
    int r = std::strcmp(word->c_str(), wordList.word->c_str());
    return r > 0;
}

bool WordList::operator==(WordList const &wordList) {
    int r = std::strcmp(word->c_str(), wordList.word->c_str());
    return r == 0;
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
                    wl->setWord(s);
                    WordList *w = tree.insert(wl);
                    w->addLine(line);
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
    //tree.print();
    WL.printWords();
    std::cout << '\n';
    return in;
}

void printLine(SinglyLinkedList *list) {
    if (list == nullptr) {
    } else {
        std::cout << list->getLine() << ", ";
        printLine(list->getNext());
    }

}

void printWord(TreeNode<WordList> *node) {
    //std::cout << "cnode: " << *node->data->word << '\n';
    if (node->left != nullptr) printWord(node->left);
    std::cout << *node->data->getWord() << ':';
    printLine(node->data->lineList);
    std::cout << '\n';
    if (node->right != nullptr) printWord(node->right);
}

void WordList::printWords() {
    printWord(tree.root);
}

void WordList::addLine(int line) {
    if (WordList::lineList == nullptr) {
        WordList::lineList = new SinglyLinkedList(line);
    } else {
        bool isLineInList = false;
        SinglyLinkedList * tail = nullptr;
        for (SinglyLinkedList *current = WordList::lineList; current != nullptr; current = current->getNext()) {
            if (current->getLine() == line) {
                isLineInList = true;
                break; //exit the loop
            }
            tail = current;
        }
        if (!isLineInList) {
            tail->addLine(tail, line);
        }
    }
}

std::string *WordList::getWord() const {
    return word;
}

void WordList::setWord(std::string *word) {
    std::transform(word->begin(), word->end(), word->begin(), ::tolower);
    WordList::word = word;
}
