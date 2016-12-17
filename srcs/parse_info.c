/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:38:13 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/08 21:47:40 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	parse_info(t_info *info)
{
	if (info->conv_char == 's')
		;
	else if (info->conv_char == 'S')
		;
	else if (info->conv_char == 'p')
		;
	else if (info->conv_char == 'D')
		;
	else if (info->conv_char == 'i' || info->conv_char == 'd')
		;
	else if (info->conv_char == 'o')
		;
	else if (info->conv_char == 'O')
		;
	else if (info->conv_char == 'u')
		;
	else if (info->conv_char == 'U')
		;
	else if (info->conv_char == 'X' || info->conv_char == 'x')
		;
	else if (info->conv_char == 'c')
		;
	else if (info->conv_char == 'C')
		;
	else if (info->conv_char == '%')
		return(write(1, &info->conv_char, 1));
	return (0);
}
