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
	Contact 	create(int nb_of_contact);
};