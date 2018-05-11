//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#include "SinglyLinkedList.h"

int SinglyLinkedList::getLine() const {
    return line;
}

SinglyLinkedList *SinglyLinkedList::getNext() const {
    return next;
}

SinglyLinkedList::SinglyLinkedList(int line) {
    SinglyLinkedList::line = line;
}

SinglyLinkedList *SinglyLinkedList::addLine(SinglyLinkedList *node, int line) {
    SinglyLinkedList *newNode = new SinglyLinkedList(line);
    if (node->next == nullptr) {
        //this is an append assuming the node passed was the tail.
        node->next = newNode;
    } else {
        //This is more of like an insert.
        newNode->next = node->next;
        node->next = newNode;
    }
    return newNode;
}



