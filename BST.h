//
// Created by phuoc quang on 4/29/18.
//

#ifndef WORDLISTPROJECT10_BST_H
#define WORDLISTPROJECT10_BST_H

#include "WordList.h"

class BST {
private:
    struct BstNode{
        BstNode(std::string &word, int &line){
            wordList = new WordList();
            wordList->setWord(word);
            wordList->createLineNode(line);
            leftNode = nullptr;
            rightNode = nullptr;
        }
        WordList *wordList;
        BstNode *leftNode, *rightNode;
    };
    BstNode *root;
    void freeBinaryTreePrivate(BstNode *node);

public:
    BST();
    ~BST();
    void insert(std::string word, int line);
    void compare(BstNode *node, std::string s, int l);

    WordList *searchWord(BstNode *root, std::string searchW);
    void search(std::string word);

    void printNodeToFile(BstNode *parent,std::ofstream &outFile);
    void printNodeToScreen(BstNode *parent);
    void printTreeInOrder();

    void freeBinaryTree();
};


#endif //WORDLISTPROJECT10_BST_H
