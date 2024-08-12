/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:49:43 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 22:49:43 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		//constructor
		Cat(void);

		//copy constructor
		Cat(const Cat &copyCo);

		//assignment operator overload
		Cat &operator=(const Cat &copyOp);

		//destructor
		~Cat();

		//functions
		void	makeSound(void) const;
};

#endif