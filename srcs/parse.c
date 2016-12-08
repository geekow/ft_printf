/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:38:13 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/08 21:47:40 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse(char c)
{
	if (str[i] == 's')
		return ();
	else if (str[i] == 'S')
		return ();
	else if (str[i] == 'p')
		return ();
	else if (str[i] == 'd')
		return ();
	else if (str[i] == 'D')
		return ();
	else if (str[i] == 'i')
		return ();
	else if (str[i] == 'o')
		return ();
	else if (str[i] == 'O')
		return ();
	else if (str[i] == 'u')
		return ();
	else if (str[i] == 'U')
		return ();
	else
		return (parse2(c));
}

int	parse2(char c)
{
	if (str[i] == 'x')
		return ();
	else if (str[i] == 'X')
		return ();
	else if (str[i] == 'c')
		return ();
	else if (str[i] == 'C')
		return ();
	else if (str[i] == '%')
		return (write(1, &c, 1));
	else
		return (-1);
}
