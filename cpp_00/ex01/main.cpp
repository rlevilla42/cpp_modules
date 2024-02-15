#include "header.hpp"
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main(void)
{
    std::string input;
    char        c;
    PhoneBook   book;
    int         nb_of_contact = 0;

    while (input != "add" && input != "search" && input != "exit")
    {
        std::cout << "Write only one these three instructions. " << std::endl << "Write 'ADD' to add a contact to the book contact: "<< std::endl << "Write 'SEARCH' to display a contact information "<< std::endl << "and write 'EXIT' if you want to exit the program (it will delete all the data)" << std::endl << "Now write bro: ";
        std::getline(std::cin, input);
    }
    while (1)
    {
        if (input == "add")
        {
            book.add(nb_of_contact);
            nb_of_contact++;
        }
        else if (input == "search")
        {
            display_all(book, nb_of_contact);
            book.search(nb_of_contact);
        }
        else if (input == "exit")
        {
            break;
        }
        std::cout << "Choose again between 'add' and 'search' (or tap 'exit' to quit): ";
        std::getline(std::cin, input);
        if (input != "add" && input != "search" && input != "exit")
        {
            std::cout << "Don't know this instruction. " << std::endl;
        }
        //continue;
    }
    return (0);
}