#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	const int N = 6;
	AAnimal* herd[N];

	sep(BRIGHT_WHITE "Creating herd" RESET, 50);
	for (int i = 0; i < N; ++i) {
		if (i < N / 2) herd[i] = new Dog();
		else           herd[i] = new Cat();
	}

	sep(BRIGHT_WHITE "Deep copy test (Dog)" RESET,50);
	Dog* d1 = new Dog();
	d1->setIdea(0, "Chase the ball");
	Dog* d2 = new Dog(*d1);
	std::cout << "d1 idea[0] = " << d1->getIdea(0) << std::endl;
	std::cout << "d2 idea[0] = " << d2->getIdea(0) << std::endl;
	d1->setIdea(0, "Guard the house");
	std::cout << "After change:" << std::endl;
	std::cout << "d1 idea[0] = " << d1->getIdea(0) << std::endl;
	std::cout << "d2 idea[0] = " << d2->getIdea(0) << std::endl;

	sep(BRIGHT_WHITE "Deep copy test (Cat via assignment)" RESET,50);
	Cat c1;
	c1.setIdea(1, "Nap on keyboard");
	Cat c2;
	c2 = c1;
	std::cout << "c1 idea[1] = " << c1.getIdea(1) << std::endl;
	std::cout << "c2 idea[1] = " << c2.getIdea(1) << std::endl;
	delete d1;
	delete d2;

	sep(BRIGHT_WHITE "Deleting herd" RESET, 50);
	for (int i = 0; i < N; ++i) delete herd[i];

	return 0;
}
