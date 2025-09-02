/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:59:44 by guphilip          #+#    #+#             */
/*   Updated: 2025/07/10 16:58:39 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>

class RPN{
	private:
		std::stack<int> _value;
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);

	public:
		RPN();
		~RPN();
		void calculate(std::string args);
		void handleAdd();
		void handleTime();
		void handleDivide();
		void handleSub();
		void validateDigit(const std::string& digit);

	class NotEnoughValueException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidInputException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class DividedByZeroException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
