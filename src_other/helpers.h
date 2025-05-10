#ifndef HELPERS_H
#define HELPERS_H
//
// Simple template function to satisfy the requirement of needing a template function
//only needs the h file as its a template
template<typename T> void swapValues(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

#endif