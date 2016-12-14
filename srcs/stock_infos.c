/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:07:29 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/14 21:52:42 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_infos	*create_infos_struct(void)
{
	t_infos		*infos;

	if (!(infos = (t_infos*)malloc(sizeof(t_infos))))
		return (NULL);
	infos->argx = -1;
	infos->flag_metadata = 0;
	infos->flag_zero = 0;
	infos->flag_minus = 0;
	infos->flag_plus = 0;
	infos->flag_space = 0;
	infos->minimum_size = -1;
	infos->precision = -1;
	infos->lenght_modifs[0] = '\0';
	infos->lenght_modifs[1] = '\0';
	infos->conv_char = '\0';
	return (infos);
}

static int	little_atoi(const char *nptr, size_t *size)
{
	int index;
	int result;

	index = 0;
	result = 0;
	while ('0' <= nptr[index] && nptr[index] <= '9')
		result = result * 10 + (nptr[index++] - '0');
	*size += index;
	return (result);
}

static int	stock_flag(char c, t_infos *infos)
{
	int	i;

	i = 0;
	if (c == '0' && ++i)
		infos->flag_zero = 1;
	else if (c == '#' && ++i)
		infos->flag_metadata = 1;
	else if (c == '-' && ++i)
		infos->flag_minus = 1;
	else if (c == '+' && ++i)
		infos->flag_plus = 1;
	else if (c == ' ' && ++i)
		infos->flag_space = 1;
	return (i);
}

t_infos		*stock_infos(char *str)
{
	t_infos		*infos;
	size_t		i;
	int			tmp;

	if (!(infos = create_infos_struct()))
		return (NULL);
	i = 0;
	while (str[i] && !infos->conv_char)
	{
		while (stock_flag(str[i], infos) || str[i] == '$')
			i++;
		if (ft_isdigit(str[i]))
		{
			tmp = little_atoi(&str[i], &i);
			if (str[i] == '$' && i++)
				infos->argx = tmp;
			else
				infos->minimum_size = tmp;
		}
		if (str[i] == '.' && ++i)
			infos->precision = little_atoi(&str[i], &i);
		if (ft_strchr("hljz", str[i]))
		{
			infos->lenght_modifs[0] = str[i++];
			if (str[i] == 'h' || str[i] == 'l')
				infos->lenght_modifs[1] = str[i++];
		}
		if (ft_strchr("sSpdDioOuUxXcC%", str[i]))
			infos->conv_char = str[i];
	}
	return (infos);
}
