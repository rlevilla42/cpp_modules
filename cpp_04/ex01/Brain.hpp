#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
public:
    Brain(void);
    Brain(Brain const &src);
    ~Brain(void);
    std::string getIdea(int	i) const;
    void addIdea(std::string idea);
    int howManyIdeas(void) const;

    Brain &operator=(Brain const &rhs);
protected:
    std::string ideas[100];
    int         _number_of_ideas;
};

//std::ostream &operator<<(std::ostream &o, Brain const &i);
#endif