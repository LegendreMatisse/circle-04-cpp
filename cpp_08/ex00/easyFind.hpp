/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:22:37 by mlegendr          #+#    #+#             */
/*   Updated: 2025/01/15 18:32:04 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <exception>
# include <vector>
# include <list>

template <typename T>
typename T::const_iterator easyFind(const T &container, const int &value)
{
	if (container.empty())
		throw std::out_of_range("Container is empty");
		
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	
	if (it != container.end())
		return (it);
	
	throw std::runtime_error("Value not found.");
}

#endif