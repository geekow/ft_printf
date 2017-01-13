/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:04:04 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/13 04:01:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	last_w;
	size_t	i;
	t_info	*info;

	i = 0;
	last_w = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i > last_w && -1 == addchars(&format[last_w], i - last_w))
				return (-1);
			if (!(info = stock_info(format + ++i, &i)) ||
					-1 == parse_info(info, args))
				return (-1);
			last_w = i;
		}
		i++;
	}
	if (i > last_w && -1 == addchars(&format[last_w], i - last_w))
		return (-1);
	va_end(args);
	return (write_or_stock_all(NULL, 0, 1));
}
