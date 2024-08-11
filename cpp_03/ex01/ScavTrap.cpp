/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:29:58 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/11 17:29:58 by mlegendr         ###   ########.fr       */
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

ScavTrap::ScavTrap(const ScavTrap &copyCo)
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
	std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << ", is guarding the gate against the forces of evil." << std::endl;
}