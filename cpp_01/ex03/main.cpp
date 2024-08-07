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
	Weapon weapon1 = Weapon("cannon loaded with grapeshot");
	HumanA bob("Jim Bob The Third", weapon1);
	bob.attack();
	weapon1.setType("deadly bio-engineered virus");
	bob.attack();

	//human B with weapon
	Weapon weapon2 = Weapon("briefcase nuke");
	HumanB jim("Jim Carlsson the Viscount of Montperllier");
	jim.setWeapon(weapon2);
	jim.attack();
	weapon2.setType("weaponized incompetence");
	jim.attack();

	//human B without weapon
	Weapon weapon3 = Weapon("sword of infinite power");
	HumanB steven("Steven Engelbert, the 2nd of his name, conqueror of the 7 seas, rightful heir to the throne of the 3rd kingdom of the 5th empire");
	steven.attack();
	weapon3.setType("a stern look");
	steven.setWeapon(weapon3);
	steven.attack();

	//human B without weapon
	Weapon weapon4 = Weapon("sword of infinite power");
	HumanB karl("Steven Engelbert, the 2nd of his name, conqueror of the 7 seas, rightful heir to the throne of the 3rd kingdom of the 5th empire");
	karl.attack();
	karl.setWeapon(weapon4);
	karl.attack();
	return (0);
}