/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 06:01:12 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/13 05:12:53 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		print_all(t_list *list)
{
	int		result;
	size_t	i;

	result = 0;
	while (list)
	{
		i = write(1, list->content, list->content_size);
		if (i != list->content_size)
			return (-1);
		result += list->content_size;
		list = list->next;
	}
	return (result);
}

int		write_or_stock_all(const char *str, int nb, char print)
{
	static t_list	*begin = NULL;
	static t_list	*list = NULL;
	
	if (print == 1)
		return (print_all(begin));
	if (!begin)
	{
		if (!(begin = ft_lstnew((void*)str, nb)))
			return (-1);
		else
		{
			list = begin;
			return (1);
		}
	}
	if (!(list->next = ft_lstnew((void*)str, nb)))
			return (-1);
	list = list->next;
	return (1);
}

int		addchars(const char *str, int nb)
{
	if (write_or_stock_all(str, nb, 0) == -1)
		return (-1);
	else
		return (nb);
}

int		addchar(char c, int nb)
{
	char            *str;
	int             i;

	i = 0;
	if (!(str = ft_strnew(nb)))
		return (-1);
	while (i < nb)
		str[i++] = c;
	return (addchars(str, nb));
}
