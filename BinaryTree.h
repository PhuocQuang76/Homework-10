//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#ifndef PROJECT10_BINARYTREE_H
#define PROJECT10_BINARYTREE_H

#include "WordList.h"

template<class T>

class BinaryTree {
protected:
    static BinaryTree<T> *root;
    BinaryTree<T> *left;
    BinaryTree<T> *right;

    BinaryTree<T> *traverseNode(BinaryTree<T> *leaf, T newLeaf);

    T *object;

public:

    BinaryTree<T> *addLeaf(T leaf);
};


#endif //PROJECT10_BINARYTREE_H
