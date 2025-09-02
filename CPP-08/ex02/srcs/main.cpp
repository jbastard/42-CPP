#include <iostream>
#include <list>
#include <stack>
#include "../includes/MutantStack.hpp"

static void print_sep(const char* title) {
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main() {
	print_sep("MutantStack");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top:  " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "(test ++it / --it) ";
	++it;
	--it;

	std::cout << "contenu (base -> top): ";
	for (; it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Copie dans un std::stack
	std::stack<int> s(mstack);
	std::cout << "copie dans std::stack: top = " << s.top() << std::endl;

	print_sep("std::list");

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "back: " << lst.back() << std::endl;

	lst.pop_back();
	std::cout << "size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "contenu (debut -> fin): ";
	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit) {
		std::cout << *lit << " ";
	}
	std::cout << std::endl;

	print_sep("END");
	return 0;
}