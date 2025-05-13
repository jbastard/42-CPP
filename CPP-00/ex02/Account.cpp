
#include "Account.hpp"
#include <ostream>
#include <iostream>

int	Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;

static int accIndex = 0;

void Account::_displayTimestamp() {
		time_t		now;
		struct tm	*tm_info;
		char		buffer[20];

		time(&now);
		tm_info = localtime(&now);
		strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm_info);
		std::cout << "[" << buffer << "]";
}

Account::Account(int initial_deposit) {

	this->_amount = initial_deposit;
	this->_accountIndex = accIndex++;
	this->_totalAmount+= initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";created"
		<< std::endl;
}

Account::~Account() {
	this->_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";closed"
		<< std::endl;
}

int Account::getNbAccounts() {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
    return (Account::_totalAmount);
}

int Account::getNbDeposits() {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout
		<< " accounts:" << accIndex
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
    return;
}

void	Account::makeDeposit( int deposit ) {
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout
		<< ";amount:" << _amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
	_totalAmount += deposit;
    return;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (this->_amount >= withdrawal) {
		_totalNbWithdrawals += 1;
		this->_nbWithdrawals += 1;
	}
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:";
	if (this->_amount < withdrawal)
		return (std::cout << "refused" << std::endl, false);
	else
		std::cout << withdrawal;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const{
    return (this->_amount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<<  std::endl;
    return;
}
