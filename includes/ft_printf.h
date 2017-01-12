/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:21:23 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/12 06:00:57 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_info
{
	int			argx;
	char		flag_metadata;
	char		flag_zero;
	char		flag_minus;
	char		flag_plus;
	char		flag_space;
	int			min_size;
	int			precision;
	char		lenght_modifs[2];
	char		conv_char;
}				t_info;

int				ft_printf(const char *format, ...);
int				parse_info(t_info *info, va_list args);
int				addchars(const char *str, int nb);
int				addchar(char c, int nb);
t_info			*stock_info(const char *str, size_t *index);

#endif
