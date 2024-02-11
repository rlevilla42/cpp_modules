#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.cpp"

class   PhoneBook {
    private:
    void		add(void);
    Contact	    search(int index);
    void		exit(void);
}