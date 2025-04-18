
#include "Account.hpp"

Account::Account(int initial_deposit) {
    (void)initial_deposit;
}

Account::~Account() {}

int Account::getNbAccounts() {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
    return (Account::_totalAmount);
}

int Account::getNbDeposits() {
    return (0);
}

int Account::getNbWithdrawals() {
    return (0);
}

void Account::displayAccountsInfos() {
    return;
}

void	Account::makeDeposit( int deposit ) {
    return;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    return (false);
}

int		Account::checkAmount( void ) const{
    return (0);
}

void	Account::displayStatus( void ) const{
    return;
}
