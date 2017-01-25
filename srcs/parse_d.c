/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:42:23 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/25 19:01:05 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_d(t_info *info, va_list args)
{
	int		d;
	char	*str;
	int		size;
	int		special;

	d = (int)va_arg(args, int);
	str = ft_itoa(d);
	special = 0;
	if (info->precision != -1 || info->flag_minus)
	{
		if ((int)ft_strlen(str) < info->precision)
			size = info->precision;
		else
			size = ft_strlen(str);
		if ((info->flag_plus || info->flag_space) && d >= 0)
			special++;
		if (size < info->min_size && !info->flag_minus)
			if (!addchar(' ', info->min_size - size - special))
				return (-1);
		if (info->flag_space && d >= 0 && !info->flag_plus)
			addchar(' ', 1);
		if (info->flag_plus && d >= 0)
			addchar('+', 1);
		if (info->precision >= 0)
			addchar('0', size - ft_strlen(str));
		if (info->precision == 0 && d == 0)
			addchar(' ', 1);
		else
			addchars(str, ft_strlen(str));
		if (info->flag_minus && (size + special) < info->min_size)
			addchar(' ', info->min_size - (size + special));
		return (0);
	}
	else
	{
		if ((info->flag_plus || info->flag_space) && d >= 0)
			special++;
		if (info->min_size > (special + (int)ft_strlen(str)) && !info->flag_zero)
			addchar(' ', info->min_size - special - ft_strlen(str));
		else if (info->min_size > (special + (int)ft_strlen(str)) && info->flag_zero)
			addchar('0', info->min_size - special - ft_strlen(str));
		if (info->flag_space && d >= 0 && !info->flag_plus)
			addchar(' ', 1);
		if (info->flag_plus && d >= 0)
			addchar('+', 1);
		addchars(str, ft_strlen(str));
	}
	return (0);
}
