#include "boardArray.h"

//makes the default board with size 5, 5 in x and 5 in y and fills it with empty elements
template <typename T> BoardArray<T>::BoardArray(){
    size = 5;
    data = new T**[size];
    for(int i = 0; i < size; i++){
        data[i] = new T*[size];
        for(int j = 0; j < size; j++){
            data[i][j] = new T();
        }
    }

}

template <typename T> BoardArray<T>::BoardArray(int size_){
    size = size_;
    data = new T**[size];

    for(int i = 0; i < size; i++){
        data[i] = new T*[size];
        for(int j = 0; j < size; j++){
            data[i][j] = new T();
        }
    }
}

template <typename T> BoardArray<T>::~BoardArray(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            delete data[i][j];
        }
        delete [] data[i];
    }
    delete [] data;
}

template <typename T> T*** BoardArray<T>::getData(){
    return data;
}

template <typename T> int BoardArray<T>::getSize(){
    return size;
}

template <typename T> T& BoardArray<T>::getDataXY(int x, int y){
    return data[x][y];
}

template <typename T> void BoardArray<T>::setDataXY(int x, int y, T& element){
    data[x][y] = &element;
}

template <typename T> void BoardArray<T>::setData(T*** data_){
    data = data_;
}

template <typename T> void BoardArray<T>::setSize(int size_){
    size = size_;
}

template <typename T> void BoardArray<T>::print() const{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << *data[i][j] << " ";
        }
        // cout << endl;
    }
}

template <typename T> ostream& operator<<(ostream& os, const BoardArray<T>& board){
    for(int i = 0; i < board.size; i++){
        for(int j = 0; j < board.size; j++){
            os << *board.data[i][j] << " ";
        }
        // os << endl;
    }
    return os;
}