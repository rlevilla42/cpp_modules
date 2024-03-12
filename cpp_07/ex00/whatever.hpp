#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename S>
void swap(S &a, S &b) {
    S c;
    c = a;
    a = b;
    b = c;
}

template <typename T>
T   min(T &a, T &b) {
    return (b <= a ? b : a);
}

template <typename Z>
Z   max(Z &a, Z &b) {
    return (a >= b ? a : b);
}
#endif