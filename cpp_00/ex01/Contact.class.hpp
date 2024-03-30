#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP
#include "header.hpp"
class	Contact {
	public:
		int			index;
		int			nbMaxContact;
		void		create(void);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif