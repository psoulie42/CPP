#include "Account.hpp"

#include <iostream>
#include <string>
#include <ctime>

// CLASS CONSTRUCT, DESTRUCT & INIT
Account::Account(int initial_deposit): _accountIndex(_nbAccounts - 1), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account(){}


// GETTERS
int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	std::cout << "coucou" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		return false;
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbDeposits++;
	_totalNbDeposits++;
	return true;
}

int Account::checkAmount() const
{
	return this->_amount;
}

void Account::_displayTimestamp()
{
	time_t timestamp = time(&timestamp);
	std::cout << timestamp << std::endl;
}
