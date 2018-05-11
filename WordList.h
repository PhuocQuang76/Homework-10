//
// Created by phuoc quang on 4/29/18.
//

#ifndef WORDLISTPROJECT10_WORDLIST_H
#define WORDLISTPROJECT10_WORDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "iostream"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "SinglyLinkedList.h"
#include "BinaryTree.h"

class WordList {
private:
    std::string word;
    SinglyLinkedList *lineList;
    static BinaryTree<WordList> tree;
public:
    WordList();
    ~WordList();
    
//    std::string getWord();
//    void setWord(std::string word);
//    void createLineNode(int line);
//    std::string getLines();
    bool operator < (WordList const &wordList);
    bool operator > (WordList const &wordList);
    bool operator == (WordList const &wordList);
    friend std::istream & operator >>(std::istream & in, WordList& WL);
};


#endif //WORDLISTPROJECT10_WORDLIST_H
