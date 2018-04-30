//
// Created by phuoc quang on 4/29/18.
//

#ifndef WORDLISTPROJECT10_WORDLIST_H
#define WORDLISTPROJECT10_WORDLIST_H

#include "iostream"
#include <string>

class WordList {
private:
    std::string word;
    struct node{
        int lineNumber;
        node *next;
    };
    node *head;
    node *tail;
public:
    WordList();
    ~WordList();
    const std::string &getWord() const;
    void setWord(const std::string &word);
    void createNode(int line);
};


#endif //WORDLISTPROJECT10_WORDLIST_H
