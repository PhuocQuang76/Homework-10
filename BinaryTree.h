//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#ifndef PROJECT10_BINARYTREE_H
#define PROJECT10_BINARYTREE_H

#include "Object.h"

class BinaryTree {
protected:
    struct node {
        Object *object;
        node *left;
        node *right;
    };

    node *root;

    node *traverseNode(node *leaf, Object *newLeaf);

public:

    node *addLeaf(Object *leaf);
};


#endif //PROJECT10_BINARYTREE_H
