/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:58:49 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 16:58:49 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public:
		//constructor
		Weapon(std::string type);

		//destructor
		~Weapon(void);

		//getter (must return a const reference)
		const std::string &getType(void) const;

		//setter
		void setType(std::string type);

	private:
		std::string _type;
};

#endif