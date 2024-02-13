#include "header.hpp"

PhoneBook::add(int nb_of_contact) {
	Contact 	new_contact;
	int			index = nb_of_contact % 8 + 1;
	new_contact.create();
	new_contact._index = index;
	if (nb_of_contact <= 8 && nb_of_contact >= 1)
	{
		PhoneBook.contact[index] = new_contact;
	}
	else if (nb_of_contact > 8)
	{
		PhoneBook.contact[index] = new_contact;
	}
	return;
}

PhoneBook::search(int index)
{

}