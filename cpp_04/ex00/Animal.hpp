/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:33:03 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 17:33:03 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		//constructor
		Animal(void);

		//parameterized constructor
		Animal(std::string const &type);

		//copy constructor
		Animal(const Animal &copyCo);

		//assignment operator overload
		Animal &operator=(const Animal &copyOp);

		//destructor
		virtual ~Animal();

		//functions
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif