/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:06:05 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/11 04:32:56 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INFO_H
# define PARSE_INFO_H

typedef	enum	e_parse
{
	s = 0,
	S = 1,
	p = 2,
	d = 3,
	D = 4,
	i = 5,
	o = 6,
	O = 7,
	u = 8,
	U = 9,
	x = 10,
	X = 11,
	c = 12,
	C = 13
}				t_parse;

int				parse_s(t_info *info, va_list args);
int				parse_maj_s(t_info *info, va_list args);
int				parse_p(t_info *info, va_list args);
int				parse_d(t_info *info, va_list args);
int				parse_maj_d(t_info *info, va_list args);
int				parse_i(t_info *info, va_list args);
int				parse_o(t_info *info, va_list args);
int				parse_maj_o(t_info *info, va_list args);
int				parse_u(t_info *info, va_list args);
int				parse_maj_u(t_info *info, va_list args);
int				parse_x(t_info *info, va_list args);
int				parse_maj_x(t_info *info, va_list args);
int				parse_c(t_info *info, va_list args);
int				parse_maj_c(t_info *info, va_list args);

#endif
