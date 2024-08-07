/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:58:38 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/06 15:34:04 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	//human A
	Weapon weapon = Weapon("cannon loaded with grapeshot");
	HumanA bob("Jim Bob The Third", weapon);
	bob.attack();
	weapon.setType("deadly bio-engineered virus");
	bob.attack();

	//human B with weapon
	Weapon weapon = Weapon("briefcase nuke");
	HumanB jim("Jim Carlsson the Viscount of Montperllier");
	jim.setWeapon(weapon);
	jim.attack();
	weapon.setType("weaponized incompetence");
	jim.attack();

	//human B without weapon
	Weapon weapon = Weapon("sword of infinite power");
	HumanB steven("Steven Engelbert, the 2nd of his name, conqueror of the 7 seas, rightful heir to the throne of the 3rd kingdom of the 5th empire");
	steven.attack();
	weapon.setType("a stern look");
	steven.attack();
	return (0);
}