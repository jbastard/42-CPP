#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {
	sep("Basic test: construction and display", 60);
	try {
		Bureaucrat alice("Alice", 5);
		Bureaucrat bob("Bob", 100);
		Form       fA("FormA", 50, 25);

		std::cout << alice << std::endl;
		std::cout << bob   << std::endl;
		std::cout << fA    << std::endl;

		std::cout << std::endl;
		sep("Signing attempt by Bob (should fail)", 60);
		bob.signForm(fA);
		std::cout << fA << std::endl;

		std::cout << std::endl;
		sep("Signing attempt by Alice (should succeed)", 60);
		alice.signForm(fA);
		std::cout << fA << std::endl;

		std::cout << std::endl;
		sep("Signing with grade equal to required (should succeed)", 60);
		Bureaucrat charlie("Charlie", 50);
		Form       fB("FormB", 50, 100);
		std::cout << charlie << std::endl;
		std::cout << fB << std::endl;
		charlie.signForm(fB);
		std::cout << fB << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	sep("Form grade exceptions", 60);
	try {
		std::cout << "Constructing with TOO HIGH signing grade (0)" << std::endl;
		Form badHigh("BadHigh", 0, 10);
		std::cout << badHigh << std::endl; // should not print
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Constructing with TOO LOW execution grade (151)" << std::endl;
		Form badLow("BadLow", 10, 151);
		std::cout << badLow << std::endl; // should not print
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	sep("Valid edges (1 and 150)", 60);
	try {
		Form edge1("EdgeTop", 1, 1);
		Form edge2("EdgeBottom", 150, 150);
		std::cout << edge1 << std::endl;
		std::cout << edge2 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
	return 0;
}