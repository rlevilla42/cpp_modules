#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP
#include <iostream>
#include <time.h>
#include <ctime>
#include <vector>
#include <list>
#include <exception>
#include <cstdlib>
#include <set>
#include <typeinfo>
class	PmergeMe
{

public:
	PmergeMe(PmergeMe const & src);
	PmergeMe&	operator=(PmergeMe const& rhs);

    bool    sort(int ac, char** str, bool check_sort = false) const;

	PmergeMe(void);
	~PmergeMe(void);

private:
    typedef std::vector<unsigned int>   pvector;
    typedef std::list<unsigned int>     plist;
    typedef plist::iterator             plist_it;

    void    checkStr(int ac, char** av) const;
    void    parse(int ac, char** av, pvector& vec) const;
    void    parse(int ac, char** av, plist& list) const;
    template <typename T>
    void    mergeInsertSort(T& cont, size_t l, size_t r) const;
    void    mergeSort(pvector& vec, size_t l, size_t m, size_t r) const;
    void    mergeSort(plist& list, size_t l, size_t m, size_t r) const;
    void    insertSort(pvector& vec, size_t l, size_t r) const;
    void    insertSort(plist& list, size_t l, size_t r) const;
    void    printResults(struct timeval timer[2][2], pvector const& vec, plist const& list) const;
    void    optimizeListIt(plist& list, plist_it& it, plist_it& end, size_t l, size_t r) const;

    class   BadFormat : public std::exception
    {
        char const* what() const throw() {return "Something wrong with the input\nplease make sure that no numbers are negative, no strings are empty and that there are no characters other than numbers inside the strings";}
    };
    class   DupInput : public std::exception
    {
        char const* what() const throw() {return "Duplicate string in input";}
    };
};

#endif
