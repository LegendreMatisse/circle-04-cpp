/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:16:31 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 18:16:31 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		//constructor
		Dog(void);

		//parameterized constructor
		Dog(std::string const &type);

		//copy constructor
		Dog(const Dog &copyCo);

		//assignment operator overload
		Dog &operator=(const Dog &copyOp);

		//destructor
		~Dog();

		//functions
		void	makeSound(void) const;
};

#endif