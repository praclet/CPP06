/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:56:15 by praclet           #+#    #+#             */
/*   Updated: 2021/04/23 11:15:36 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B()
{
}

B::B(B const & src)
{
	(void) src;
}

B::~B()
{
}

B & B::operator=(B const & src)
{
	(void) src;
	return (*this);
}