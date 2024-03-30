#ifndef		RPN_HPP
# define	RPN_HPP
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <exception>

class	RPN
{

public:
    static void calc(char* c_str);

private:
	RPN(RPN const & src);
	RPN&	operator=(RPN const& rhs);

	RPN(void);
	~RPN(void);

};

#endif
