#include "../includes/easyFind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> array;
	int j = 0;

	for (int i = 0; i < 10; i++)
		array.push_back(j += 3);
	try
	{
		easyFind(array, 9);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
