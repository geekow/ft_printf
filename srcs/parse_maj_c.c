/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maj_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:42:34 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/13 06:17:30 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse_info.h"

int	parse_maj_c(t_info *info, va_list args)
{
	info->lenght_modifs[0] = 'l';
	return (parse_c(info, args));
}
