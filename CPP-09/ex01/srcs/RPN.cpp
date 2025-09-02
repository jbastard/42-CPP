/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:59:46 by guphilip          #+#    #+#             */
/*   Updated: 2025/07/10 16:58:22 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	// std::cout << "RPN default constructor has been called" << std::endl;
}

// not used
RPN::RPN(const RPN& copy)
{
	// std::cout << "RPN copy constructor has been called" << std::endl;
	(void)copy;
}
// not used
RPN& RPN::operator=(const RPN& other)
{
	// std::cout << "RPN copy assignement has been called" << std::endl;
	(void)other;
	return *this;
}

RPN::~RPN()
{
	// std::cout << "RPN destructor has been called" << std::endl;
}

const char* RPN::NotEnoughValueException::what() const throw()
{
	return "Error: Not enough value in stack.\n";
}

const char* RPN::InvalidInputException::what() const throw()
{
	return "Error: Invalid input.\n";
}

const char* RPN::DividedByZeroException::what() const throw()
{
	return "Error: Trying to divide by zero, (WTF?).\n";
}

void RPN::validateDigit(const std::string& digit)
{
	if (digit.length() != 1 || !isdigit(digit[0]))
		throw InvalidInputException();
	_value.push(static_cast<int>(digit[0] - '0'));
}

void RPN::calculate(std::string args)
{
	std::istringstream	iss(args);
	std::string 		token;

	while (iss >> token) // process mot par mot
	{
		if (token == "+")
			handleAdd();
		else if (token == "-")
			handleSub();
		else if (token == "*")
			handleTime();
		else if (token == "/")
			handleDivide();
		else
			validateDigit(token);
	}

	if (_value.size() != 1)
		throw InvalidInputException();

	std::cout << _value.top() << std::endl;
}

void RPN::handleAdd()
{
	if (_value.size() < 2)
		throw NotEnoughValueException();

	int b = _value.top();
	_value.pop();

	int a = _value.top();
	_value.pop();

	_value.push(a + b);
}

void RPN::handleSub()
{
	if (_value.size() < 2)
		throw NotEnoughValueException();

	int b = _value.top();
	_value.pop();

	int a = _value.top();
	_value.pop();

	_value.push(a - b);
}

void RPN::handleTime()
{
	if (_value.size() < 2)
		throw NotEnoughValueException();

	int b = _value.top();
	_value.pop();

	int a = _value.top();
	_value.pop();

	_value.push(a * b);
}

void RPN::handleDivide()
{
	if (_value.size() < 2)
		throw NotEnoughValueException();

	int b = _value.top();
	_value.pop();

	if (b == 0)
		throw DividedByZeroException();

	int a = _value.top();
	_value.pop();

	_value.push(a / b);
}
