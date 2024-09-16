/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:22:37 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/16 18:13:34 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <exception>
# include <vector>

template <typename T>
typename T::const_iterator easyfind(const T &container, const int &value)
{
	if (container.empty())
		throw std::out_of_range("Container is empty");
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)	
	{
		if (*it == value)
			return it;
	}
	throw std::runtime_error("Value not found.");
}

#endif