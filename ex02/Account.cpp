/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:48:38 by jfernand          #+#    #+#             */
/*   Updated: 2026/01/12 19:58:26 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

void	Account::makeDeposit(int deposit)
{
	int	previous = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << previous << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int previous = _amount;
	if (previous < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
                  << "p_amount:" << previous << ";"
                  << "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << previous << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayAccountsInfos(void)
{
	int	nb_acc = getNbAccounts();
	int total = getTotalAmount();
	int	deposits = getNbDeposits();
	int	withdrawals = getNbWithdrawals();

	Account::_displayTimestamp();
	std::cout << "accounts:" << nb_acc << ";"
		<< "total:" << total << ";"
		<< "deposits:" << deposits << ";"
		<< "withdrawals:" << withdrawals << std::endl;
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(nullptr);
    std::tm *tm = std::localtime(&t);

    std::cout << "["
              << std::setfill('0') << std::setw(4) << (tm->tm_year + 1900)
              << std::setw(2) << (tm->tm_mon + 1)
              << std::setw(2) << tm->tm_mday << "_"
              << std::setw(2) << tm->tm_hour
              << std::setw(2) << tm->tm_min
              << std::setw(2) << tm->tm_sec
              << "] ";
}
