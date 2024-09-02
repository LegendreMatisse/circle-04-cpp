/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:52:37 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 15:52:37 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "An instance of Serializer was created." << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "An instance of Serializer was destroyed." << std::endl;
}

uintptr_t Serializer::serialize(Data *data)
{
	return reinterpret_cast<uintptr_t>(data);
}

Data *Serializer::deserialize(uintptr_t in)
{
	return reinterpret_cast<Data *>(in);
}
