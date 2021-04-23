/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:17:24 by praclet           #+#    #+#             */
/*   Updated: 2021/04/23 13:41:10 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	switch (rand() % 3 + 1)
	{
		case 1:
			std::cout << "Generating A" << std::endl;
			return ((Base *)new A);
		case 2:
			std::cout << "Generating B" << std::endl;
			return ((Base *)new B);
		case 3:
		default:
			std::cout << "Generating C" << std::endl;
			return ((Base *)new C);
	}
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Detecting A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "Detecting B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "Detecting C" << std::endl;
		return ;
	}
	std::cout << "Unknown type" << std::endl;
}

void identify_from_reference( Base & p)
{
	try
	{
		A tmp(dynamic_cast<A &>(p));
		std::cout << "Detecting A" << std::endl;
	}
	catch (std::exception const & e)
	{
		try
		{
			B tmp(dynamic_cast<B &>(p));
			std::cout << "Detecting B" << std::endl;
		}
		catch (std::exception const & e)
		{
			try
			{
				C tmp(dynamic_cast<C &>(p));
				std::cout << "Detecting C" << std::endl;
			}
			catch (std::exception const & e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int main(void)
{
	srand(time(NULL));
	for (std::size_t i = 0;i < 10;i++)
	{
		if (i)
			std::cout << std::endl;
		Base * tmp = generate();
		identify_from_pointer(tmp);
		identify_from_reference(*tmp);
		delete tmp;
	}
	return (0);
}
