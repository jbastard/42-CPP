#pragma once
#include "Colors.hpp"

#include <iostream>

class AAnimal {

protected:
	std::string _type;

	AAnimal();
	AAnimal(const AAnimal &copy);
	AAnimal			&operator=(const AAnimal &src);
public:

	virtual ~AAnimal() = 0;

	const			std::string& getType() const;

	virtual void	makeSound() const = 0 ;
};

std::ostream &operator<<(std::ostream &out, const AAnimal &src);
