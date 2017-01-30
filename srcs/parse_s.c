/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:43:06 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/30 17:54:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <wchar.h>

static int	flag_zero_spc(char flag_minus, char flag_zero, int min_size, int i)
{
	if (!flag_minus && flag_zero && ((min_size - i) > 0))
		if (-1 == addchar('0', min_size - i))
			return (-1);
	if (!flag_minus && !flag_zero && ((min_size - i) > 0))
		if (-1 == addchar(' ', min_size - i))
			return (-1);
	return (1);
}

static int	flag_space(char flag_minus, char flag_zero, int min_size, int i)
{
	if (!flag_minus && !flag_zero && ((min_size - i) > 0))
		return (addchar(' ', min_size - i));
	return (1);
}

static int	get_and_save(t_info *info, wchar_t **fws, char **fs, va_list args)
{
	int			i;
	wchar_t		*wstr;
	char		*str;

	i = 0;
	if (info->lenght_modifs[0] == 'l' && info->lenght_modifs[1] == '\0')
	{
		wstr = (wchar_t*)va_arg(args, wchar_t*);
		if (!wstr)
			i = 6;
		while (wstr && wstr[i])
			i = i + 1;
		*fws = wstr;
	}
	else
	{
		str = (char*)va_arg(args, char*);
		if (!str)
			str = ft_strdup("(null)");
		i = ft_strlen(str);
		*fs = str;
	}
	if (info->precision == -1 || info->precision > i)
		info->precision = i;
	return (info->precision);
}

int			parse_s(t_info *info, va_list args)
{
	char		*str;
	wchar_t		*wstr;
	int			i;

	i = get_and_save(info, &wstr, &str, args);
	if (!flag_zero_spc(info->flag_minus, info->flag_zero, info->min_size, i))
		return (-1);
	if (info->lenght_modifs[0] == 'l' && info->lenght_modifs[1] == '\0')
	{
		i = 0;
		if (!wstr && !addchars("(null)", info->precision))
			return (-1);
		while (wstr && wstr[i] && i < info->precision)
			if (!addunicode((int)wstr[i++]))
				return (-1);
	}
	else
	{
		if (!str || !addchars(str, info->precision))
			return (-1);
	}
	if (info->flag_minus && (info->min_size > i))
		if (!flag_space(0, 0, info->min_size, i))
			return (-1);
	return (1);
}
