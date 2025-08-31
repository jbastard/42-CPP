#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Colors.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(0));

	Bureaucrat signer145("Signer145", 145);  // OK pour signer Shrubbery (145)
	Bureaucrat exec150("Exec150", 150);      // trop faible pour exécuter Shrubbery (137)
	Bureaucrat exec137("Exec137", 137);      // juste assez pour exécuter Shrubbery (137)

	Bureaucrat signer72("Signer72", 72);     // OK pour signer Robotomy (72)
	Bureaucrat exec70("Exec70", 70);         // trop faible pour exécuter Robotomy (45)
	Bureaucrat exec45("Exec45", 45);         // juste assez pour exécuter Robotomy (45)

	Bureaucrat signer25("Signer25", 25);     // OK pour signer Pardon (25)
	Bureaucrat exec10("Exec10", 10);         // trop faible pour exécuter Pardon (5)
	Bureaucrat exec5("Exec5", 5);            // juste assez pour exécuter Pardon (5)

	// --- Forms concrets (ex02) ---
	ShrubberyCreationForm shrub("home");           // sign 145, exec 137
	RobotomyRequestForm    robo("Bender");         // sign 72,  exec 45
	PresidentialPardonForm pardon("Arthur Dent");  // sign 25,  exec 5

	std::cout << shrub << "\n" << robo << "\n" << pardon << "\n";

	// 1) Erreur exécution sans signature (scope ex02)
	std::cout << "\n=== Exécution sans signature (doit échouer) ===\n";
	exec137.executeForm(shrub);

	// 2) SHRUBBERY: signer puis exécuter (échec puis succès)
	std::cout << "\n=== ShrubberyCreationForm ===\n";
	signer145.signForm(shrub);      // OK (145)
	exec150.executeForm(shrub);     // échec (150 > 137)
	exec137.executeForm(shrub);     // succès -> crée "home_shrubbery"

	// 3) ROBOTOMY: signer puis exécuter (échec puis quelques essais réussis/ratés)
	std::cout << "\n=== RobotomyRequestForm ===\n";
	signer72.signForm(robo);        // OK (72)
	exec70.executeForm(robo);       // échec (70 > 45)
	for (int i = 0; i < 3; ++i)     // montrer la proba 50%
		exec45.executeForm(robo);   // succès/échec aléatoire

	// 4) PARDON: signer puis exécuter (échec puis succès)
	std::cout << "\n=== PresidentialPardonForm ===\n";
	signer25.signForm(pardon);      // OK (25)
	exec10.executeForm(pardon);     // échec (10 > 5)
	exec5.executeForm(pardon);      // succès (pardon affiché)

	std::cout << "\n=== Appel direct execute() enveloppé d'un try/catch ===\n";
	try {
		RobotomyRequestForm r2("Marvin");
		signer72.signForm(r2);
		r2.execute(exec45); // OK (signé, exec45 a le grade requis)
	} catch (std::exception &e) {
		std::cerr << "Exception directe: " << e.what() << "\n";
	}

	return 0;
}