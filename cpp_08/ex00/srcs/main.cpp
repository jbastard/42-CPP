#include "../includes/easyFind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> array;

	for (int i = 0; i < 10; i++)
		array.push_back(i * 2);
	try
	{
		easyFind(array, 8);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
