#include "../includes/Base.hpp"

int main(void)
{
	srand(std::time(NULL));

	std::cout << "Generating A, B, C" << std::endl << std::endl;

	Base	*tab[3];
	for (int i = 0; i < 3; i++)
		tab[i] = generate();

	std::cout << "Pointers identification" << std::endl;


	for (int i = 0; i < 3; i++)
		identify(tab[i]);

	std::cout << std::endl << "References identification" << std::endl;

	for (int i = 0; i < 3; i++)
		identify(*tab[i]);

	for (int i = 0; i < 3; i++)
		delete tab[i];
}
