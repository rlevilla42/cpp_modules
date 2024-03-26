#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** argv)
{
    if (ac != 2)
    {
        std::cerr << "usage: ./btc [input.txt]" << std::endl;
        return 1;
    }
    BitcoinExchange a;
    a.execute(argv[1]);
    return (0);
}
/*2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 21474836488*/