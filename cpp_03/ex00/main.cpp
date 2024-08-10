/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:27:40 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/10 17:27:40 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap1("Steven");
	ClapTrap clapTrap2("Walter");

	clapTrap1.attack(clapTrap2.getName());
	clapTrap1.setAttackDamage(2);
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	clapTrap2.printStats();
	clapTrap2.beRepaired(1);
	clapTrap2.printStats();
	return (0);
}