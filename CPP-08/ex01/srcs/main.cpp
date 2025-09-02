#include "../includes/Span.hpp"

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "=== 1st test ===" << std::endl;
	std::cout << "Between 9 and 11" << std::endl;
	std::cout << sp.shortestSpan() << std::endl << std::endl;
	std::cout << "Between 3 and 17" << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::vector<int> range;
	for (int i = 0; i < 10000; i++)	{
		range.push_back(i);
	}

	std::cout << std::endl << "=== 2nd test ===" << std::endl;
	try	{
		Span sp = Span(10001);
		sp.addNumbers(range.begin(), range.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e)	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << "== Exceptions ==" << std::endl;
	try	{
		Span sp = Span(1);

		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e)	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try	{
		sp.addNumber(1);
	} catch (std::exception &e)	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
