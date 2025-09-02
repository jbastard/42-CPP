#include "../includes/easyFind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::list<int> array;
//	std::vector<int> array;
	int j = 0;

	for (int i = 0; i < 10; i++)
		array.push_back(j += 2);

	try	{
		easyFind(array, 9);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try	{
		easyFind(array, 8);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
