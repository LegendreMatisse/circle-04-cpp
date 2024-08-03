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

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(void);				//constructor
		Zombie(std::string &name);	//constructor
		~Zombie();					//destructor

		//getters
		std::string	getName(void) const;

		//setters
		void		setName(std::string name);

		//functions
		void		announce(void);
};

Zombie	*zombieHorde(int n, std::string name);

#endif