/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:04:04 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/08 21:53:31 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	read_flag(const char *str, va_list args, int *nb)
{
	int	i;

	i = 1;
	if (args)
		nb += 1;
	while (str[i] && !ft_strchr("sSpdDioOuUxXcC%", str[i]))
			i++;
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	size_t	i;

	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
		if (format[i] == '%')
			i += read_flag(format + i, args, &result);
		else
		{
			ft_putchar(format[i++]);
			result += 1;
		}
	va_end(args);
	return (result);
}
