#include "header.hpp"
//#include <iostream>
//#include <iomanip>

std::string cut_str(std::string str)
{
    std::string new_str;

    if (str.length() > 10)
    {
        new_str = str.substr(0, 10);
        new_str[9] = '.';
        return new_str;
    }
    return str;
}

void    display_one(Contact contact)
{
    std::cout << std::setw(10) << contact.index << " |";
    std::cout << std::setw(10) << cut_str(contact.firstName) << " |";
    std::cout << std::setw(10) << cut_str(contact.lastName) << " |";
    std::cout << std::setw(10) << cut_str(contact.nickName) << " |" << std::endl;
    return;
}

void    display_all(PhoneBook book, int nb_of_contact)
{
   int  index = 0;
   if (nb_of_contact == 0)
   {
        std::cout << "Create at least one contact before -___-"<< std::endl;
        return;
   }
   if (nb_of_contact < 9)
   {
        while (index < nb_of_contact)
        {
            display_one(book.contact[index]);
            index++;
        }
    }
    else
    {
        while (index < 8)
        {
            display_one(book.contact[index]);
            index++;
        }
    }
    return;
}