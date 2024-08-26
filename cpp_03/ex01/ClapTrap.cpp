/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:29:10 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/19 18:31:14 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copyCo)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copyCo;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copyOp)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &copyOp)
	{
		this->_name = copyOp._name;
		this->_hitPoints = copyOp._hitPoints;
		this->_energyPoints = copyOp._energyPoints;
		this->_attackDamage = copyOp._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

void ClapTrap::determineMessage(std::string const &message, int amount)
{
	if (message == "takeDamage")
		std::cout << this->getName() << " takes " << amount << " points of damage!" << std::endl;
	else if (message == "beRepaired")
		std::cout << this->getName() << " is being repaired for " << amount << " points!" << std::endl;
	else if (message == "tiredAttack")
		std::cout << this->getName() << " is too tired to attack!" << std::endl;
	else if (message == "tiredRepair")
		std::cout << this->getName() << " is too tired to repair itself!" << std::endl;
	else if (message == "dead")
		std::cout << this->getName() << " is dead!" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->getEnergyPoints() < 1)
	{
		this->determineMessage("tiredAttack", 0);
		return ;
	}
	if (this->getHitPoints() < 1)
	{
		this->determineMessage("dead", 0);
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (static_cast<unsigned int>(this->getHitPoints()) <= amount)
	{
		this->determineMessage("dead", 0);
		this->setHitPoints(0);
		return ;
	}
	determineMessage("takeDamage", amount);
	this->setHitPoints(this->getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() < 1)
	{
		this->determineMessage("dead", 0);
		return ;
	}
	if (this->getEnergyPoints() < 1)
	{
		this->determineMessage("tiredRepair", 0);
		return ;
	}
	determineMessage("beRepaired", amount);
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	return ;
}

//debug functions
void ClapTrap::printStats(void)
{
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Hitpoints: " << this->getHitPoints() << std::endl;
	std::cout << "Energy Points: " << this->getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << this->getAttackDamage() << std::endl;
	return ;
}