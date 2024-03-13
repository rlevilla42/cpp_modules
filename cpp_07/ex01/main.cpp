#include "iter.hpp"
#include <iostream>

template <typename T>
void    print_type(T& a)
{
    std::cout << "print:" << a << std::endl;
    a += 42;
}

int main(void)
{
    int a[] = {42, 24, 2, 4, 4, 2};
    std::string b[] = {"Wapiti", "Lama", "Wapitilamasticot"};

    std::cout << "-----ITER 1" << std::endl;
    iter(a, sizeof(a) / sizeof(a[0]), print_type);
    iter(b, sizeof(b) / sizeof(b[0]), print_type);
    std::cout << "-----ITER 2" << std::endl;
    //iter2(a, print_type);
    //iter2(b, print_type);
}