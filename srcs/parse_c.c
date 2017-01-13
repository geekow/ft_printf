/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:41:12 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/13 06:10:18 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <wchar.h>

int		flag_zero(char flag_minus, char flag_zero, int min_size)
{
	char 	c;

	c = '0';
	if (!flag_minus && flag_zero && ((min_size - 1) > 0))
		return (addchar('0', min_size - 1));
	return (1);
}

int		flag_space(char flag_minus, char flag_zero, int min_size)
{
	char 	c;

	c = ' ';
	if (!flag_minus && !flag_zero && ((min_size - 1) > 0))
		return (addchar(' ', min_size - 1));
	return (1);
}

int		parse_c(t_info *info, va_list args)
{
	unsigned char	c;
	wint_t			wc;

	if (!flag_zero(info->flag_minus, info->flag_zero, info->min_size))
		return (-1);
	if (!flag_space(info->flag_minus, info->flag_zero, info->min_size))
		return (-1);
	if (info->lenght_modifs[0] == 'l')
	{
		wc = (wint_t)va_arg(args, wint_t);
		if (!addchar((char)wc, 1))
			return (-1);
	}
	else
	{
		c = (unsigned char)va_arg(args, int);
		if (!addchar(c, 1))
			return (-1);
	}
	if (info->flag_minus && (info->min_size > 1))
		if (!flag_space(0, 1, info->min_size))
			return (-1);
	return (1);
}
