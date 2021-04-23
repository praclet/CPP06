/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:51:26 by praclet           #+#    #+#             */
/*   Updated: 2021/04/23 14:13:28 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <math.h>

void end(int rc)
{
	std::cout << "Invalid value" << std::endl;
	exit(rc);
}

void coutSetup(char const * type)
{
	std::cout << std::setw(13) << type << ": " << std::right;
}

void forScience(std::string const & arg)
{
	coutSetup("char");
	std::cout << "impossible" << std::endl;
	coutSetup("int");
	std::cout << "impossible" << std::endl;
	coutSetup("float");
	std::cout << arg << std::endl;
	coutSetup("double");
	std::cout << arg.substr(0, arg.length() - 1) << std::endl;
	exit(0);
}

int main(int argc, char* argv[])
{
	if (argc !=2)
	{
		std::cout << "USAGE: " << argv[0] << " value" << std::endl;
		return (1);
	}
	char * idx;
	std::string str(argv[1]);

	for (std::size_t i = 0;i < str.length();i++)
		str[i] = tolower(str[i]);

	if (str.length() <= 0)
		end(1);

	double value = std::strtod(argv[1], &idx);
	int prec = 1;

	if ((void*)idx == (void*)(argv[1] + str.length()))
	{
		if (isspace(argv[1][0]))
			end(1);
		std::size_t pointPos = str.find_first_of('.');
		if (pointPos != std::string::npos)
		{
			std::size_t lastDecPos = str.find_last_not_of('0');
			if (lastDecPos != std::string::npos && pointPos < lastDecPos)
				prec = lastDecPos - pointPos;
		}
	}
	else
	{
		if (str.length() == 1)
			value = argv[1][0];
		else
			if (str == "nanf" || str == "+nanf" || str == "-nanf")
				forScience("nanf");
			else
				if (str == "+inff" || str == "inff")
					forScience("inff");
				else
					if (str == "-inff")
						forScience("-inff");
					else
						end(1);
	}
	{
		coutSetup("char");
		if (isinf(value) || isnan(value) || value > CHAR_MAX || value < CHAR_MIN)
			std::cout << "impossible";
		else
		{
			if (!isprint(static_cast<char>(value)))
				std::cout << "Non displayble";
			else
				std::cout << "'" << static_cast<char>(value) << "'";
		}
		std::cout << std::endl;
	}
	{
		coutSetup("int");
		if (isinf(value) || isnan(value) || value > INT_MAX || value < INT_MIN)
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(value);
		std::cout << std::endl;
	}
	{
		coutSetup("float");
		if (!isinf(value) && !isnan(value) && value
				&& (value < -FLT_MAX || (value > -FLT_MIN 
				&& value < FLT_MIN) || value > FLT_MAX))
			std::cout << "impossible";
		else
			std::cout << std::setprecision(prec) << std::fixed << static_cast<float>(value) << 'f';
		std::cout << std::endl;
	}
	{
		coutSetup("double");
		std::cout << std::setprecision(prec) << std::fixed << value << std::endl;
	}
	return (0);
}
