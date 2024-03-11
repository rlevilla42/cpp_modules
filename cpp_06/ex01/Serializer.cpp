#include "Serializer.hpp"

/************** constructor *************/

Serializer::Serializer(void) {return;};

Serializer::Serializer(Serializer const &src) {return;};

Serializer::~Serializer(void) {return;};

Serializer &Serializer::operator=(Serializer const &rhs) {return(*this);};

/************** function *************/
uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data*       Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
//std::ostream &operator<<(std::ostream &o, Serializer const &i) {o << i.get();return o;};