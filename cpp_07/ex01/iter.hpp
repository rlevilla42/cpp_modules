# ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>

template <typename T>
void    iter(T *array, size_t array_lenght, void (*funct)(T &)){
    for (size_t i = 0; i < array_lenght ; i++)
        funct(array[i]);
};

/*template <typename T>
void    iter(T *array, size_t array_lenght, void (*f) (T&)){
    for (size_t i = 0; i < array_lenght ; i++)
        f(array[i]);
};*/
#endif
