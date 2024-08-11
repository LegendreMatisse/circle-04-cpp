/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:27:44 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/10 17:27:44 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap1("Steven");
	ClapTrap clapTrap1("Walter");

	scavTrap1.attack(clapTrap1.getName());
	scavTrap1.printStats();
	clapTrap1.takeDamage(scavTrap1.getAttackDamage());
	clapTrap1.printStats();
	clapTrap1.beRepaired(1);
	scavTrap1.printStats();
	scavTrap1.guardGate();

	scavTrap1.takeDamage(110);
	scavTrap1.printStats();

	return (0);
}