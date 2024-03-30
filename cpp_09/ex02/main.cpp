#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    PmergeMe merginator;
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe n1 n2 n3.." << std::endl;
        return 1;
    }
    merginator.sort(ac, av, false);
}
