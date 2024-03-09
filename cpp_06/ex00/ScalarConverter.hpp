#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>
#include <string>
# include <fstream>
# include <ctime>
# include <limits>
# include <sstream>
# include <cmath>

class ScalarConverter {
public:
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const &src);
    ~ScalarConverter(void);

    static void convert(std::string const &litteral);
    ScalarConverter &operator=(ScalarConverter const &rhs);
private:
    static void toSpecial(std::string litteral);
    static void toChar(std::string litteral);
    static void toInt(std::string litteral);
    static void toFloat(std::string litteral);
    static void toDouble(std::string litteral);
};

std::ostream &operator<<(std::ostream &o, ScalarConverter const &i);
#endif