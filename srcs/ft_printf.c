/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:04:04 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/29 21:33:51 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	valid_str(const char *str)
{
	static int	i = 1;

	if (i == 0)
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_strchr("sSpdDioOuUxXcC%", str[i]))
			return (1);
		i++;
	}
	i = 0;
	return (0);
}

static int	add_last_info(const char *format, size_t last_w, size_t i)
{
	if (valid_str("%s"))
	{
		if (-1 == addchars(&format[last_w], i - last_w))
			return (-1);
	}
	else
	{
		if (-1 == addchars(&format[last_w], ft_strchr(&format[last_w], '%')
					- &format[last_w]))
			return (-1);
	}
	return (1);
}

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
		if (format[i] == '%' && !valid_str(format + i))
		{
			info = stock_info(format + ++i, &i);
			addchars(&format[i], ft_strlen(&format[i]));
		}
		while (format[i] == '%' && valid_str(format + i))
		{
			if (i > last_w && -1 == addchars(&format[last_w], i - last_w))
				return (-1);
			if (!(info = stock_info(format + ++i, &i)) ||
					-1 == parse_info(info, args))
				return (-1);
			last_w = i;
		}
		i = (format[i]) ? i + 1 : i;
	}
	if (add_last_info(format, last_w, i) == -1)
		return (-1);
	va_end(args);
	return (write_or_stock_all(NULL, 0, 1));
}
