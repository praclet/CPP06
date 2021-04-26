/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:31:30 by praclet           #+#    #+#             */
/*   Updated: 2021/04/26 12:11:24 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Data.hpp"

static void fillString(char * str, std::size_t size)
{
	if (!str || !size)
		return ;
	for (std::size_t i = 0;i < size - 1;i++)
		str[i] = rand() % (126 - 32 + 1) + 32;
	str[size - 1] = 0;
}

void * serialize(void)
{
	Data * res = new Data;
	std::size_t size;

	size = rand() % 25 + 10;
	res->rndString1 = new char[size];
	fillString(res->rndString1, size); 
	res->rndInteger = rand() - RAND_MAX / 2;
	size = rand() % 25 + 10;
	res->rndString2 = new char[size];
	fillString(res->rndString2, size); 
	std::cout << "str1: '" << res->rndString1 << "'" << std::endl;
	std::cout << " int: '" << res->rndInteger << "'" << std::endl;
	std::cout << "str2: '" << res->rndString2 << "'" << std::endl;
	return (reinterpret_cast<void *>(res));
}

Data * deserialize(void * raw)
{
	return (reinterpret_cast<Data *>(raw));
}
