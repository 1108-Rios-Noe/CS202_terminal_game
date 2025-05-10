#ifndef BOARDARRAY_H
#define BOARDARRAY_H

#include <iostream>
using namespace std;

template <typename T> class BoardArray{
    T*** data;
    int size;

    public:
        BoardArray();
        BoardArray(int);
        BoardArray(const BoardArray<T>&);
        ~BoardArray();

        T*** getData();
        int getSize();
        T& getDataXY(int, int);

        void setDataXY(int, int, T&);

        void setData(T***);
        void setSize(int);
        
        void print() const;

        friend ostream& operator<<(ostream&, const BoardArray<T>&);
};

#endif