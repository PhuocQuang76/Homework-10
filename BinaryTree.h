//
// Created by Sangalang, Emmanuel on 5/10/18.
//

#ifndef PROJECT10_BINARYTREE_H
#define PROJECT10_BINARYTREE_H

template<class T>
class BinaryTree {
protected:
    static BinaryTree<T> *root;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree<T> * traverseNode(BinaryTree<T> *leaf, T newLeaf);
    T *object;
public:
    static BinaryTree<T> *getRoot();

    static void setRoot(BinaryTree<T> *root);

    BinaryTree<T> *getLeft() const;

    void setLeft(BinaryTree<T> *left);

    BinaryTree<T> *getRight() const;

    void setRight(BinaryTree<T> *right);

    BinaryTree<T> *addLeaf(T leaf);

    T *getObject() const;

    void setObject(T *object);
};


#endif //PROJECT10_BINARYTREE_H
