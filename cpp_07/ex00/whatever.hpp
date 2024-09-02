/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:05:41 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 17:05:41 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename Whatever>
void swap(Whatever &a, Whatever &b)
{
	Whatever tmp = a;
	a = b;
	b = tmp;
}

template <typename Whatever>
Whatever &min(Whatever &a, Whatever &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename Whatever>
Whatever &max(Whatever &a, Whatever &b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
