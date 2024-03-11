#include "ScalarConverter.hpp"

/************** constructor *************/

ScalarConverter::ScalarConverter(void) {
    std::cout << "Default constructor has been called" << std::endl;
    return;
};

ScalarConverter::ScalarConverter(ScalarConverter const &src) {return;};

ScalarConverter::~ScalarConverter(void) {return;};

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {return(*this);};

/************** function *************/

void ScalarConverter::toChar(std::string litteral)
{
    char c = litteral[0];
    int i = static_cast<int>(litteral[0]);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    std::cout << "Conversion from Char"  << std::endl;

    if (litteral == "nan" || litteral == "-inf" || litteral == "+inf")
			std::cout << "char: Impossible" << std::endl;
		else if (c < 32 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;
		if (litteral == "nan" || litteral == "-inf" || litteral == "+inf")
			std::cout << "int: Impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (f == std::floor(f) && litteral != "nan" && litteral != "-inf" && litteral != "+inf")
			std::cout << "float: " << f << ".0f" << std::endl;
		else if (litteral == "-inf" || litteral == "+inf")
			std::cout << "float: " << f << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;;
		if (d == std::floor(f) && litteral != "nan" && litteral != "-inf" && litteral != "+inf")
			std::cout << "double: " << f << ".0" << std::endl;
		else
			std::cout << "double: " << f << std::endl;

}

void ScalarConverter::toInt(std::string litteral)
{
    long long ll = std::strtol(litteral.c_str(), nullptr, 10);
    int i = static_cast<int>(ll);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    std::cout << "Conversion from Int" << std::endl;

    if (litteral == "nan" || litteral == "-inf" || litteral == "+inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    } else {

    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;

    if (ll < std::numeric_limits<int>::min() || ll > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
    }

    if (f == std::floor(f) && !std::isnan(f) && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d == std::floor(d) && !std::isnan(d) && !std::isinf(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static bool isSpecialFloat(float value) 
{
    return !(value <= std::numeric_limits<float>::max() && value >= -std::numeric_limits<float>::max());
}

static bool isnancustom(float value) {
    return value != value;
}

static bool isinfcustom(float value) {
    return std::numeric_limits<float>::has_infinity && (value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity());
}

static bool isSpecialDouble(double value) 
{
        return isnancustom(value) || isinfcustom(value);
}

std::string impossible(int n)
{
    if (n == 1)
        return "char: impossible";
    if (n == 2)
        return impossible(1) + "\nint: impossible";
    if (n == 3)
        return impossible(2) + "\nfloat: impossible";
    if (n == 4)
        return impossible(3) + "\ndouble: impossible";
    return "";
}

void    print_result(char const& c, int const& i, float const& f, double const& d)
{
    std::cout << std::fixed << std::setprecision(1); 
    if (d > 0 && isinf(d) == false && (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max()))
        std::cout << impossible(3) << "\ndouble: " << d << std::endl;
    else if (isnan(f) || isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << impossible(2) << "\nfloat: "<< f << "f\ndouble: " << d << std::endl;
    else if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << impossible(1) << "\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
    else
    {
        std::cout << "char: ";
        if (isprint(c))
            std::cout << "\'" << c << "\'";
        else
            std::cout << "Non displayable";
        std::cout<<
            "\nint: "       << i <<
            "\nfloat: "     << f <<
            "f\ndouble: "   << d << std::endl;
    }
}

bool    weird_maths(std::string const& str)
{
    std::string const special_nums[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    int i = 0;
    while (i <= 5 && str != special_nums[i])
        i++;
    if (i > 5)
        return false;
    else if (i < 3)
    {
        float f = atof(special_nums[i].c_str());
        print_result(0, 0, f, static_cast<double>(f));
    }
    else
    {
        double d = std::strtod(str.c_str(), NULL);
        print_result(0, 0, static_cast<float>(d), d);
    }
    return (true);
}

void ScalarConverter::toFloat(std::string litteral)
{
    std::cout << "Conversion from Float" << std::endl;
    if (!litteral.empty() && (litteral.back() == 'f' || litteral.back() == 'F')) 
        litteral.erase(litteral.size() - 1);

    std::istringstream iss(litteral);
    float f;

    if (!(iss >> f)) 
    {
        std::cout << "Conversion to float failed." << std::endl;
        return;
    }

    double d = static_cast<double>(f);
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
  
    if (litteral == "nan" || litteral == "-inf" || litteral == "+inf")
        std::cout << "char: impossible" << std::endl;   
    else {
        if (c < 32 || c > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
    }

    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max() || isnancustom(f) || isinfcustom(f))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (f == static_cast<float>(static_cast<int>(f)) && !isSpecialFloat(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (d == static_cast<double>(static_cast<int>(d)) && !isSpecialFloat(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::toDouble(std::string litteral)
{
    std::cout << "Conversion from Double" << std::endl;
    std::istringstream iss(litteral);
    
    double d;

    if (!(iss >> d)) 
    {
        std::cout << "Conversion to double failed." << std::endl;
        return;
    }

    int i = static_cast<int>(d);
    char c = static_cast<char>(d);
    float f = static_cast<float>(d);
    
    if (litteral == "nan" || litteral == "-inf" || litteral == "+inf")
        std::cout << "char: impossible" << std::endl; 
    else if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || isnancustom(d) || isinfcustom(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (f == static_cast<float>(static_cast<int>(f)) && !isSpecialDouble(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (d == static_cast<double>(static_cast<int>(d)) && !isSpecialDouble(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}


enum Type{
    Char,
    Int,
    Float,
    Double,
    Invalid,
    Special
};

static Type checkType(std::string const &litteral)
{
    if(litteral.back() == 'f')
    	return Float;
    else if (litteral.find('.') != std::string::npos)
        return Double;
    else if (litteral.length() > 0)
    {
        if(isdigit(litteral.c_str()[0]) || ((litteral.c_str()[0] == '-' || litteral.c_str()[0] == '+') && isdigit(litteral.c_str()[1])))
               return Int;
        else if (litteral.length() > 1)
    	    return Special;
        else
    	    return Char ;
    }
    else
        return Invalid;
    return Invalid;
}

void ScalarConverter::toSpecial(std::string litteral)
{
    (void)litteral;
    std::cout << "Conversion from Special"  << std::endl;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert(std::string const &litteral)
{
    if (weird_maths(litteral))
    {
        return;
    }
    switch (checkType(litteral))
    {
        case Char:
            toChar(litteral);
            break;
        case Int:
            toInt(litteral);
            break;
        case Float:
            toFloat(litteral);
            break;
        case Double:
            toDouble(litteral);
            break;
        case Special:
            toSpecial(litteral);
            break;
        default:
            std::cout << "Error: Invalid type" << std::endl;
            break;
    }
}
//std::ostream &operator<<(std::ostream &o, ScalarConverter const &i) {o << i.get();return o;};