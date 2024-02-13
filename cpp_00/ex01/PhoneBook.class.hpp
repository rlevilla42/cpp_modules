#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP
#include "header.hpp"

class   PhoneBook {
    public:
    void		add(int nb_of_contact);
    void	    search(int index);
    void		exit(void);
    private:
    Contact contact[8];
    int     index;
    int		nbMaxContact;
};

#endif