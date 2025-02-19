/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:13:51 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 15:13:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data();
	data->data = "Dit is een banaan.";
	std::cout << data->data << std::endl;
	uintptr_t steven = Serializer::serialize(data);
	std::cout << steven << std::endl;
	std::cout << Serializer::deserialize(steven)->data << std::endl;
	delete data;
	return 0;
}