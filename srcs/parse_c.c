/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:41:12 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/11 08:55:20 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <wchar.h>

int		flag_zero(char flag_minus, char flag_zero, int min_size)
{
	int		result;
	char 	c;

	result = 0;
	c = '0';
	if (!flag_minus && flag_zero && ((min_size - 1) > 0))
		while (min_size > 1 && min_size--)
			result += write(1, &c, 1);
	return (result);
}

int		flag_space(char flag_minus, char flag_zero, int min_size)
{
	int 	result;
	char 	c;

	result = 0;
	c = ' ';
	if (!flag_minus && !flag_zero && ((min_size - 1) > 0))
		while (min_size > 1 && min_size--)
			result += write(1, &c, 1);
	return (result);
}

int		parse_c(t_info *info, va_list args)
{
	int				result;
	unsigned char	c;
	wchar_t			wc;

	result = flag_zero(info->flag_minus, info->flag_zero, info->min_size);
	result = flag_space(info->flag_minus, info->flag_zero, info->min_size);
	if (info->lenght_modifs[0] == 'l')
	{
		wc = (wchar_t)va_arg(args, wint_t);
		result += write(1, &wc, 1);
	}
	else
	{
		c = (unsigned char)va_arg(args, int);
		result += write(1, &c, 1);
	}
	c = ' ';
	if (info->flag_minus && ((info->min_size - 1) > 0))
		while (info->min_size > 1 && info->min_size--)
			result += write(1, &c, 1);
	return (result);
}
