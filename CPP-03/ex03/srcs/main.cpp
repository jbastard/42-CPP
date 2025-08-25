#include "../includes/DiamondTrap.hpp"

void sep(std::string title) {
    std::cout << std::endl
        << "================"
        << title << "================"
        << std::endl;
}

int main() {
    sep(" BASIC DIAMOND-TRAP ");
    DiamondTrap d1("Toto");
    d1.whoAmI();
    d1.attack("his bro");
    d1.beRepaired(10);
    d1.takeDamage(42);
    std::cout << d1 << std::endl;

    sep(" DIAMOND-TRAP COPY ");
    DiamondTrap d2(d1);
    d2.whoAmI();
    d2.attack("copied target");
    std::cout << d2 << std::endl;

    sep(" DIAMOND-TRAP ASSIGNMENT OP ");
    DiamondTrap d3("Nobody");
    d3 = d2;
    d3.whoAmI();
    d3.attack("assigned target");
    std::cout << d3 << std::endl;

    sep(" DESTRUCTORS ");
    return 0;
}