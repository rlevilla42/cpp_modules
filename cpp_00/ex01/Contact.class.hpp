#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP
#include "header.hpp"
class	Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		int			index;
		int			nbMaxContact;
		void		create(void);
};

#endif