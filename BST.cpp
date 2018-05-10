//
// Created by phuoc quang on 4/29/18.
//

#include "BST.h"
#include "WordList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

#include <bitstring.h>
BST::BST() {
    root = nullptr;
}

BST::~BST() {
    BST::freeBinaryTree();
}

void BST::insert(std::string word, int line) {
    /* If the tree is empty, return a new Node */
    if(root == nullptr){
        root = new BstNode(word, line);
        return;
    }
    BstNode *cur;
    cur = root;
    //for(;;){
        compare(cur, word, line);
    //}
}

void BST::compare(BstNode *node, std::string w, int l) {
    // Word from user input
    std::string inputString = w;
    std::transform(inputString.begin(),inputString.end(),inputString.begin(),::tolower);
    //get word from binary search tree
    std::string getString = node->wordList->getWord();
    std::transform(getString.begin(),getString.end(),getString.begin(),::tolower);

    if(inputString.compare(getString) == 0){
        node->wordList->createLineNode(l);
        return;
    }else if(inputString.compare(getString) < 0){
        if(node->leftNode != nullptr){
            //node = node->leftNode;
            compare(node->leftNode, inputString, l);
        }else{
            node->leftNode = new BstNode(w,l);
            return;
        }
    }else if(inputString.compare(getString) > 0){
        if(node->rightNode != nullptr){
            //node = node->rightNode;
            compare(node->rightNode, inputString,l);
        }else{
            node->rightNode = new BstNode(w,l);
            return;
        }
    }
}

//void BST::compare(BstNode *node, std::string w, int l) {
//    if(w.compare(node->wordList->getWord()) == 0){
//        node->wordList->createLineNode(l);
//        return;
//    }
//    if(w.compare(node->wordList->getWord()) < 0){
//        if(node->leftNode != nullptr){
//            //node = node->leftNode;
//            compare(node->leftNode, w, l);
//        }else{
//            node->leftNode = new BstNode(w,l);
//            return;
//        }
//    }else if(w.compare(node->wordList->getWord()) > 0){
//        if(node->rightNode != nullptr){
//            //node = node->rightNode;
//            compare(node->rightNode, w,l);
//        }else{
//            node->rightNode = new BstNode(w,l);
//            return;
//        }
//    }
//}

//WordList* BST::searchWord(BST::BstNode *root, std::string searchW) {
////    if(root == nullptr){
////        return nullptr;
////    }
////    if(root->wordList->getWord() == searchW){
////        return root->wordList;
////    }else if(searchW > root->wordList->getWord()){
////        return searchWord(root->rightNode, searchW);
////    }else if(searchW < root->wordList->getWord()){
////        return searchWord(root->leftNode, searchW);
////    }
////}

WordList* BST::searchWord(BST::BstNode *root, std::string searchW) {
    if(root == nullptr){
        return nullptr;
    }
    std::string searchString = searchW;
    std::transform(searchString.begin(),searchString.end(),searchString.begin(),::tolower);
    std::string getString = root->wordList->getWord();
    std::transform(getString.begin(),getString.end(),getString.begin(),::tolower);


    if(getString == searchString){
        return root->wordList;
    }else if(searchString > getString){
        return searchWord(root->rightNode, searchString);
    }else if(searchString < getString){
        return searchWord(root->leftNode, searchString);
    }else{
        return nullptr;
    }
}
void BST::search(std::string word) {
    WordList *wl = searchWord(root, word);
    if(wl == nullptr){
        std::cout << "There are no matching word." << std::endl;
    }else{
        std::cout << "\""<< word <<"\":" << " is at line number " ;
        std::cout << wl->getLines();
        std::cout << "\n==============================" << std::endl;
    }
}

void BST::printNodeToFile(BstNode *parent, std::ofstream &outFile) {
    //std::ofstream outFile("BSTOutput.txt");
    if (root == nullptr) {
        outFile << "Binary Tree is empty.\n";
        exit(1);
    }

    if(parent) {
        printNodeToFile(parent->leftNode, outFile);
        outFile << "\"" << parent->wordList->getWord() << "\""<< " at line number: ";

        //output lines to file
        outFile << parent->wordList->getLines() << std::endl;
        printNodeToFile(parent->rightNode, outFile);

    }
}
void BST::printNodeToScreen(BstNode *parent){
    if (root == nullptr) {
        std::cout << "Empty tree." << std::endl;
        exit(1);
    }
    if(parent){
        printNodeToScreen(parent->leftNode);
        std::cout << "\"" << parent->wordList->getWord() << "\""<< " at line number: ";
        //parent->wordList->getLine();
        std::cout << parent->wordList->getLines() << std::endl;
        printNodeToScreen(parent->rightNode);
    }
}

void BST::printTreeInOrder(){
    std::cout << "LIST OF WORDS:\n" <<std::endl;
    printNodeToScreen(root);
    std::ofstream outFile("BSTOutput.txt");
    outFile << "LIST OF WORDS\n\n";
    printNodeToFile(root,outFile);
    outFile.close();
}

void BST::freeBinaryTree() {
    freeBinaryTreePrivate(root);
}

void BST::freeBinaryTreePrivate(BST::BstNode *node) {
    if(node == nullptr){
        return;
    }
    freeBinaryTreePrivate(node->leftNode);
    freeBinaryTreePrivate(node->rightNode);
    delete(node);
}