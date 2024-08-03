/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:17:17 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/03 23:17:17 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string &name) : _name(name)
{
	std::cout << Zombie::getName() << " raised from the dead..." << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::getName() << " was banished from this realm..." << std::endl;
	return ;
}

std::string	Zombie::getName(void) const
{
	return this->_name;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}