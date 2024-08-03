/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:17:35 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/03 23:17:35 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		//constructors
		Zombie(void);
		Zombie(std::string name);

		//destructor
		~Zombie();

		//getters
		std::string	getName(void) const;

		//functions
		void		announce(void) const;
};

Zombie	*zombieHorde(int n; std::string name)

#endif