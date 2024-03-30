#include "RPN.hpp"
bool    is_op(char const& c)
{
    return c == '+' || c == '-' || c == '/' || c == '*';
}
int     operate(std::stack<int>& stack, char const c)
{
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '/')
        return a / b;
    else if (c == '*')
        return a * b;
    throw(std::exception());
}
//--------------Functions----------------//
void    RPN::calc(char *c_str)
{
    try
    {
        std::string str = (c_str);
        std::stack<int> stack;
        std::string::iterator it = str.begin();
        if (*it == ' ')
            it++;
        for (; it < str.end(); it++)
        {
            if (is_op(*it) && stack.size() > 1)
                stack.push(operate(stack, *it));
            else if (isdigit(*it))
                stack.push(*it - 48);
            else
                throw(std::exception());
            if (++it != str.end() && *it != ' ')
                throw(std::exception());
        }
        if (stack.size() == 1)
            std::cout << stack.top() << std::endl;
        else
            throw(std::exception());
    }
    catch(std::exception& e)
    {
        std::cout << "Input probably sucks" << std::endl;
    }
}
//--------------Operators----------------//
RPN&	RPN::operator=(RPN const&  rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}
//--------------Constructors------------//
RPN::RPN(RPN const &src)
{
	*this = src;
	return ;
}

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}
//--------------Non-Member--------------//
