/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:31:25 by praclet           #+#    #+#             */
/*   Updated: 2021/04/23 09:40:26 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

struct Data
{
	char *	rndString1;
	int		rndInteger;
	char *	rndString2;
};

void * serialize(void);
Data * deserialize(void * raw);

#endif
