#include "header.hpp"

void	PhoneBook::add(int nb_of_contact) {
	Contact 	new_contact;
	int			index = nb_of_contact % 8;
	new_contact.create();
	new_contact.index = index;
	if (nb_of_contact <= 7 && nb_of_contact >= 0)
	{
		this->contact[index] = new_contact;
	}
	else if (nb_of_contact > 7)
	{
		this->contact[index] = new_contact;
	}
	return;
}

void	PhoneBook::search(int nb_of_contact)
{
	std::string str;
	int         index;

	if (nb_of_contact == 0)
	{
		return;
	}
	if (nb_of_contact > 0)
    {
        std::cout << std::endl << "Write the index of the contact you want to see the informations: ";
        std::getline(std::cin, str);
        if (str.empty() || str.length() > 1 || str[0] < 48 || str[0] > 57)
            return;
	}
	index = str[0] - 48;
	if (index > nb_of_contact - 1)
	{
		std::cout << "Nothing exist at this index." << std::endl;
		return;
	}
	std::cout << "first name: " << this->contact[index].firstName << std::endl;
	std::cout << "last name: " << this->contact[index].lastName << std::endl;
	std::cout << "nick name: " << this->contact[index].nickName << std::endl;
	std::cout << "phone number: " << this->contact[index].phoneNumber << std::endl;
	std::cout << "darkest secret: " << this->contact[index].darkestSecret << std::endl;
	return;
}