//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#ifndef PROJECT10_BINARYTREE_H
#define PROJECT10_BINARYTREE_H

#include "WordList.h"
#include "TreeNode.h"

template <class T>
class Tree
{
    // Internal class which stores only Node related information.
//public:
//    struct TreeNode
//            : public TreeNode {
//
//    };

private:
    void freeMemory(TreeNode<T> *);


public:
    TreeNode<T> *root;
    Tree();
    ~Tree();
    T *insert(T *);
    void print();
};

template <class T>
Tree<T>::Tree():root(NULL){

}

template <class T>
Tree<T>::~Tree()
{
    freeMemory(root);
}

template <class T>
void Tree<T>::freeMemory(TreeNode <T> *node)
{
    if (node==NULL)
        return;
    if (node->left)
        freeMemory(node->left);
    if (root->right)
        freeMemory(node->right);
    delete node;
}

template <class T>
//make it return value?
T *Tree<T>::insert(T *val)
{
    TreeNode<T> *treeNode = NULL;
    try
    {
        treeNode = new TreeNode<T>();
        treeNode->data = val;
    } catch (std::bad_alloc &exception)
    {
        std::cerr << "bad_alloc caught: " << exception.what() << std::endl;
        EXIT_FAILURE;
    }
    TreeNode<T> *temp=NULL;
    TreeNode<T> *prev=NULL;

    temp = root;
    while(temp)
    {
        prev = temp;
        if (*temp->data == *treeNode->data)
            return temp->data;
        else if (*temp->data < *treeNode->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    if (prev==NULL)
        root = treeNode;
    else
    {
        if (*prev->data<*treeNode->data)
            prev->right = treeNode;  // use setter function?
        else
            prev->left = treeNode;
    }
    return treeNode->data;
}

#endif //PROJECT10_BINARYTREE_H
