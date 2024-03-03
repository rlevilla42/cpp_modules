#include "Brain.hpp"

/************** constructor *************/

Brain::Brain(void) {
    std::cout << "Brain constructor by default" << std::endl;
    return;
};

Brain::Brain(Brain const &src) {
    std::cout << "Brain constructor by copy" << std::endl;
    *this = src;
    return;
};

Brain::~Brain(void) {
    std::cout << "Brain DEStructor called" << std::endl;
    return;
};

Brain &Brain::operator=(Brain const &rhs) {
    std::cout << "Brain assignment by copy" << std::endl;
    if (this != &rhs)
    {
        this->_number_of_ideas = rhs._number_of_ideas;
        for (int i = 0; i < rhs._number_of_ideas; i++)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return(*this);
};

/************** function *************/

std::string	Brain::getIdea(int	i) const
{
	return this->ideas[i];
}

void	Brain::addIdea(std::string idea)
{
	this->ideas[this->_number_of_ideas] = idea;
	this->_number_of_ideas++;
}

int		Brain::howManyIdeas(void) const
{
	return Brain::_number_of_ideas;
};
//std::ostream &operator<<(std::ostream &o, Brain const &i) {o << i.get();return o;};