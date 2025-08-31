#include "../includes/Iter.hpp"

void increment(int& i)
{
	i++;
}

int main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	std::cout << "Original Int Array: ";
	iter(tab, 5, print<int>);
	std::cout << std::endl;

	iter(tab, 5, increment);
	std::cout << "Array after increment: ";
	iter(tab, 5, print<int>);
	std::cout << std::endl;

	std::string strings[] = {"Hello World ", "Please save me from CPP ", "I can't stand it no more."};
	std::cout << "String Array: ";
	iter(strings, 3, print<std::string>);
	std::cout << std::endl;

	const float floats[] = {42.42f, 1.1f, 13.13f};
	std::cout << "Float Array: ";
	iter(floats, 3, print<float>);
	std::cout << std::endl;
}
