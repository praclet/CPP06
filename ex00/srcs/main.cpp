/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:51:26 by praclet           #+#    #+#             */
/*   Updated: 2021/04/14 15:16:54 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc !=2)
	{
		std::cout << "USAGE: " << argv[0] << " value" << std::endl;
		return (1);
	}
	
	return (0);
}

