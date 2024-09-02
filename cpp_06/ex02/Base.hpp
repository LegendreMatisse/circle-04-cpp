/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:04:50 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 16:04:50 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	public:
		//destructor
		virtual ~Base() {}
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base *generate(void);
void identify(Base *pointer);
void identify(Base &reference);

#endif
