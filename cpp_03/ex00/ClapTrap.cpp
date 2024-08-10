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

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name("default")
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name)
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

void ClapTrap::determineMessage(std::string const &message, int const &amount, std::string const &name, std::string const &target)
{
	if (message == "attack")
		std::cout << "ClapTrap " << name << "attacks " << target << "causing, " << amount << "points of damage!" << std::endl;
	else if (message == "takeDamage")
		std::cout << "ClapTrap " << name << "takes " << amount << "points of damage!" << std::endl;
	else if (message == "beRepaired")
		std::cout << "ClapTrap " << name << "is being repaired for " << amount << "points!" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	determineMessage("attack", this->_attackDamage, this->_name, target);
	ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
	return ;
	/*determineMessage("attack", this->_attackDamage, this->_name, target);
	int temp = ClapTrap::getEnergyPoints();
	temp -= 1;
	ClapTrap::setEnergyPoints(temp);
	temp = ClapTrap::getHitPoints();
	temp -= getAttackDamage();
	ClapTrap::setHitPoints(temp);
	return ;*/
}

void ClapTrap::takeDamage(unsigned int amount)
{
	determineMessage("takeDamage", amount, this->_name, NULL);
	ClapTrap::setHitPoints(ClapTrap::getHitPoints() - amount);
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	determineMessage("beRepaired", amount, this->_name, NULL);
	ClapTrap::setHitPoints(ClapTrap::getHitPoints() + amount);
	ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
	return ;
}

//debug functions
void ClapTrap::printStats(void)
{
	std::cout << "Name: " << ClapTrap::getName() << std::endl;
	std::cout << "Hitpoints: " << ClapTrap::getHitPoints() << std::endl;
	std::cout << "Energy Points: " << ClapTrap::getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << ClapTrap::getAttackDamage() << std::endl;
	return ;
}