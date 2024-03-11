#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
Base*   generate(void)
{
    return clock() % 3 == 0 ? dynamic_cast<Base*>(new A) : clock() % 2 ? dynamic_cast<Base*>(new B) : dynamic_cast<Base*>(new C);
}
void    identify(Base& p)
{
    try{
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return (void) a;
    }catch (std::exception& e){}
    try{
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return (void) b;
    }catch (std::exception& e){}
    try{
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return (void) c;
    }catch (std::exception& e){}
}
void    identify(Base* p)
{
    try
    {
        if (dynamic_cast<A*>(p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(p))
            std::cout << "C" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
int main(void)
{
    Base* wapiti = generate();
    identify(wapiti);
    identify(*wapiti);
    delete wapiti;
    return 0;
}
