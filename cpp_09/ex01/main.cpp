#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "usage: ./RPN [\"n1 n2 n3.. o1 o2...\"] (n=numbers,o=operators)" << std::endl;
        return 1;
    }
    RPN::calc(av[1]);
}
