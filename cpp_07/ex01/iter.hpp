/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:18:48 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 17:18:48 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename Iter>
void iter(Iter *arr, int len, void (*function)(const Iter &in))
{
	for (size_t i = 0; i < len; i++)
	{
		function(arr[i]);
	}
	
}

#endif
