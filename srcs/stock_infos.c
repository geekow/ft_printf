/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:07:29 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/14 15:23:59 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_infos	*create_infos_struct(void)
{
	t_infos		*infos;
	
	if (!(infos = (t_infos*)malloc(sizeof(t_infos))))
		return (NULL);
	infos.argx = -1;
	infos.flag_metadata = 0;
	infos.flag_zero = 0;
	infos.flag_minus = 0;
	infos.flag_plus = 0;
	infos.flag_space = 0;
	infos.minimum_size = -1;
	infos.precision = -1;
	infos.lenght_modifs[0] = '\0';
	infos.lenght_modifs[1] = '\0';
	return (infos);
}

t_infos		stock_infos(char *str)
{
	t_infos		*infos;
	size_t		i;
	int			tmp;

	if (!(infos = create_infos_struct()))
		return (NULL);
	i = 0;
	while (str[i] && !ft_strchr("sSpdDioOuUxXcC%", str[i]))
	{
		if (ft_isdigit(str[i]))
		{
			if (str[i] == '0')
				infos.flag_zero = 1;
			tmp = ft_custom_atoi(&str[i], &i);
			if (str[i++] == '$')
			{
				infos.argx = tmp;
				infos.flag_zero = 0;
			}
			else
				infos.minimum_size = tmp;
		}
	}
}
