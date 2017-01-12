/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:04:04 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/12 07:05:08 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	size_t	last_write;
	size_t	i;
	int		verif;
	t_info	*info;

	i = 0;
	result = 0;
	last_write = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i > last_write)
			{
				verif = addchars(&format[last_write], i - last_write);
				if (verif == -1)
					return (-1);
				result += verif;
			}
			if (!(info = stock_info(format + ++i, &i)))
				return (-1);
			last_write = i;
			verif = parse_info(info, args);
			if (verif == -1)
				return (-1);
			else
				result += verif;
		}
		i++;
	}
	if (i > last_write)
	{
		verif = addchars(&format[last_write], i - last_write);
		if (verif == -1)
			return (-1);
		result += verif;
	}
	va_end(args);
	return (write_or_stock_all(NULL, 0, 1));
}
