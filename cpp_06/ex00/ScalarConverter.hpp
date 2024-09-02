/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:47 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 15:26:47 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <iomanip>

class ScalarConverter
{
	private:
		//constructor
		ScalarConverter(void);
	public:
		//destructor
		~ScalarConverter();

		//functions
		static void	convert(const std::string &in);
};

#endif