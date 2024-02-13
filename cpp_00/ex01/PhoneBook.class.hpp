#include "header.hpp"

class   PhoneBook {
    public:
    void		add(void);
    void	    search(int index);
    void		exit(void);
    private:
    Contact contact[8];
    int     index;
    int		nbMaxContact;
};

void    display(void)
{
    std::string i = "index";
    std::string fn = "first name";
    std::string ln = "last name";
    std::string nn = "nickname";
    std::cout << std::setw(10) << i << " |";
    std::cout << std::setw(10) << fn << " |";
    std::cout << std::setw(10) << ln << " |";
    std::cout << std::setw(10) << nn << " |" << std::endl;
}

int main(void)
{
    display();
}