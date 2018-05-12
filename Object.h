//
// Created by Sangalang, Emmanuel on 5/11/18.
//

#ifndef PROJECT10_OBJECT_H
#define PROJECT10_OBJECT_H

class Object {
public:
    virtual bool operator < (Object const &object);
    virtual bool operator > (Object const &object);
    virtual bool operator == (Object const &object);
};

#endif //PROJECT10_OBJECT_H
