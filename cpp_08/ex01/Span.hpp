#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
public:
    Span(void);
    Span(unsigned int n);
    Span(Span const &src);
    ~Span(void);

    template <typename IT>
        void addNumber(IT start, IT end)
        {
            if (start == end)
                throw (emptySpanException());
            if (_array.size() + std::distance(start, end) > getSize())
                throw (maxSpanSizeException());
            std::copy(start, end, std::back_inserter(_array));
        }
    void    addNumber(unsigned int n);
    int    shortestSpan(void);
    int    longestSpan(void);
    int             getNumber(size_t n) const;
    unsigned int    getSize(void) const;
    Span &operator=(Span const &rhs);

    class emptySpanException: public std::exception {
        const char* what() const throw() {
            return "Empty Span !";
        };
    };
    class oneElementSpanException: public std::exception {const char* what() const throw() {return "There's only one element insinde the Span";};};
    class maxSpanSizeException: public std::exception {const char* what() const throw() {return "Span is full amigo";};};

private:
    std::vector<int>    _array;
    unsigned int        _sizeMax;
};

std::ostream &operator<<(std::ostream &o, Span const &c);
#endif