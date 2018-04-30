//
// Created by phuoc quang on 4/29/18.
//

#include "WordList.h"
WordList::WordList() {
    head = nullptr;
    tail = nullptr;
}

WordList::~WordList() {

}

void WordList::createNode(int value) {
    node *temp = new node;
    temp->lineNumber = value;
    temp->next = nullptr;
    if(head == nullptr){
        head = temp;
        tail = temp;
        temp = nullptr;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

const std::string &WordList::getWord() const {
    return word;
}

void WordList::setWord(const std::string &word) {
    WordList::word = word;
}
