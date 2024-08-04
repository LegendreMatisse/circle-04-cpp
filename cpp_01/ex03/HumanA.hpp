/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:59:11 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 16:59:11 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		//constructor
		HumanA(std::string name, Weapon &weapon);

		//destructor
		~HumanA();

		//getter
		std::string getName() const;

		//function
		void attack() const;

	private:
		std::string _name;
		Weapon &_weapon;
};

#endif