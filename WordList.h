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
#include "Object.h"
#include "SinglyLinkedList.h"
#include "BinaryTree.h"

class WordList: public Object {
private:
    std::string *word;
    SinglyLinkedList *lineList;
public:
    WordList();

    bool operator<(Object const &object) override;

    bool operator>(Object const &object) override;

    bool operator==(Object const &object) override;

    ~WordList();
    
//    std::string getWord();
//    void setWord(std::string word);
//    void createLineNode(int line);
//    std::string getLines();
//    bool operator < (Object const &wordList);
//    bool operator > (Object const &wordList);
//    bool operator == (Object const &wordList);
    friend std::istream & operator >>(std::istream & in, WordList& WL);
};


#endif //WORDLISTPROJECT10_WORDLIST_H
