#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"
#include "includes/Colors.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	std::cout << j->getType() << "      : ";
	j->makeSound();
	const Animal* i = new Cat();
	std::cout << i->getType() << "      : ";
	i->makeSound();

	meta->makeSound();

	const WrongAnimal* not_the_one = new WrongCat();
	std::cout << not_the_one->getType() << " : ";
	not_the_one->makeSound();
	return 0;
}