#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
//
#include <iostream>
using namespace std;
//Class that makes an array with a certain data type specified when making it, makes it a certain size
//makes an array of any data type and handles the memory
template<typename T> class DynamicArray {
    T* data;
    int size;

    public:
        DynamicArray(){
            size = 5;
            data = new T[size];
        }
        DynamicArray(int n) {
            size = n;
            data = new T[n];
        }
        DynamicArray(const DynamicArray<T>& rhs){
            size = rhs.size;
            data = new T[size];
            for(int i = 0; i < size; i++){
                data[i] = rhs.data[i];
            }
        }
        ~DynamicArray() {
            delete[] data;
        }
        T& operator[](int i) { //this method is key to many things (used a lot)
            return data[i];
        }
        int getSize() const {
            return size;
        }
        DynamicArray<T>& operator=(const DynamicArray<T>& rhs){
            size = rhs.size;
            data = new T[size];
            for(int i = 0; i < size; i++){
                data[i] = rhs.data[i];
            }
            return *this;
        }
        friend ostream& operator<<(ostream& os, const DynamicArray<T>& arr) {
            os << "DynamicArray(size=" << arr.size << ")";
            return os;
        }
};

#endif // DYNAMICARRAY_H