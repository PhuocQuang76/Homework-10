//
// Created by phuoc quang on 4/29/18.
//

#include "WordList.h"
WordList::WordList() {
    bst = new BST;
    head = nullptr;
    tail = nullptr;
}

WordList::~WordList() {
    for(node *currentNode = head; currentNode != nullptr;){
        node *deleteNode = currentNode;
        currentNode = currentNode->next;
        delete deleteNode;
    }
}

void WordList::createLineNode(int line) {
    node *mynode = new node;
    mynode->lineNumber = line;
    mynode->next = nullptr;
    if(head == nullptr){
        head = mynode;
        tail = mynode;
    }else{
        tail->next = mynode;
        tail = mynode;
    }
}

std::string WordList::getWord(){
    return word;
}

void WordList::setWord(std::string word) {
    WordList::word = word;
}

std::string WordList::getLines() {
    //char str[1024];
    //std::strcpy(str, "");
    std::string text = "";
    node *cur = head;
    while(cur != nullptr){
        //std::strcat(str, (head->lineNumber)); std::strcat(str, " ");
        text = text + std::to_string(cur->lineNumber) + ",";
        cur = cur->next;
    }
    std::string removeLastCharString = text.substr(0, text.length()-1);
    return removeLastCharString;
}


