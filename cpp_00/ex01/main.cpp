#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main(void)
{
    std::string input;
    PhoneBook   book;
    int         nb_of_Contact = 1;
    int         input_search;
    std::cout << "Write 'ADD' to add a contact to the book contact: "<< std::endl << "Write 'SEARCH' to display a contact information "<< std::endl << "and write 'EXIT' if you want to exit the program (it will delete all the data)" << std::endl << "Now write bro: ";
    std::cin >> input;
    while (input == 'add' || input == 'search')
    {
        if (input == 'add')
        {
            book.add(nb_of_contact);
            nb_of_Contact++;
        }
        if (input == 'search')
        {
            std::cout << "Write the index of the contact you want to see the informations: ";
            std::string(std::cin, input);
            input_search = input - 48;
            book.search(input_search);
        }
        std::cout << "Write 'ADD' to add a new contact to the book contact: "<< std::endl << "Write 'SEARCH' to display a contact information "<< std::endl << "and write 'EXIT' if you want to exit the program (it will delete all the data)" << std::endl << "Now write bro: ";
        std::cin >> input;
    }
    return (0);
}