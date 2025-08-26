#pragma once

#include <iostream>

class Brain {

private:
	std::string _ideas[100];

public:

	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &src);

	const std::string& getIdea(int i) const;
	void setIdea(int i, const std::string& s);

};

std::ostream &operator<<(std::ostream &out, const Brain &src);
