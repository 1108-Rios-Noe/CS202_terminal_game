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

        T*** getData();
        int getSize();
        T getDataXY(int, int);

        void setData(T***);
        void setSize(int);
        
        T& operator()(int x, int y);
        void print() const;

        friend ostream& operator<<(ostream&, const boardArray<T>&);
};

#endif