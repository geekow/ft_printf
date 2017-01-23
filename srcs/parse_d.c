/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:42:23 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/23 21:27:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
int			parse_d(t_info *info, va_list args)
{
	int		d;
	int		len;
	char	*str;

	d = (int)va_arg(args, int);
	str = ft_itoa(d);
	len = ft_strlen(str);
	if (info->flag_space && d >= 0)
		addchar(' ', 1);

	if (info->min_size && info->precision > len)
		addchar(' ', info->min_size - info->precision - info->flag_plus - info->flag_space);
	else if ((info->min_size && (!info->flag_zero || info->precision != -1 )))
		addchar(' ', info->min_size - info->flag_plus - len - info->flag_space);
	if (d < 0)
	{
		addchar('-', 1);
		len--;
		str++;
	}
	if (info->flag_zero && info->precision == -1)
		addchar('0', info->min_size - len - 1);
	if (info->precision >= 0)
	{
		addchar('0', info->precision - len);
	}
	if (!addchars(str, len))
		return (-1);
	return (0);
}**/

int			parse_d(t_info *info, va_list args)
{
	int		d;
	int		tmp;
	char	*str;

	d = (int)va_arg(args, int);
	str = ft_itoa(d);
	tmp = 0;
	if (d > 0 && info->flag_space)
		tmp++;
	if (info->min_size > info->precision && !info->flag_zero)
	{
		if (info->precision > 0)
			addchar(' ', info->min_size - (info->precision - ft_strlen(str)) - tmp);
		else
			addchar(' ', info->min_size - ft_strlen(str) - tmp);
	}
	else if (info->min_size > info->precision && info->flag_zero)
	{
		addchar('0', info->min_size - ft_strlen(str) - tmp);
	}
	if (!addchars(str, ft_strlen(str)))
		return (-1);
	return (0);
}
