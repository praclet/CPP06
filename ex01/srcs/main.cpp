/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:25:48 by praclet           #+#    #+#             */
/*   Updated: 2021/04/26 12:12:46 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Data.hpp"

int main(void)
{
	srand (time(NULL));
	for (std::size_t i = 0;i < 10;i++)
	{
		Data *tmp=deserialize(serialize());

		std::cout << std::endl;
		std::cout << "str1: '" << tmp->rndString1 << "'" << std::endl;
		std::cout << " int: '" << tmp->rndInteger << "'" << std::endl;
		std::cout << "str2: '" << tmp->rndString2 << "'" << std::endl;
		std::cout << "*******************" << std::endl;
		delete [] tmp->rndString1;
		delete [] tmp->rndString2;
		delete tmp;
	}
	return (0);
}
