/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:49:53 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/13 15:39:37 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCat_HPP
# define WRONGCat_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		//constructor
		WrongCat(void);

		//copy constructor
		WrongCat(const WrongCat &copyCo);

		//assignment operator overload
		WrongCat &operator=(const WrongCat &copyOp);

		//destructor
		~WrongCat();

		//functions
		void	makeSound(void) const;
};

#endif