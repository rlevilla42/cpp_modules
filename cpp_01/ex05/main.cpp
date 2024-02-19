#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl Jean_guy;
    if (argc != 2)
    {
        std::cerr << "Bro fais un effort stp et met le bon nombre dárgument merci -__-" << std::endl;
        return (1);
    }
    Jean_guy.complain(argv[1]);
    return (0);
}