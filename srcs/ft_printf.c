/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:04:04 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/16 16:31:26 by jjacobi          ###   ########.fr       */
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
				result += write(1, &format[last_write], i - last_write);
			info = stock_info(format + ++i, &i);
			last_write = i;
			result += parse_info(info);
		}
		i++;
	}
	if (i > last_write)
	{
		write(1, &format[last_write], i - last_write);
		last_write = i;
	}
	va_end(args);
	return (result);
}
