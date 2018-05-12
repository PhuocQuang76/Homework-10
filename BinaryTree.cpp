//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#include "BinaryTree.h"

template<class T>
BinaryTree<T> *BinaryTree<T>::traverseNode(BinaryTree<T> *leaf, T newLeaf) {
    BinaryTree<T> *returnValue;
    if (leaf == nullptr) {
        BinaryTree<T> *newNode = new BinaryTree<T>();
        newNode->object = &newLeaf;
        returnValue = newNode;
    } else if (*leaf->object == newLeaf) {
        returnValue = leaf;
    } else if (*leaf->object > newLeaf) {
        BinaryTree<T> *traversedLeaf = traverseNode(leaf->left, newLeaf);
        if (leaf->left == nullptr) {
            leaf->left = traversedLeaf;
        }
        returnValue = traversedLeaf;
    } else if (*leaf->object < newLeaf) {
        BinaryTree<T> *traversedLeaf = traverseNode(leaf->right, newLeaf);
        if (leaf->right == nullptr) {
            leaf->right = traversedLeaf;
        }
        returnValue = traversedLeaf;
    }
    return returnValue;
}

template<class T>
BinaryTree<T> *BinaryTree<T>::addLeaf(T leaf) {
    BinaryTree<T> *newNode = traverseNode(root, leaf);
    if (root == nullptr) {
        root = newNode;
    }
    return newNode;
}
