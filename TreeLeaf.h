//
// Created by Sangalang, Emmanuel on 5/14/18.
//

#ifndef PROJECT10_TREELEAF_H
#define PROJECT10_TREELEAF_H

template <class T>
class TreeLeaf {

public:
    T *data;
    TreeLeaf * left;
    TreeLeaf * right;

    TreeLeaf(T *val) {
        this->data = val;
    }
};



#endif //PROJECT10_TREELEAF_H
