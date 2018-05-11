//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#include "BinaryTree.h"

template<class T>
BinaryTree<T> *traverseNode(BinaryTree<T> *leaf, T newLeaf) {
    BinaryTree<T> *returnValue;
    if (leaf == nullptr) {
        BinaryTree<T> *newNode = new BinaryTree<T>();
        newNode->setObject(newLeaf);
        returnValue = newNode;
    } else if (leaf->getObject() == newLeaf) {
        returnValue = leaf;
    } else if (leaf->getObject() > newLeaf) {
        BinaryTree<T> *traversedLeaf = traverseNode(leaf->getLeft(), newLeaf);
        if (leaf->getLeft() == nullptr) {
            leaf->setLeft(traversedLeaf);
        }
        returnValue = traversedLeaf;
    } else if (leaf->getObject() < newLeaf) {
        BinaryTree<T> *traversedLeaf = traverseNode(leaf->getRight(), newLeaf);
        if (leaf->getRight() == nullptr) {
            leaf->setRight(traversedLeaf);
        }
        returnValue = traversedLeaf;
    }
    return returnValue;
}

template<class T>
BinaryTree<T> *BinaryTree<T>::addLeaf(T leaf) {
    BinaryTree<T> *newNode = traverseNode(this->root, leaf);
    if (this->root == nullptr) {
        root = newNode;
    }
    return newNode;
}

template<class T>
BinaryTree<T> *BinaryTree<T>::getRoot() {
    return root;
}

template<class T>
void BinaryTree<T>::setRoot(BinaryTree<T> *root) {
    BinaryTree<T>::root = root;
}

template<class T>
BinaryTree<T> *BinaryTree<T>::getLeft() const {
    return left;
}

template<class T>
void BinaryTree<T>::setLeft(BinaryTree<T> *left) {
    BinaryTree<T>::left = left;
}

template<class T>
BinaryTree<T> *BinaryTree<T>::getRight() const {
    return right;
}

template<class T>
void BinaryTree<T>::setRight(BinaryTree<T> *right) {
    BinaryTree<T>::right = right;
}
