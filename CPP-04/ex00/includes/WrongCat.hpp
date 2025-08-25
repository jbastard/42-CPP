#pragma once

#include "WrongAnimal.hpp"
#include "Colors.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {

private:

public:

	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();

	WrongCat	&operator=(const WrongCat &src);

	void		makeSound() const;
};

std::ostream &operator<<(std::ostream &out, const WrongCat &src);