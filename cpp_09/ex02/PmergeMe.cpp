#include "PmergeMe.hpp"
#include <cctype>
#include <ctime>
#include <iomanip>
#include <sys/time.h>
template <typename Iterator>
bool isSorted(Iterator begin, Iterator end);
template<typename T>
void printVector(const std::string& name, const std::vector<T>& vec);
//--------------Functions----------------//

void    PmergeMe::printResults(struct timeval timer[2][2], pvector const& vec, plist const& list) const
{
    size_t                                  i = 0;
    int                                     seconds[2]; 
    int                                     micro[2];
    std::list<unsigned int>::const_iterator end = list.end();

    end--;
    std::cout << "After: ";
    for (i = 0; i < vec.size() - 1 && i < 4; i++)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[i];
    if (vec.size() > 5)
        std::cout << "....";
    std::cout << std::endl;
    for (int i = 0; i < 2; ++i) 
    {
        seconds[i] = timer[i][1].tv_sec - timer[i][0].tv_sec;
        micro[i] = timer[i][1].tv_usec - timer[i][0].tv_usec;
        if (micro[i] < 0)
        {
            seconds[i]--;
            micro[i] += 1000000;
        }
        std::cout   << (i == 0 ? "Vector" : "List") << " version took: "
                    << seconds[i] << "." << std::setw(6) << std::setfill('0')
                    << micro[i] << "s" << std::endl;
    }
}
void    PmergeMe::mergeSort(pvector& vec, size_t l, size_t m, size_t r) const
{
    pvector tmp1(vec.begin() + l, vec.begin() + m + 1);
    pvector tmp2(vec.begin() + m + 1, vec.begin() + r + 1);
    size_t i_tmp1 = 0; size_t i_tmp2 = 0;

    for (;l <= r; l++)
    {
        if (i_tmp1 < tmp1.size() && (i_tmp2 == tmp2.size() || tmp1[i_tmp1] < tmp2[i_tmp2]))
        {
            vec[l] = tmp1[i_tmp1];
            i_tmp1++;
        }
        else
        {
            vec[l] = tmp2[i_tmp2];
            i_tmp2++;
        }
    }
}
void    PmergeMe::mergeSort(plist& list, size_t l, size_t m, size_t r) const
{
    plist_it    left = list.begin();
    plist_it    mid = list.begin();
    plist_it    right = list.begin();

    optimizeListIt(list, left, mid, l, m);
    mid++;
    plist       tmp1(left, mid);
    optimizeListIt(list, mid, right, m + 1, r);
    if (right != list.end())
        right++;
    plist       tmp2(mid, right);

    plist_it    tmp1_it = tmp1.begin();
    plist_it    tmp2_it = tmp2.begin();


    for (; left != right; left++)
    {
        if(tmp1_it != tmp1.end() && (*tmp1_it < *tmp2_it || tmp2_it == tmp2.end()))
        {
            *left = *tmp1_it;
            tmp1_it++;
        }
        else
        {
            *left = *tmp2_it;
            tmp2_it++;
        }
    }
}
void    PmergeMe::optimizeListIt(plist& list, plist_it& it, plist_it& end, size_t l, size_t r) const
{
    if (list.size() / 2 >= l)
    {
        it = list.begin();
        for(size_t i = 0; i < l; i++)
            it++;
        if (list.size() / 2 >= r)
        {
            end = it;
            for (size_t i = 0; i < r - l; i++)
                end++;
        }
        else
        {
            end = list.end();
            end--;
            for (size_t i = 0; i < list.size() - r - 1 ; i++)
                end--;
        }
    }
    else
    {
        end = list.end();
        end--;
        for (size_t i = 0; i < list.size() - r - 1 ; i++)
            end--;
        it = end;
        for (size_t i = 0; i < r - l; i++)
            it--;
    }
}
void    PmergeMe::insertSort(pvector& vec, size_t l, size_t r) const
{
    size_t  tmp;
    for (size_t i = l + 1; i <= r; i++)
    {
        tmp = vec[i];
        for(size_t j = i - 1;; j--)
        {
            if(vec[j] > tmp)
                vec[j+1] = vec[j];
            else
            {
                vec[j+1] = tmp;
                break;
            }
            if (j == l)
            {
                vec[j] = tmp;
                break;
            }
        }
    }
}
void    PmergeMe::insertSort(plist& list, size_t l, size_t r) const
{
    plist_it    end = list.begin();
    plist_it    begin = list.begin();
    plist_it    it_sub;
    size_t      tmp;
    optimizeListIt(list, begin, end, l, r);
    plist_it    it = begin;
    end++;
    it++;
    for (; it != end ; it++)
    {
        it_sub = it;
        it_sub--;
        tmp = *it;
        for (plist_it it_sub_post = it, it;;it_sub--, it_sub_post--)
        {
            if (*it_sub > tmp)
                *it_sub_post = *it_sub;
            else
            {
                *it_sub_post = tmp;
                break;
            }
            if (it_sub == begin)
            {
                *it_sub = tmp;
                break;
            }
        }
    }
}
template <typename T>
void    PmergeMe::mergeInsertSort(T& cont, size_t l, size_t r) const
{
    if (l >= r)
        return;
    if ((r - l <= 32 && typeid(T) == typeid(pvector))
            || (r - l <= 12 && typeid(T) == typeid(plist)))
        insertSort(cont, l, r);
    else
    {
        size_t  m = (r - l) / 2 + l;
        mergeInsertSort(cont, l, m);
        mergeInsertSort(cont, m + 1, r);
        mergeSort(cont, l, m, r);
    }
}
void    PmergeMe::parse(int ac, char** av, pvector& vec) const
{
    vec.reserve(ac - 1);
    for (int i = 1; i < ac; i++)
    {
        vec.push_back(static_cast<size_t>(atol(av[i])));
    }
}
void    PmergeMe::parse(int ac, char** av, plist& list) const
{
    for (int i = 1; i < ac; i++)
    {
        list.push_back(static_cast<size_t>(atol(av[i])));
    }
}
void    PmergeMe::checkStr(int ac, char** av) const
{
    std::set<std::string> set;
    int             i = 1;
    size_t          j = 0;
    for (int i = 1; i < ac; i++)
    {
        if(av[i][0] == 0 || av[i][0] == '-')
            throw(BadFormat());
        for (j = 0; isdigit(av[i][j]); j++);
        if (av[i][j] != 0)
            throw(BadFormat());
        if (!set.insert(av[i]).second)
            throw(DupInput());
    }
    std::cout << "sorting: " << set.size() << " elements.\n" <<"Before sorting: ";
    for (i = 1; i < ac - 1 && i < 5; i++)
    {
        std::cout << av[i] << ", ";
    }
    std::cout << av[i];
    if (ac > 6)
        std::cout << "....";
    std::cout << std::endl;
}
bool    PmergeMe::sort(int ac, char** av, bool check_sort) const
{
    try{checkStr(ac, av);}
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return false;}
    struct timeval  timer[2][2];

    gettimeofday(&(timer[0][0]), NULL);
    pvector vec;
    parse(ac, av, vec);
    mergeInsertSort(vec, 0, vec.size() - 1);
    gettimeofday(&(timer[0][1]), NULL);

    gettimeofday(&(timer[1][0]), NULL);
    plist   list;
    parse(ac, av, list);
    mergeInsertSort(list, 0, vec.size() - 1);
    gettimeofday(&(timer[1][1]), NULL);

    printResults(timer, vec, list);
    if (check_sort == true)
    {
        if (!isSorted(vec.begin(), vec.end()) || !isSorted(list.begin(), list.end()))
            std::cerr << "Sorting is somehow wrong." << std::endl;
        else
            std::cout << "Containers have been checked and it seems everything is in order" <<std::endl;
    }
    return true;
}
//--------------Operators----------------//
PmergeMe&	PmergeMe::operator=(PmergeMe const&  rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}
//--------------Constructors------------//
PmergeMe::PmergeMe(PmergeMe const &src)
{
    (void)src;
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}
//--------------Non-Member--------------//
template<typename T>
void printVector(const std::string& name, const std::vector<T>& vec) {
    std::cout << name << ": ";
    typename std::vector<T>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
template <typename Iterator>
bool isSorted(Iterator begin, Iterator end)
{
    Iterator check = begin;
    if (check == end || ++check == end)
        return true;
    
    Iterator it = begin;
    Iterator next = it;
    ++next;
    
    while (next != end)
    {
        if (*next < *it)
            return false;

        ++it;
        ++next;
    }
    return true;
}
