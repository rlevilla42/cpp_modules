#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP
#include "header.hpp"

class   PhoneBook {
    public:
    void		add(int nb_of_contact);
    void	    search(int nb_of_contact);
    void		exit(void);
    Contact     contact[9];
    int         index;
    int		    nbMaxContact;
};

#endif