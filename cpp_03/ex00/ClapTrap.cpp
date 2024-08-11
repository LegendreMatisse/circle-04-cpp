/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:50:02 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/10 21:50:02 by mlegendr         ###   ########.fr       */
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

void ClapTrap::determineMessage(std::string const &message, std::string const &target, int amount)
{
	if (message == "attack")
		std::cout << "ClapTrap " <<this->getName() << " attacks " << target << " causing, " <<this->getAttackDamage() << " points of damage!" << std::endl;
	else if (message == "takeDamage")
		std::cout << "ClapTrap " <<this->getName() << " takes " << amount << " points of damage!" << std::endl;
	else if (message == "beRepaired")
		std::cout << "ClapTrap " <<this->getName() << " is being repaired for " << amount << " points!" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (ClapTrap::getEnergyPoints() < 1)
	{
		std::cout << "ClapTrap " <<this->getName() << " is too tired to attack!" << std::endl;
		return ;
	}
	else if (ClapTrap::getHitPoints() < 1)
	{
		std::cout << "ClapTrap " <<this->getName() << " is dead!" << std::endl;
		return ;
	}
	determineMessage("attack", target, 0);
	ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	determineMessage("takeDamage", "himself", amount);
	ClapTrap::setHitPoints(ClapTrap::getHitPoints() - amount);
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (ClapTrap::getEnergyPoints() < 1)
	{
		std::cout << "ClapTrap " <<this->getName() << " is too tired to repair itself!" << std::endl;
		return ;
	}
	else if (ClapTrap::getHitPoints() < 1)
	{
		std::cout << "ClapTrap " <<this->getName() << " is dead!" << std::endl;
		return ;
	}
	determineMessage("beRepaired", "himself", amount);
	ClapTrap::setHitPoints(ClapTrap::getHitPoints() + amount);
	ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
	return ;
}

//debug functions
void ClapTrap::printStats(void)
{
	std::cout << "Name: " <<this->getName() << std::endl;
	std::cout << "Hitpoints: " <<this->getHitPoints() << std::endl;
	std::cout << "Energy Points: " <<this->getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " <<this->getAttackDamage() << std::endl;
	return ;
}