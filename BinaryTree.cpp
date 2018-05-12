//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#include "BinaryTree.h"

BinaryTree::node *BinaryTree::traverseNode(node *leaf, Object *newLeaf) {
    node *returnValue;
    if (leaf == nullptr) {
        node *newNode = new node();
        newNode->object = newLeaf;
        returnValue = newNode;
    } else if (*leaf->object == *newLeaf) {
        returnValue = leaf;
    } else if (*leaf->object > *newLeaf) {
        node *traversedLeaf = traverseNode(leaf->left, newLeaf);
        if (leaf->left == nullptr) {
            leaf->left = traversedLeaf;
        }
        returnValue = traversedLeaf;
    } else if (*leaf->object < *newLeaf) {
        node *traversedLeaf = traverseNode(leaf->right, newLeaf);
        if (leaf->right == nullptr) {
            leaf->right = traversedLeaf;
        }
        returnValue = traversedLeaf;
    }
    return returnValue;
}

BinaryTree::node *BinaryTree::addLeaf(Object *leaf) {
    if (root == nullptr) {
        root = new node();
    }
    return nullptr;
}
