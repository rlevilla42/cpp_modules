#include "Serializer.hpp"
#include <iostream>

typedef struct  Data
{
    std::string wapiti;
    int         integer_of_type1;
    void*       calamity;
}               Data;

int main(void)
{
    Data*       the_data = new Data;
    uintptr_t   the_weird_pointer;
    Data*       data_prime;

    the_data->wapiti            = "A kind of antelope.";
    the_data->integer_of_type1  = 42;
    the_data->calamity          = &the_data->integer_of_type1;

    the_weird_pointer   = Serializer::serialize(the_data);
    data_prime          = Serializer::deserialize(the_weird_pointer);

    std::cout << "Data : "<< the_data->wapiti << " has " <<
                the_data->integer_of_type1 << " friends at " <<
                *static_cast<int*>(the_data->calamity) << "Lausanne." << std::endl;
    std::cout << "Data_prime : "<< data_prime->wapiti << " has " <<
                data_prime->integer_of_type1 << " friends at " <<
                *static_cast<int*>(data_prime->calamity) << "Lausanne." << std::endl;
    std::cout << "Adresses: " << the_data << ":" << reinterpret_cast<std::string*>(the_weird_pointer) << ":" << data_prime << std::endl;

    delete the_data;
    return 0;
}