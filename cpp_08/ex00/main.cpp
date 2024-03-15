#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>
int main(void)
{
    std::list<int>      a_list;
    std::deque<int>     a_deque;
    std::vector<int>    a_vector;

    for (size_t i = 0; i <= 42; i++)
    {
        a_list.push_back(i); a_deque.push_back(i); a_vector.push_back(i);
    }
    try{
        std::cout << "a_list easy: " << *easyfind(a_list, 42) << std::endl;
    }catch(std::exception &e){std::cout << e.what() << std::endl;}
    try{
        std::cout << "a_deque easy: " << *easyfind(a_deque, -1) << std::endl;
    }catch(std::exception &e){std::cout << e.what() << std::endl;}
    try{
        std::cout << "a_vector easy: " << *easyfind(a_vector, 43) << std::endl;
    }catch(std::exception &e){std::cout << e.what() << std::endl;}

}