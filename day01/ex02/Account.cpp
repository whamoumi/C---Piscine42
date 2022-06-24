#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>
#include <string>
#include <time.h> 
#include <stdio.h>

int Account::_nbAccounts = 1;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string	give_time(void)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [20];

  	time (&rawtime);
  	timeinfo = localtime (&rawtime);
	strftime (buffer,20,"[%G%m%d_%H%M%S]",timeinfo);
	return (buffer);
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << give_time() << " index:" << this->_accountIndex <<";amount:"<< initial_deposit <<";created"<< std::endl;
	this->_nbAccounts++;
	
}

Account::~Account(void)
{
	std::cout << give_time() << " index:" << this->_accountIndex <<";amount:"<< this->_amount <<";closed"<< std::endl;
}
void Account::displayStatus( void ) const
{
	std::cout << give_time() << " index:" << this->_accountIndex << ";amount:" << this->_amount <<";deposits:"<< this->_nbDeposits <<";withdrawals:" << this->_nbWithdrawals << std::endl;
}
int	Account::getNbAccounts( void )
{
	return(_nbAccounts - 1);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << give_time() << " accounts:"<< getNbAccounts() << ";total:"<< getTotalAmount() <<";deposits:"<< getNbDeposits() <<";withdrawals:"<< getNbWithdrawals() <<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int old_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits = 1;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << give_time() << " index:" << this->_accountIndex << ";p_amount:" << old_amount << ";deposit:" << deposit <<";amount:" << this->_amount <<";nb_deposits:"<< this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int old_amount = this->_amount;
	this->_amount -= withdrawal;
	if (this->_amount >= 0)
	{
		_totalNbWithdrawals++;
		this->_nbWithdrawals = 1;
		_totalAmount -= withdrawal;
		std::cout << give_time() << " index:" << this->_accountIndex << ";p_amount:" << old_amount << ";withdrawal:" << withdrawal <<";amount:" << this->_amount <<";nb_withdrawals:"<< this->_nbWithdrawals << std::endl;
	}
	else
	{
		this->_amount = old_amount;
		std::cout << give_time() << " index:" << this->_accountIndex << ";p_amount:" << old_amount << ";withdrawal:refused"<< std::endl;
	}
	return(1);
}