#include "Dog.hpp"
#include "Cat.hpp"

void	subject_tests(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}
void	loop_test(void)
{
	std::string	u_input;
	std::cout << "Wanna do the loop thing? y/n :" << std::flush;
	std::cin >> u_input;
	if (u_input == "n")
		return ;

	Animal*	Animal_array[100];
	for (int i = 0; i < 50; i++)
		Animal_array[i] = new Dog();
	for (int i = 50; i < 100; i++)
		Animal_array[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete Animal_array[i];
}
int	main(void)
{
	/*std::cout << "\t----Subject Tests----" << std::endl;
	subject_tests();
	std::cout << "\n\t----Loop test----" << std::endl;
	loop_test();
	std::cout << "\n\t----Some More Tests----" << std::endl;

	Dog	doggo = Dog();

	doggo.addIdea("Bones");
	doggo.addIdea("Lasagna");
	doggo.printIdeas();

	Dog	doggo2 = Dog(doggo);
	doggo2.addIdea("Kartoffel");
	doggo.printIdeas();
	doggo2.printIdeas();
	std::cout << &doggo << "|" << &doggo2 << std::endl;*/
	Cat	kitty = Cat();

	kitty.addIdea("Fish");
	kitty.addIdea("Milk");
	kitty.printIdeas();
    //exit(1);

	Cat	kitty2 = Cat(kitty);
	kitty2.addIdea("Kartoffel");
	kitty.printIdeas();
	kitty2.printIdeas();
	std::cout << &kitty << "|" << &kitty2 << std::endl;
}
