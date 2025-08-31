#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"

#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(0));

	Intern intern;
	Bureaucrat boss("Boss", 1);

	const std::string formNames[]  = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};
	const std::string targets[]    = { "home", "Bender", "Arthur Dent" };

	std::cout << "=== Creation via Intern::makeForm ===\n";
	for (int i = 0; i < 3; ++i) {
		AForm* f = 0;
		try {
			f = intern.makeForm(formNames[i], targets[i]); // doit aussi afficher "Intern creates <form>"
		} catch (std::exception &e) {
			std::cerr << "makeForm threw: " << e.what() << "\n";
		}

		if (!f) {
			std::cerr << "Creation failed for \"" << formNames[i] << "\"\n";
			continue;
		}

		std::cout << *f << "\n";

		boss.signForm(*f);
		boss.executeForm(*f);

		delete f;
	}

	std::cout << "\n=== Nom inconnu: doit afficher une erreur explicite ===\n";
	AForm* unknown = 0;
	try {
		unknown = intern.makeForm("top secret clearance", "nobody");
		// Selon l’implémentation, unknown peut être NULL et/ou une exception peut être levée.
	} catch (std::exception &e) {
		std::cerr << "Unknown makeForm threw: " << e.what() << "\n";
	}
	if (unknown) {
		// Si votre implémentation retourne quand même un pointeur, on évite les fuites.
		delete unknown;
	}

	return 0;
}