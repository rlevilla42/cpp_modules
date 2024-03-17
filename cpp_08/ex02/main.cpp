#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "--Mutant stack version" << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    std::cout << "top:" << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size:" << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    //[...]
    mstack.push(6);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "--List version" << std::endl;
    std::list<int> tha_list;
    tha_list.push_back(1);
    tha_list.push_back(2);
    std::cout << "top:" << tha_list.back() << std::endl;
    tha_list.pop_back();
    std::cout << "size:" << tha_list.size() << std::endl;
    tha_list.push_back(3);
    tha_list.push_back(4);
    tha_list.push_back(5);
    //[...]
    tha_list.push_back(6);
    std::list<int>::iterator itt = tha_list.begin();
    std::list<int>::iterator itte = tha_list.end();
    ++itt;
    --itt;
    while (itt != itte)
    {
        std::cout << *itt << std::endl;
        ++itt;
    }
    std::list<int> ss(tha_list);
    return 0;
}