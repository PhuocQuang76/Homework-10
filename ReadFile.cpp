//
// Created by phuoc quang on 4/29/18.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "ReadFile.h"
#include <vector>

ReadFile::ReadFile() {
    bst = new BST;
}

void *ReadFile::readFile(std::string fileName) {
    static int lineNumber = 0;
    std::ifstream inFile(fileName);
    if(inFile.is_open()) {
        //Check if file is empty
        if(inFile.peek() == std::ifstream::traits_type::eof()){
            std::cout << "File is empty !!!" << std::endl;
            exit(1);
        }
        while (inFile) {
            std::string line;
            lineNumber++;
            if (!getline(inFile, line)) break;
            std::istringstream iss(line);
            while (iss) {
                std::string word;
                if (!getline(iss, word, ' ')) break;
                // copying the contents of the string to char array
                std::vector<char> cWord(word.begin(), word.end());
                char front = cWord[0];
                char back = cWord.back();
                //strcpy(cWord, word.c_str());
                if ((int) front >= 65 && (int) front <= 122) {
                    if ((int) front > 90 && (int) front < 97) {
                        cWord.erase(cWord.begin());
                    }
                } else {
                    cWord.erase(cWord.begin());
                }
                if ((int) back >= 65 && (int) back <= 122) {
                    if ((int) back > 90 && (int) back < 97) {
                        cWord.pop_back();
                    }
                } else {
                    cWord.pop_back();
                }
                std::string sWord(cWord.begin(), cWord.end());
                bst->insert(sWord, lineNumber);
            }
        }
    }else{
        std::cout <<"Error opening file"<< std::endl;
    }
    inFile.close();
}

void ReadFile::search() {
    std::string searchWord;
    std::cout << "\nEnter the word you want to search : " ;
    std::cin >> searchWord;
    bst->search(searchWord);
}

void ReadFile::print() {
    bst->printTreeInOrder();
}

