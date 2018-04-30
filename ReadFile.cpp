//
// Created by phuoc quang on 4/29/18.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "ReadFile.h"

ReadFile::ReadFile() {
    bst = new BST;
    //fileName = "text-file.txt";
}
void *ReadFile::readFile(std::string fileName) {
    static int lineNumber = 0;
    std::fstream inFile(fileName);
    if(inFile.is_open()){
        while(inFile){
            std::string line;

            std::cout << std::endl;
            lineNumber++;
            std::cout <<lineNumber<<"-----------------"<<std::endl;
            if(!getline(inFile, line)) break;
       // while(getline(inFile,line, ' ') || getline(inFile, line, '.') || getline(inFile, line, ',')){

            std::istringstream iss(line);


            //while(iss >> word){
            while(iss){
                std::string word;
                //if(!getline(iss,word, ' ') || !getline(iss,word,'.') || !getline(iss,word, ',')) break;
                if(!getline(iss,word, ' ')) break;
                    std::cout << word<< std::endl;
                    bst->insert(word, lineNumber);
                //i++;
            }

        }

    }else{
        std::cout <<"Error opening file"<< std::endl;
    }
    inFile.close();

}
