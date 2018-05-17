//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#ifndef PROJECT10_SINGLYLINKEDLIST_H
#define PROJECT10_SINGLYLINKEDLIST_H

#include <string>
class SinglyLinkedList {
private:
    int line;
    SinglyLinkedList *next;
public:
    SinglyLinkedList(int line);

    int getLine() const;

    SinglyLinkedList *getNext() const;

    SinglyLinkedList *addLine(SinglyLinkedList *node, int line);

};


#endif //PROJECT10_SINGLYLINKEDLIST_H
