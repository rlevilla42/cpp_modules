#include "WrongCat.hpp"

/************** constructor *************/

WrongCat::WrongCat(void) {return;};

WrongCat::WrongCat(WrongCat const &src) {*this = src; return;};

WrongCat::~WrongCat(void) {return;};

WrongCat &WrongCat::operator=(WrongCat const &rhs) {return(*this);};

/************** function *************/

std::ostream &operator<<(std::ostream &o, WrongCat const &i) {return o;};
std::string WrongCat::getType(void) const {return this->type;};
void WrongCat::makeSound(void) const {std::cout << "WRONG MIAOU ??" << std::endl;return;};