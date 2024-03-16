#include "Span.hpp"

/************** constructor *************/

Span::Span(void) {return;};

Span::Span(unsigned int n): _sizeMax(n) {return;};

Span::Span(Span const &src) {
    if (this != &src)
    {
        *this = src;
    }
    return;
};

Span::~Span(void) {return;};

Span &Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        this->_sizeMax = rhs._sizeMax;
        for (int i = 0; i < rhs._array.size(); i++) {
            this->_array[i] = rhs._array[i];
        }
    }
    return(*this);
};

/************** function *************/

void    Span::addNumber(unsigned int n) {
    if (this->_array.size() >= this->_sizeMax) {
        throw maxSpanSizeException();
    }
    this->_array.push_back(n);
    return ;
};

int    Span::shortestSpan(void) {

    /****** check all error ******/

    if (this->_array.empty()) {
        throw emptySpanException();
    } else if (this->_array.size() == 1) {
        throw oneElementSpanException();
    }

    /****** copy the array in a temp and sort it ******/

    std::vector<int>    temp;
    for (int i = 0; i < this->_array.size(); i++) {
        //temp[i] = this->_array[i];
        temp.push_back(this->_array[i]);
    }
    std::sort(temp.begin(), temp.end());
    int shortest = temp[1] - temp[0]; // give a first value to shortest
    for (size_t i = 1; i < temp.size() - 1; ++i) {
        int span = temp[i + 1] - temp[i]; //compute every difference size value
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
};

int    Span::longestSpan(void) {
    if (this->_array.empty()) {
        throw emptySpanException();
    } else if (this->_array.size() == 1) {
        throw oneElementSpanException();
    }
    std::vector<int>::iterator min = std::min_element(this->_array.begin(), this->_array.end());
    std::vector<int>::iterator max = std::max_element(this->_array.begin(), this->_array.end());
    int longest = *max - *min;
    if (longest < 0)
        longest *= -1;
    return longest;
};

int     Span::getNumber(size_t n) const
{
    if (n < _sizeMax)
        return _array[n];
    return 0;
}
unsigned int     Span::getSize() const
{
    return _sizeMax;
}

std::ostream&   operator<<(std::ostream& o, Span const& c)
{
    o << "Span: ";
    for (size_t i = 0; i < c.getSize(); i++)
    {
        o << c.getNumber(i);
        if (i + 1 < c.getSize())
            o << ", ";
    }
    return o;
}