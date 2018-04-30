//
// Created by phuoc quang on 4/29/18.
//

#include "BST.h"
#include "WordList.h"

BST::BST() {
    root = nullptr;
}

BST::~BST() {
//    BST::freeBinaryTree();
}

void BST::insert(std::string word, int line) {
    /* If the tree is empty, return a new Node */
    if(root == nullptr){
        root = new BstNode(word, line);
        return;
    }
    BstNode *cur = root;
    for(;;){
        if(word.compare(cur->wordList->getWord()) == 0){
            cur->wordList->createNode(line);
            return;
        }
        if(word.compare(cur->wordList->getWord()) < 0){
            if(cur->leftNode != nullptr){
                cur = cur->leftNode;
            }else{
                cur->leftNode = new BstNode(word, line);
                return;
            }
        }else if(word.compare(cur->wordList->getWord()) > 0){
            if(cur->rightNode != nullptr){
                cur = cur->rightNode;
            }else{
                cur->rightNode = new BstNode(word, line);
                return;
            }
        }
    }
}