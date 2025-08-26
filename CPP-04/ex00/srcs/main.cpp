#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Colors.hpp"


int main()
{
	const Animal* i = new Cat();
	std::cout << i->getType() << "      : ";
	i->makeSound();
	const Animal* j = new Dog();
	std::cout << j->getType() << "      : ";
	j->makeSound();

	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " : ";
	k->makeSound();

	delete i;
	delete j;
	delete k;

	return 0;
}