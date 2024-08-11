/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:30:45 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/11 22:30:45 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default")
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTrap parameterized constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &copyCo) : ClapTrap(copyCo)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copyCo;
}

FragTrap &FragTrap::operator=(const FragTrap &copyOp)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &copyOp)
	{
		this->setName(copyOp.getName());
		this->setHitPoints(copyOp.getHitPoints());
		this->setEnergyPoints(copyOp.getEnergyPoints());
		this->setAttackDamage(copyOp.getAttackDamage());
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
void	FragTrap::highFivesGuys(void)
{
	std::cout << "Can I get a high five, guys?" << std::endl;
	std::cout << "Don't leave me hanging, guys!" << std::endl;
	std::cout << "Get fucked, assholes!" << std::endl;
}