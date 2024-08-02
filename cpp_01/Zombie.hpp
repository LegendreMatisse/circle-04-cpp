/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:13:19 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/31 20:25:58 by mlegendr         ###   ########.fr       */
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

		//functions
		void		announce(void);
		Zombie		*newZombie(std::string name);
		void		randomChump(std::string name);
};

#endif