/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 06:01:12 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/12 06:03:49 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		addchars(const char *str, int nb)
{
	return (write(1, str, nb));
}

int		addchar(char c, int nb)
{
	char            *str;
	int             i;

	i = 0;
	if (!(str = ft_strnew(nb)))
		return (-1);
	while (i++ < nb)
		str[i] = c;
	return (addchars(str, nb));
}
