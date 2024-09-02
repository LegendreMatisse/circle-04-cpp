/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:52:44 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 15:52:44 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	std::string	data;
};

class Serializer
{
	private:
		//constructor
		Serializer(void);
	public:
		//deconstructor
		~Serializer();

		//functions
		static uintptr_t	serialize(Data *data);
		static Data			*deserialize(uintptr_t in);
};


#endif
