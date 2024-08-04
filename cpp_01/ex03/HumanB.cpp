/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:59:42 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 16:59:42 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanB created" << std::endl;
	return ;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destroyed" << std::endl;
	return ;
}

std::string HumanB::getName() const
{
	return this->_name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}

void HumanB::attack() const
{
	std::cout << HumanB::getName() << " attacks with his " << this->_weapon->getType() << std::endl;
	return ;
}