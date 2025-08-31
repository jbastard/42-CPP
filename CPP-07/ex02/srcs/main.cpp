#include "../includes/Array.hpp"

int main(void)
{
	try
	{
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 2;

		Array<int> b = a;
		b[0] = 42;

		std::cout << "========================================" << std::endl;
		std::cout << "============ INT ARRAY DEMO ============" << std::endl;
		std::cout << "========================================" << std::endl;

		std::cout << "Array a: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << "Array b: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;

		std::cout << "========================================" << std::endl;
		std::cout << "========== OUT OF BOUNDS DEMO ==========" << std::endl;
		std::cout << "========================================" << std::endl;

		std::cout << "Accessing out of bounds index: ";
		std::cout << a[10] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Array<std::string> a(3);

		a[0] = "Hello";
		a[1] = "World";
		a[2] = "Please end C++";

		std::cout << "========================================" << std::endl;
		std::cout << "========== STRING ARRAY DEMO ===========" << std::endl;
		std::cout << "========================================" << std::endl;

		std::cout << "std::string Array: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "'" << a[i] << "'" << ", " << " ";
		std::cout << std::endl;

		std::cout << "std::string Array size: " << a.size() << std::endl;
		std::cout << "========================================" << std::endl;
		std::cout << "========== OUT OF BOUNDS DEMO ==========" << std::endl;
		std::cout << "========================================" << std::endl;

		std::cout << "Accessing out of bounds index: ";
		std::cout << a[4] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "========================================" << std::endl;
		std::cout << "=========== EMPTY ARRAY DEMO ===========" << std::endl;
		std::cout << "========================================" << std::endl;

		std::cout << "Creating empty array 'f'" << std::endl;

		Array<float> f;

		if (f.size() == 0)
			std::cout << "Array is empty and has been successfully created" << std::endl;
		else
			std::cout << "Empty array f has been created." << std::endl;

		std::cout << "Accessing index 0 of an empty array: ";
		std::cout << f[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
