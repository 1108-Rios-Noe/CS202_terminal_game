#ifndef BOARDARRAY_H
#define BOARDARRAY_H

#include <iostream>
using namespace std;

template <typename T> class boardArray{
    T*** data;
    int size;

    public:
        boardArray();
        boardArray(int);
        boardArray(const boardArray<T>&);
        ~boardArray();
        
        T& operator()(int x, int y);
        void print() const;
};

#endif