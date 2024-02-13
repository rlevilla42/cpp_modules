#include "header.hpp"

void	PhoneBook::add(int nb_of_contact) {
	Contact 	new_contact;
	int			index = nb_of_contact % 8 + 1;
	new_contact.create();
	new_contact._index = index;
	if (nb_of_contact <= 8 && nb_of_contact >= 1)
	{
		this->contact[index] = new_contact;
	}
	else if (nb_of_contact > 8)
	{
		this->contact[index] = new_contact;
	}
	return;
}

void	PhoneBook::search(int index)
{

}