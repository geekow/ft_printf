/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:42:23 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/26 19:39:53 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_data(char modifs[2], va_list args)
{
	if (modifs[0] == '\0')
		return ((long long)va_arg(args, int));
	else if (modifs[0] == 'h' && modifs[1] == 'h')
		return ((signed char)(va_arg(args, int)));
	else if (modifs[0] == 'h' && modifs[1] == '\0')
		return ((short)va_arg(args, int));
	else if (modifs[0] == 'l' && modifs[1] == '\0')
		return ((long)va_arg(args, long));
	else if (modifs[0] == 'l' && modifs[1] == 'l')
		return ((long long)va_arg(args, long long));
	else if (modifs[0] == 'j' && modifs[1] == '\0')
		return ((intmax_t)va_arg(args, intmax_t));
	else if (modifs[0] == 'z' && modifs[1] == '\0')
		return ((size_t)va_arg(args, size_t));
	else
		return ((int)va_arg(args, int));
}

int					parse_d(t_info *info, va_list args)
{
	long long	d;
	char		*str;
	int			size;
	int			special;

	d = get_data(info->lenght_modifs, args);
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
		if (d < 0 && info->precision >= 0)
			special++;
		if (size < info->min_size && !info->flag_minus)
			if (!addchar(' ', info->min_size - size - special))
				return (-1);
		if (info->flag_space && d >= 0 && !info->flag_plus)
			addchar(' ', 1);
		if (info->flag_plus && d >= 0)
			addchar('+', 1);
		if (info->precision >= 0)
		{
			if (d < 0)
			{
				addchar('-', 1);
				str++;
				addchar('0', size - ft_strlen(str));
			}
			else
				addchar('0', size - ft_strlen(str));
		}
		if (info->precision == 0 && d == 0 && info->min_size != -1)
			addchar(' ', 1);
		else if (info->precision != 0 || d != 0)
			addchars(str, ft_strlen(str));
		if (info->flag_minus && (size + special) < info->min_size)
			addchar(' ', info->min_size - (size + special));
		return (0);
	}
	else
	{
		if ((info->flag_plus || info->flag_space) && d >= 0)
			special++;
		if (info->min_size > (special + (int)ft_strlen(str))
				&& !info->flag_zero)
			addchar(' ', info->min_size - special - ft_strlen(str));
		else if (info->min_size > (special + (int)ft_strlen(str))
				&& info->flag_zero)
		{
			if (info->flag_plus && d >= 0)
				addchar('+', 1);
			else if (d < 0)
			{
				str++;
				special++;
				addchar('-', 1);
			}
			addchar('0', info->min_size - special - ft_strlen(str));
		}
		if (info->flag_space && d >= 0 && !info->flag_plus)
			addchar(' ', 1);
		if (info->flag_plus && d >= 0 && !info->flag_zero)
			addchar('+', 1);
		addchars(str, ft_strlen(str));
	}
	return (0);
}
