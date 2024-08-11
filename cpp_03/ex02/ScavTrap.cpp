/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:30:50 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/11 22:30:50 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copyCo) : ClapTrap(copyCo)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copyCo;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copyOp)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &copyOp)
	{
		this->setName(copyOp.getName());
		this->setHitPoints(copyOp.getHitPoints());
		this->setEnergyPoints(copyOp.getEnergyPoints());
		this->setAttackDamage(copyOp.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->getHitPoints() < 1)
	{
		this->determineMessage("dead", 0);
		return ;
	}
	if (this->getEnergyPoints() < 1)
	{
		this->determineMessage("tiredAttack", 0);
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing, " <<this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (this->getHitPoints() < 1)
	{
		this->determineMessage("dead", 0);
		return ;
	}
	if (this->getEnergyPoints() < 1)
	{
		std::cout << this->getName() << " is too tired to guard the gate!" << std::endl;
		return ;
	}
	std::cout <<  this->getName() << " has entered in Gate keeper mode!" << std::endl;
	return ;
}