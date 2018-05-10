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
#include "BST.h"
#include <vector>

class WordList {
private:
    std::string word;
    struct node{
        int lineNumber;
        node *next;
    };
    node *head;
    node *tail;
    BST *bst;

public:
    WordList();
    ~WordList();
    
    std::string getWord();
    void setWord(std::string word);
    void createLineNode(int line);
    std::string getLines();
};


#endif //WORDLISTPROJECT10_WORDLIST_H
