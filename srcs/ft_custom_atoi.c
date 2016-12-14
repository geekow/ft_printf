/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:56:54 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/14 17:24:50 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int         ft_custom_atoi(const char *nptr, int *size)
{
	int index;
	int condition;
	int result;

	index = 0;
	result = 0;
	while ('0' <= nptr[index] && nptr[index] <= '9')
		result = result * 10 + (nptr[index++] - '0');
	size += index;
	return (result);
}
