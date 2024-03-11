#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

struct Data;

class Serializer {
private:
    Serializer(void);
    Serializer(Serializer const &src);

    Serializer &operator=(Serializer const &rhs);
public:
    ~Serializer(void);
    static uintptr_t   serialize(Data* ptr);
    static Data*       deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &o, Serializer const &i);
#endif