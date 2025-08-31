#include "../includes/Bureaucrat.hpp"

int main() {
	try {
		// Bureaucrats
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		// Forms
		Form contract("Contract", 50, 30);
		Form topSecret("TopSecret", 1, 1);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
		std::cout << contract << std::endl;
		std::cout << topSecret << std::endl;

		std::cout << "\n=== Signing tests ===" << std::endl;

		// Too weak to sign
		intern.signForm(contract);

		// Strong enough to sign
		boss.signForm(contract);

		// Boss signing the hardest form
		boss.signForm(topSecret);

		// Already signed test
		boss.signForm(contract);

	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Invalid form test ===" << std::endl;
	try {
		Form invalid("Invalid", 0, 200); // should throw
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}