#include "../includes/Span.hpp"

Span::Span()
{
	// std::cout << "Span default constructor has been called" << std::endl;
}

Span::Span(unsigned int N){
	this->_N = N;
	// std::cout << "Span parametized constructor has been called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_intStock = other._intStock;
	}
	// std::cout << "Span copy assignment operator has been called" << std::endl;
	return (*this);
}

Span::Span(const Span& copy)
{
	this->_N = copy._N;
	this->_intStock = copy._intStock;
}

Span::~Span()
{
	// std::cout << "Span destructor has been called" << std::endl;
}

const char* Span::SpanOverflowException::what() const throw()
{
	return "Cannot add any more numbers, Span will overflow";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to realise a span";
}

void Span::addNumber(int value)
{
	if (_intStock.size() >= _N)
		throw Span::SpanOverflowException();
	_intStock.push_back(value);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (_intStock.size() + std::distance(begin, end) > _N)
		throw Span::SpanOverflowException();
	_intStock.insert(_intStock.end(), begin, end);
}

int Span::shortestSpan() const
{
	if (_intStock.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> tmp = _intStock;
	std::sort(tmp.begin(), tmp.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_intStock.size() < 2)
		throw Span::NotEnoughNumbersException();
	int min = *std::min_element(_intStock.begin(), _intStock.end());
	int max = *std::max_element(_intStock.begin(), _intStock.end());
	return max - min;
}
