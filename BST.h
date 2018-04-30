//
// Created by phuoc quang on 4/29/18.
//

#ifndef WORDLISTPROJECT10_BST_H
#define WORDLISTPROJECT10_BST_H

#include "WordList.h"

class BST {
private:
    struct BstNode{
        BstNode(const std::string word, int line){
            wordList->setWord(word);
            wordList->createNode(line);
        }
        WordList *wordList;
        BstNode *leftNode, *rightNode;
    };
    BstNode *root;

    WordList recursiveFind(BstNode *node, char searchValue);
    //void freeBinaryTreePrivate(BstNode *node);

public:
    BST();
    ~BST();
    void insert(std::string, int);
    void PrintInOrder(BstNode *prt);
    //void freeBinaryTree();


};


#endif //WORDLISTPROJECT10_BST_H
