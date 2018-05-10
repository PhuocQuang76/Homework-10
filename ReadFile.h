//
// Created by phuoc quang on 4/29/18.
//

#ifndef WORDLISTPROJECT10_READFILE_H
#define WORDLISTPROJECT10_READFILE_H
#include <string>
#include <iostream>
#include <fstream>
#include "WordList.h"
#include "BST.h"


class ReadFile {
protected:
    BST *bst;
    //std::string fileName;


public:
    ReadFile();
    ~ReadFile();
    void *readFile(std::string fileName);
    void search();
    void print();

};


#endif //WORDLISTPROJECT10_READFILE_H
