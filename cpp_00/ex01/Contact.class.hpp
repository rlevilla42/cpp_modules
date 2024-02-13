#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP
#include "header.hpp"
class	Contact {
  private:
	std::string _name;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
  public:
	int			_index;
	int			_nbMaxContact;
	void		create(void);
};

#endif