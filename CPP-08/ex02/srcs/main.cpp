#include "../includes/MutantStack.hpp"

int main(void)
{

	/******************************************************************************
	* 						MUTANT STACK IMPLEMENTATION							  *
	*******************************************************************************/

	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	std::cout << "=========== FIRST ELEMENT IN STACK =============" << std::endl;
	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "================== STACK SIZE ==================" << std::endl;
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);

	std::cout << "=========== STACK SIZE AFTER PUSHES ============" << std::endl;
	std::cout << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "============ ITERATE THROUGH STACK =============" << std::endl;

	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << "END." << std::endl;
	
	/******************************************************************************
	* 				LST IMPLEMENTATION TO COMPARE OUTPUTS						  *
	*******************************************************************************/

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	std::cout << "=========== FIRST ELEMENT IN LIST =============" << std::endl;
	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "=================== LIST SIZE ==================" << std::endl;
	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);

	std::cout << "=========== LIST SIZE AFTER PUSHES ============" << std::endl;
	std::cout << lst.size() << std::endl;

	std::cout << "============ ITERATE THROUGH LIST ==============" << std::endl;

	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << ", ";

	std::cout << "END." << std::endl;

	return 0;

}
